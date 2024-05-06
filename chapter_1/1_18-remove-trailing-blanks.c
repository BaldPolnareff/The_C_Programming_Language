#include <stdio.h>
#include <stdbool.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define MAXLEN 1000

_Bool is_newline(char c) {
  return c == '\n';
}

_Bool is_blank(char c) {
  return (c == '\t' || c == ' ' || is_newline(c));
}

void trim(char *string, int len) {
  int i;
  if (len == 0) {
    return;
  }
  for (i = len - 1; i >= 0; i--) {
    if (!is_blank(string[i])) {
      string[i + 1] = '\0'; 
      break;
    }
  }
}

int main(void)
{
  int c, i;
  i = 0;
  int len = 0;

  char string[MAXLEN];

  /* store each line, trim it, print it and reset index to overwrite */
  while ((c = getchar()) != EOF) {
    len = i;
    if (is_newline(c)) {
      trim(string, len);
      printf("%s\n", string);
      i = 0;
    }
    string[i] = c;
    i++;
  }

   return EXIT_SUCCESS;
}
