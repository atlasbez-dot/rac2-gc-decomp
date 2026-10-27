/* Fixture for tests/test_trap_redundant_barrier.py: authored, not game code. */
extern int ticks;
extern void every_third(void);
extern void every_fifth(void);
extern void prepare(void);

/* The branch over the first call still holds `ticks', read above the division guard;
   the call in front keeps the prologue's stores out of the way. */
void guarded(void)
{
    prepare();
    if (ticks % 3 == 0)
        every_third();
    if (ticks % 5 == 0)
        every_fifth();
}

/* Control: no division, so no guard; the reload is redundant on the branch's path and is
   dropped. */
void plain(void)
{
    prepare();
    if (ticks == 3)
        every_third();
    if (ticks == 5)
        every_fifth();
}
