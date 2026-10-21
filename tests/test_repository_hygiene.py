"""Keep private experiment directories out without rejecting retained C variants."""
from pathlib import Path
from types import SimpleNamespace
import tempfile
import unittest
from unittest.mock import patch

import check_repository


class ScratchHygieneTests(unittest.TestCase):
    def test_empty_source_barriers_are_rejected(self):
        for text in ("do { } while (0);", "do { /* schedule */ ; }\nwhile (0U);"):
            errors = []
            check_repository.check_empty_barriers(text, "src/example.c", errors)
            self.assertEqual(len(errors), 1)

    def test_nonempty_macro_blocks_and_literal_mentions_are_allowed(self):
        for text in ("do { high = value.hi; low = value.lo; } while (0);",
                     '/* do { } while (0) */ const char *s = "do {} while (0)";',
                     '// do {} while (0)\nreturn 0;'):
            errors = []
            check_repository.check_empty_barriers(text, "src/example.c", errors)
            self.assertEqual(errors, [])

    def check_paths(self, paths):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            for path in paths:
                target = root / path
                target.parent.mkdir(parents=True, exist_ok=True)
                target.write_text("/* authored source fixture */\n", encoding="utf-8")
            with patch.object(check_repository, "ROOT", root), patch(
                "subprocess.run", return_value=SimpleNamespace(stdout="\n".join(paths))
            ):
                errors = []
                check_repository.check_hygiene(errors)
                return errors

    def test_tracked_scratch_is_rejected_even_if_gitignore_would_hide_it(self):
        paths = ["scratch/check-many.sh", "nonmatching/levels/_scratch/screen.txt",
                 "nonmatching/levels/_scratch2/var/body.c"]
        errors = self.check_paths(paths)
        self.assertEqual(len(errors), len(paths))
        for path in paths:
            self.assertTrue(any(path in error and "stay local" in error for error in errors))

    def test_catalogue_named_retained_variants_are_allowed(self):
        self.assertEqual(self.check_paths([
            "nonmatching/levels/func_L00_002D3FB8.c",
            "nonmatching/levels/alternatives/func_L00_002D3FB8-form-01.c",
        ]), [])
