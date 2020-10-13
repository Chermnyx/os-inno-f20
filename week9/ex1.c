#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

size_t n;

typedef struct {
  size_t page_n;
  size_t bits;
} page_t;

int main(int argc, char const* argv[]) {
  printf("NPFrames = ");
  scanf("%zu", &n);

  size_t total_pages;
  printf("NTotal = ");
  scanf("%zu", &total_pages);

  size_t references;
  printf("NRefs = ");
  scanf("%zu", &references);

  size_t hits = 0;
  size_t misses = 0;
  size_t i = 0;

  page_t* table = (page_t*)calloc(
      total_pages,
      sizeof(page_t));  // [page_N (virt addr page number)] -> (page_t | NULL)

  for (i = 0; i < total_pages; ++i) {
    (table + i)->page_n = i;  // WARN: page with i=0 does not exist
  }

  page_t* mem =
      (page_t*)calloc(n, sizeof(page_t));  // [pageFrameN] -> (page_t | NULL)

  for (i = 0; i < references; ++i) {
    size_t accessed_page;
    scanf("%zu", &accessed_page);

    size_t j = 0;
    int hit = 0;
    for (j = 0; j < n; ++j) {
      page_t* page = mem + j;
      if (page->page_n == accessed_page) {
        hit = 1;
        break;
      }
    }

    hits += hit;

    if (!hit) {
      misses++;
      size_t to_drop_n = 0;
      for (j = 1; j < n; ++j) {
        if ((mem + j)->page_n == 0) {
          to_drop_n = j;
          break;
        }
        if ((mem + j)->bits < (mem + to_drop_n)->bits) {
          to_drop_n = j;
        }
      }

      *(mem + to_drop_n) = *(table + accessed_page);
    }

    for (j = 0; j < total_pages; ++j) {
      (table + j)->bits = (j == accessed_page) | ((table + j)->bits >> 1);
    }
  }

  printf("hits: %zu, misses: %zu, ratio: %lf\n", hits, misses,
         (double)hits / misses);
  return 0;
}
