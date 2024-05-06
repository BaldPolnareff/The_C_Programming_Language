#include <stdio.h>

#define EXIT_SUCCESS 0;
#define EXIT_FAILURE 1;

#define MAXLINE 1000 /* maximum input line length */

int get_line(char string[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && c != '\n' && (c = getchar()) != EOF ; ++i) {
    string[i] = c;
    if (c == '\n') {
      string[i] = c;
      ++i;
    }
    string[i] = '\0';
  }
  return i;
}

void copy(char to[], char from[]) {
  int i;
  i = 0;

  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}

int main(void)
{
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;

  while ((len = get_line(line, MAXLINE)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }
  if (max > 0) {
    printf("%s", longest);
  }
  return EXIT_SUCCESS;
}
