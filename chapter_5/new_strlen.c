#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int string_len(char *s) {
  char *ptr;
  for (ptr = s; *ptr != '\0'; ptr++) {
    continue;
  }
  return ptr - s;
}

int main(void)
{
  char my_string[1000];
  char c;
  int i = 0;

  while ((c = getchar() != EOF)) {
    my_string[i] = c;
    i++;
  }
  my_string[i] = '\0';

  int test_length = strlen(my_string);
  int calc_length = string_len(my_string);
  
  printf("\n");
  puts("Testing own implementation of strlen:");
  printf("Real string length: %d\tOwn implementation: %d\n", test_length, calc_length);

  return EXIT_SUCCESS;
}
