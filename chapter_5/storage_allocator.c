#include <stdio.h>
#include <stdbool.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define ALLOCSIZE 10000 /*available space */
#define OUT_OF_BOUNDS 0 /*C guarantees that 0 is never a valid address for data (in stdio you have NULL available) */

static char allocbuf[ALLOCSIZE]; /*allocation buffer*/ 
static char *allocp = allocbuf; /*next free position*/

char *alloc(int n) {
  /* function that returns a pointer to n characters
   */
  char remaining = allocbuf + ALLOCSIZE - allocp;

  if (remaining >= n) {
    /*it fits! */
    allocp += n; /*shift the pointer to its new position*/
    return allocp - n; /*return the old position*/
  } else {
    /*not enough room! */
    return OUT_OF_BOUNDS;
  }
}

void afree(char *ptr) {
  if (ptr >= allocbuf && ptr < allocbuf + ALLOCSIZE) {
    allocp = ptr;
  }
}

int main(void)
{
  return EXIT_SUCCESS;
}
