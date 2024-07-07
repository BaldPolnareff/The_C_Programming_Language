#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAXLEN 10000

int get_line(char *s, int limit) {
  char *start = s;
  char c;
  int length = 0;

  while ((c = getchar()) != EOF && --limit > 0 && c != '\n') {
    *s++ = c;
  }
  if (c == '\n') {
    *s++ = c;
  }
  *s = '\0';
  length = s - start;
  return length;
}

int main(int argc, char *argv[])
{
  char line[MAXLEN];
  long int lineno = 0;
  int c;
  bool except = false, number = false;
  int found = 0;

  while (--argc > 0 && (*++argv)[0] == '-') {
    while (c = *++argv[0]) {
      switch (c) {
        case 'x':
          except = true;
          break;
        case 'n':
          number = true;
          break;
        default:
          printf("grep: illegal option '%c'\n", c);
          argc = 0;
          found = -1;
          break;
      }
    }
  }
  if (argc != 1) {
    puts("Usage: grep -x -n <pattern>");
  } else {
    while (get_line(line, MAXLEN ) > 0) {
      lineno++;
      if ((strstr(line, *argv) != NULL) != except) {
        if (number) {
          printf("[%ld]: ", lineno);
        }
        printf("%s", line);
        found++;
      }
    }
  }
  return found;
}
