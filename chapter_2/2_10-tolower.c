#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAXLEN 1000
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

char lower(char c) {
  c = isupper(c) ? c + 32 : c;
  return c;
}


int main(void)
{
  int c, i;
  i = 0;

  char string[MAXLEN];

  while ((c = getchar()) != EOF) {
    if (i > MAXLEN) {
      printf("Length limit exceeded.");
      return EXIT_FAILURE;
    }
    string[i] = lower(c);
    i++;
  }

  puts(string);
  return EXIT_SUCCESS;
}
