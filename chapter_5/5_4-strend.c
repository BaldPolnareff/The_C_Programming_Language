#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define MAXLEN 10000

static char appendix[] = "PORCAMADONNA";

bool strend(char *string, char *appendix) {
  int string_length = strlen(string);
  int appendix_length = strlen(appendix);
  char *end_of_string = string + string_length;
  char *end_of_appendix = appendix + appendix_length;

  while (end_of_appendix >= appendix) {
    if (*end_of_appendix-- != *end_of_string--) {
      return false;
    }
  }
  return true;
}

int main(void)
{
  char input_string[MAXLEN];
  int i = 0;
  char c;

  while ((c = getchar()) != EOF) {
    input_string[i++] = c;
  }
  input_string[i] = '\0';

  printf("\nAppendix to be found in input string: '%s'\n", appendix);
  if (strend(input_string, appendix)) {
    puts("TRUE");
    return EXIT_SUCCESS;
  }
  puts("FALSE");
  return EXIT_FAILURE;
}
