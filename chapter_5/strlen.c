#include <stdio.h>
#include <stdbool.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define MAXLEN 1000

int strlength(char *string) {
  int len;
  for (len = 0; *string != '\0'; string++) {
    len++;
  }

  return len;
}

int main(void)
{
  char input_string[MAXLEN];
  int i, c;
  int length = 0;
  
  i = 0;
  while ((c = getchar()) != EOF) {
    input_string[i] = c;
    i++;
  }
  input_string[i] = '\0';
  length = strlength(input_string);

  printf("\nString \"%s\" has length %d\n", input_string, length);

  return EXIT_SUCCESS;
}
