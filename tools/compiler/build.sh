#!/bin/bash
# The game's C compiler: GNU EE 2.9-ee-991111b (cpp, cc1, as) rebuilt from its public source.
#
#   tools/compiler/build.sh [OUT]        # default build/compiler/tools
#
# Run it on 32-bit-capable x86-64 Linux (gcc -m32), e.g. in the rac2-linux container
# (docs/BUILDING.md). It downloads the two inputs to build/downloads/ and checks them,
# applies the patches in tools/compiler/patches/ (Lombyte's sce-991111b stack, MIT, with its
# retired 0034 and its earlier 0020), the 0057/0058 compiler profiles, the 0059 assembler option and the
# transformers in tools/compiler/transformers/,
# refuses to build unless the patched sources hash as listed below, and builds.
#
# The binaries' hashes depend on the build host; the sources' do not. A compiler from these
# sources compiles every matched function in src/ to the retail bytes (tools/build.py).
set -euo pipefail
ROOT=$(cd "$(dirname "$0")/../.." && pwd)
HERE=$ROOT/tools/compiler
OUT=$(mkdir -p "${1:-$ROOT/build/compiler/tools}" && cd "${1:-$ROOT/build/compiler/tools}" && pwd)
DL=$ROOT/build/downloads
W=${WORK:-/tmp/rac2-compiler}
J=$(nproc)
mkdir -p "$DL" "$W"

fetch() {  # fetch FILE SHA256 URL
  [ -f "$DL/$1" ] || curl -fL --retry 3 -o "$DL/$1" "$3"
  echo "$2  $DL/$1" | sha256sum --check --quiet
}
fetch gnu-ee-binutils-gcc-1.1.tar.gz 1f518043e252d6eda726386971d52eda26541ab936ea73a9783d73712b595f92 \
  "https://web.archive.org/web/20060518234647id_/http://ps2dev.sourceforge.net:80/downloads/ee/gnu-ee-binutils-gcc-1.1.tar.gz"
fetch bison-1.28.tar.gz c5d3e4858e17cb440cee9de7837f07277bcfb03507e9d2f0c506cab5efe36c3a \
  https://ftp.gnu.org/gnu/bison/bison-1.28.tar.gz

# The source tree.
rm -rf "$W/src" && tar xzf "$DL/gnu-ee-binutils-gcc-1.1.tar.gz" -C "$W" && mv "$W/gnu-ee-binutils-gcc" "$W/src"
cd "$W/src"
export GIT_CEILING_DIRECTORIES=$W
for p in 0000 0001 0015 0016 0019 0020 0021 0022 0025 0026 0027 0028 0029 0030 0031 0032 0033 0034 \
         0036 0037 0044 0045 0046 0047 0048 0049 0050 0051 0052 0053 0054 0055 0056 0057; do
  git apply --whitespace=nowarn "$HERE"/patches/$p-*.patch
done
patch -R -p1 -s < "$HERE"/patches/0001-r5900-quad-saves.patch   # the retail saves in 8-byte slots
git apply --whitespace=nowarn "$HERE"/patches/0058-*.patch       # the opt-in -mastra-quad-saves switch
git apply --whitespace=nowarn "$HERE"/patches/0059-*.patch       # per-object sign-bit seed selection
T=$HERE/transformers
python3 $T/neutralise_timode_anchor.py gcc/config/mips/mips.c
python3 $T/enable_loop_padding.py gcc/config/mips/mips.h
python3 $T/count_trap_length.py gcc/config/mips/mips.c
python3 $T/ascending_save_order.py gcc/config/mips/mips.c
python3 $T/reorder_save_blocks.py gcc/config/mips/mips.c
python3 $T/u4_mtc1_helper.py gas/config/tc-mips.c
python3 $T/restrict_mtc1_exemption.py gas/config/tc-mips.c
python3 $T/fold_zero_ti_store.py gcc
python3 $T/fold_zero_ti_return_value.py gcc
python3 $T/u3_frame_order_on.py gcc/config/mips/mips.c
python3 $T/disable_frame_order_default.py gcc/config/mips/mips.c
python3 $T/pad_div_erratum_nops.py gas/config/tc-mips.c
python3 $T/neutralise_div_dslot.py gcc
python3 $T/pad_div_erratum_branch.py gas/config/tc-mips.c >/dev/null
python3 $T/r5900_mfc1_interlock.py gas/config/tc-mips.c
python3 $T/tidy_condjump_fallthru.py gcc/flow.c
python3 $T/zero_ti_store_barrier.py gcc/haifa-sched.c
python3 $T/gcse_unsplit_edges.py gcc/gcse.c
python3 $T/keep_block_order.py gcc/flow.c
python3 $T/qcopy_pattern.py gcc
python3 $T/hazard_labels.py .
python3 $T/qcopy_barrier.py gcc
python3 $T/no_annulled_wide_stores.py gcc/reorg.c
python3 $T/zero_ti_por.py gcc
sha256sum --check --quiet <<'SUMS'
78eba27106cd3a183125df8380d4ee19e38de6506d8fd416b34fb3460d142704  gcc/config/mips/mips.c
d43a3f2274e1ca640c1f877b9aa2a82b2e337298d7d0ebf7e5498fe91b3523f4  gcc/config/mips/mips.h
790a54f4772853284ab43a7afc9f592913da8f012b46d43abf5f2a3660467eef  gcc/config/mips/mips.md
a12ae81a7e222259d50148ae8e27592cd88ba32715077172a5984804245ea840  gcc/toplev.c
3098888cc26ac83c936a8d505662b6ba1aa9039811e89c534f4ea8f1a851e7d6  gcc/haifa-sched.c
57ed3b11b677ad163a189adf26b0c32b1c856123403de158a08859644bc1b637  gcc/reorg.c
f89153488b2d94ae782195c577a4f7e15fda0b9455852cc25f70d7f759912a5d  gcc/flags.h
02f386e5e25a90684b912fbb11ce1a634a40a80dbefc93b20b0546259e1f8bfc  gcc/gcse.c
ba947e44256e3d5144e353a4976aac931a4941acc8dcb1dc0fda99fa8b7b504a  gcc/flow.c
89227b294163fdd860f559d67c1e4bce6ea2b3b1c86f16a3812401f7b187e1ff  gas/config/tc-mips.c
SUMS

