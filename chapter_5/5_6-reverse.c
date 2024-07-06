#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 10000

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1 

void reverse(char *s) {
  int len = strlen(s);
  char *left = s;
  char *right = s + len - 1;

  char tmp;

  while (left <= right) {
    tmp = *left;
    *left++ = *right;
    *right-- = tmp;
  }
}

int main(void)
{
  char input_string[MAXLEN];
  char c;
  char *ptr = input_string;
  
  while ((c = getchar()) != EOF) {
    *ptr++ = c;
  }
  *ptr= '\0';
  
  reverse(input_string);
  printf("\n%s\n", input_string);
  return EXIT_SUCCESS;
}
