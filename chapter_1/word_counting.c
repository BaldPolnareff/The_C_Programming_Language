#include <stdio.h>

#define IN 1 /* INSIDE a word */
#define OUT 0 /* OUTSIDE a word */

int main(void)
{
  int c, nl, nw, nc, state;

  state = OUT;
  nw = nl = nc = 0;

  while ((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n') {
      ++nl;
    }
    if (c == '\n' || c == ' ' || c == '\t') {
      state = OUT;
    } else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }

  printf("%d lines, %d words, %d characters", nl, nw, nc);

  return 0;
}
