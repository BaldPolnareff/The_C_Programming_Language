#include <stdio.h>
#include <stdbool.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define MAXLEN 1000
#define PRINT_THRESHOLD 80

_Bool is_newline(char c) {
  return c == '\n';
}

int main(void)
{
  int i, c;
  i = 0;

  char string[MAXLEN];

  while ((c = getchar()) != EOF) {
    string[i] = c;
    i++;
    if (is_newline(c)) {
      if (i > PRINT_THRESHOLD) {
        string[i] = '\n';
        printf("%s\n", string);
      }
      i = 0;
    }
  }
  return EXIT_SUCCESS;
}
