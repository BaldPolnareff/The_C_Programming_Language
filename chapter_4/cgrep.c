#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAXLEN 10000
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

char needle[] = "orcoddio";

int get_line(char *string, int limit) {
  int c, i;
  i = 0;

  while (limit > 0) {
    c = getchar();
    if (c == EOF || c == '\n') {
      break;
    }
    string[i] = c;
    i++;
    limit--;
  }
  if (c == '\n') {
    string[i] = c;
    i++;
  }

  string[i] = '\0';
  return i;
}

int strindex(char *haystack, char *needle) {
  int needle_len = strlen(needle);
  int haystack_len = strlen(haystack);
  int i, j;

  if (needle_len == 0) {
    return 0;
  }

  for (i = 0; i < haystack_len - needle_len; i++) {
    for (j = 0; j < needle_len; j++) {
      if (haystack[i + j] != needle[j]) {
        break;
      }
      if (j == needle_len - 1) {
        return i;
      }
    }
  }
  return -1;
}

void highlight_substr(char *haystack, char *needle, char open_delim, char close_delim) {
  if (strindex(haystack, needle) == -1) {
    return;
  }

  int start = strindex(haystack, needle);
  int haystack_len = strlen(haystack);
  int needle_len = strlen(needle);

  int end = start + needle_len - 1;

  int i;

  for (i = 0; i < start; i++) {
    putchar(haystack[i]);
  }
  putchar(open_delim);
  for (i = start; i <= end; i++) {
    putchar(haystack[i]);
  }
  putchar(close_delim);
  for (i = end + 1; i < haystack_len; i++) {
    putchar(haystack[i]);
  }
}

int main(void)
{
  char line[MAXLEN];

  while (get_line(line, MAXLEN) > 0) {
    highlight_substr(line, needle, '<', '>');
    putchar('\n');
  }


  return EXIT_SUCCESS;
}
