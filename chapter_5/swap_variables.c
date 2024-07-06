#include <stdbool.h>
#include <stdio.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

void swap(int *a, int *b) {
  char tmp = *a;

  *a = *b;
  *b = tmp;
}

int main(void)
{
  int x = 69;
  int y = 420;
  puts("Pre-swapping:");
  printf("%d __ %d\n\n", x, y);

  swap(&x, &y);

  puts("Post-swapping:");
  printf("%d __ %d\n", x, y);

  return EXIT_SUCCESS;
}
