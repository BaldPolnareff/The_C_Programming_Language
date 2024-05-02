#include <stdio.h>
#include <stdbool.h>

#define EXIT_SUCCESS 0

_Bool detect_white_space(int c) {
  if (c == '\n' || c == '\t' || c == ' ') {
    return true;
  } 
  return false;
}

int main(void)
{
  int c;
  int counter;

  counter = 0;

  while ((c = getchar()) != EOF) {
    if (detect_white_space(c) == true) {
      printf("\n\t\t\t");
      for (int i = 0; i < counter; i++) {
        printf("__");
      }
      printf("\n");
      counter = 0;
      
    } else {
      ++counter;
      printf("%c", c);
    }
  }
  return EXIT_SUCCESS;
}
