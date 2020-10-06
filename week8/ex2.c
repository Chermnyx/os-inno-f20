#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MB10 (10 * 1000 * 1000)

int main(int argc, char const* argv[]) {
  size_t i = 0;
  for (i = 0; i < 10; ++i) {
    void* mem = malloc(MB10);
    memset(mem, 0, MB10);
    sleep(1);
  }
  return 0;
}

/*
vmstat output:
[1] 304252
procs -----------memory---------- ---swap-- -----io---- -system-- ------cpu-----
 r  b   swpd   free   buff  cache   si   so    bi    bo   in   cs us sy id wa st
 6  0 687476 420628   2804 6684152    0    0    90   259  119  170 34 14 52  0  0
 6  0 692100 404920   2804 6699524    0    0     0     0 7983 17885 24 13 63  0  0
 7  0 692100 391256   2804 6702436    0    0     0     0 8023 18432 26 11 63  0  0
 4  0 692100 404320   2804 6679912    0    0     0     0 7758 17323 21 10 68  0  0
 3  0 692356 407344   2804 6672104    0    0     0     0 8437 17651 29 10 61  0  0
 4  0 692356 392484   2804 6670920    0    0     0     0 7987 18581 26 12 63  0  0
 2  0 692612 380576   2804 6679444    0    0     0 12716 8195 18536 22 12 66  0  0
 3  0 692612 375940   2804 6675756    0    0     0    84 8028 17874 27 11 62  0  0
 3  0 692612 365884   2804 6675412    0    0     0   844 7934 18431 25 12 63  0  0
 7  0 692612 358332   2804 6675380    0    0    32    40 7865 17241 24 10 66  0  0
 4  0 693124 348000   2804 6673728    0    0     0     0 7910 16891 29 11 60  0  0
[1]  + 304252 done       ./ex2

Nothing is swapped or loaded from the swap (si = so = 0) because there is enough memory in my system.
Each second the amount of free memory decreases as (./ex2) allocates it (except for the cases when other processes free the memory)


ex2 takes more memory (but still can't compete in memory eating with zoom) so it becomes higher in `top -d1` command (the value of RES and %MEM also increases).
*/
