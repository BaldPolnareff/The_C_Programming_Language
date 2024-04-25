#include <stdio.h>


int main(void) {
  
  long int count_blank;
  long int count_tab;
  long int count_newline;
  int c;

  count_blank = 0;
  count_tab = 0;
  count_newline = 0;

  while ((c = getchar()) != EOF) {
    if (c == " " ) {
      ++count_blank;
    } else if (c == "\t") {
      ++count_tab;
    } else if (c == "\n") {
      ++count_newline;
    }
  }

  printf("You input %ld blanks, %ld tabs and %ld newlines", count_blank, count_tab, count_newline);

  return 0;
}