# bison 1.28: the 1999 grammars need its skeleton.
if [ ! -x "$W/bison/bin/bison" ]; then
  rm -rf "$W/bison-1.28" && tar xzf "$DL/bison-1.28.tar.gz" -C "$W"
  (cd "$W/bison-1.28" && CC="gcc -std=gnu89" CFLAGS="-O2 -fcommon" ./configure --prefix="$W/bison" \
     && make -j$J && make install) > "$W/bison.log" 2>&1
fi
export BISON_SIMPLE=$W/bison/share/bison.simple BISON_HAIRY=$W/bison/share/bison.hairy

F="-O2 -fno-strict-aliasing -fcommon -std=gnu89 -D_GNU_SOURCE"
rm -rf "$W/build" && mkdir "$W/build" && cd "$W/build"
printf 'obstack.o gcc.o mkstemp.o: override CFLAGS = -g\n' > host-flags.mk
export CC="gcc -m32" CFLAGS="$F"
{
  bash "$W/src/configure" --target=mips64r5900-sf-elf --host=i686-linux-gnu --build=i686-linux-gnu \
       --disable-nls --enable-languages=c --without-headers --prefix="$W/install"
  make -j$J all-libiberty
  # The 1999 Makefile lacks flow.o -> insn-flags.h: generate the headers first.
  make -C gcc -f Makefile -f "$W/build/host-flags.mk" LANGUAGES=c "CC=gcc -m32" "CFLAGS=$F" \
       BISON="$W/bison/bin/bison" insn-flags.h insn-codes.h insn-config.h
  make -C gcc -f Makefile -f "$W/build/host-flags.mk" -j$J LANGUAGES=c "CC=gcc -m32" "CFLAGS=$F" \
       BISON="$W/bison/bin/bison" cc1 cpp xgcc
  make -j$J all-gas
} > "$W/build.log" 2>&1 || { tail -30 "$W/build.log"; exit 1; }
cp gcc/cc1 gcc/cpp "$OUT/" && cp gas/as-new "$OUT/as"
# the compiler's own headers (stdarg.h and the va-*.h it includes), as the
# SDK recipe installs them: an authored unit that includes <stdarg.h>
# (a varargs body) needs them on the preprocessor's path.
mkdir -p "$OUT/include" && cp "$W/src/gcc/ginclude/"*.h "$OUT/include/"
RAC2_COMPILER_ROOT="$OUT" python3 "$ROOT/tests/test_zero_ti_store.py"
RAC2_COMPILER_ROOT="$OUT" python3 "$ROOT/tests/test_gcse_unsplit_edges.py"
RAC2_COMPILER_ROOT="$OUT" python3 "$ROOT/tests/test_keep_block_order.py"
RAC2_COMPILER_ROOT="$OUT" python3 "$ROOT/tests/test_qcopy.py"
RAC2_COMPILER_ROOT="$OUT" python3 "$ROOT/tests/test_qcopy_barrier.py"
RAC2_COMPILER_ROOT="$OUT" python3 "$ROOT/tests/test_no_annulled_wide_stores.py"
RAC2_COMPILER_ROOT="$OUT" python3 "$ROOT/tests/test_zero_ti_por.py"
python3 "$ROOT/tests/test_qcopy_rtl.py"
RAC2_COMPILER_ROOT="$OUT" python3 "$ROOT/tests/test_dli_masks.py"
RAC2_COMPILER_ROOT="$OUT" python3 "$ROOT/tests/test_hazard_labels.py"
echo "compiler in $OUT"
