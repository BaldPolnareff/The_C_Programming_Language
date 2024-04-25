#include <stdio.h>

int main(void)
{
  int result;
  result = getchar() != EOF;
  printf("Result of 'getchar() != EOF' is: %d\n", result);
  return 0;
}
