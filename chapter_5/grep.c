#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAXLINE 10000

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1 

/*print lines that match pattern of first cli argument */
int get_line(char *s, int limit) {
  char c;
  char *start = s;

  while ((c = getchar()) != EOF && --limit > 0 && c != '\n') {
    *s++ = c;
  }
  if (c == '\n') {
    *s++ = c;
  }
  *s = '\0';
  return s - start;
}

int main(int argc, char *argv[])
{
  char line[MAXLINE];

  if (argc != 2) {
    puts("Usage: grep <pattern>");
    return EXIT_FAILURE;
  } else {
    while (get_line(line, MAXLINE) > 0) {
      if (strstr(line, argv[1]) != NULL) {
        printf("%s", line);
      }
    }
  }
  return EXIT_SUCCESS;
}
