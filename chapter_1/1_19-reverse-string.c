#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define MAXLEN 1000

void reverse_string(char *string) {
  if (string == NULL) {
    fprintf(stderr, "NULL pointer passed as string!\n");
    return;
  }
  int len = strlen(string);
  int left = 0;
  int right = len - 1;

  while (left < right) {
    char tmp = string[left];
    string[left] = string[right];
    string[right] = tmp;
    left++;
    right--;
  }
}
_Bool is_newline(char c) {
  return c == '\n';
}

int main(void)
{
  int c;
  int i = 0;
  char string[MAXLEN];

  while ((c = getchar()) != EOF) {
    if (is_newline(c)) {
      string[i] = '\0';
      reverse_string(string);
      printf("%s\n", string);
      i = 0;
    }
    string[i] = c;
    i++;
  }
  return EXIT_SUCCESS;
}
