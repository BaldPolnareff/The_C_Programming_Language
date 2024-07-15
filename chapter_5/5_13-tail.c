#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000
#define MAXLINES 10000

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1 
#define DEFAULT_TAIL 10 

bool is_digit(char c) {
  return c >= '0' && c <= '9';
}

bool is_integer(char *string) {
  while (*string) {
    if (!is_digit(*string)) {
      return false;
    }
    string++;
  }
  return true;
}

int array_length(char **arr) {
  int length = 0;
  while (*arr++ != NULL) {
    length++;
  }
  return length;
}

void tail(int n_lines, char *input_lines[], char *end[]) {
  if (n_lines > end - input_lines) {
    printf("WARNING! Input stream contains less lines (%ld) than requested tail (%d)!\n", end - input_lines, n_lines);
    n_lines = end - input_lines;
  }
  
  puts("\n--------------------------------------------");
  printf("Tail of %d elements: \n\n", n_lines);

  char **ptr = end - n_lines;

  while (ptr < end) {
    printf("%s", *ptr++);
  }
}

int main(int argc, char *argv[])
{
  char *lines[MAXLINES];
  int n_lines = DEFAULT_TAIL;
  char buffer[MAXLINE];
  char *buffer_start = buffer;
  char *buffer_ptr = buffer;
  int total_lines = 0;

  char c;
  
  if (argc > 2) {
    puts("Usage: tail -n");
    return EXIT_FAILURE;
  }
  if (--argc > 0 && (*++argv)[0] == '-') {
    if (is_integer(++argv[0])) {
      n_lines = atoi(argv[0]);
    } else {
      fputs("Argument needs to be an integer!", stderr);
      return EXIT_FAILURE;
    }
  }
  
  while ((c = getchar()) != EOF) {
    if (buffer_ptr - buffer_start > MAXLINE) {
      fputs("ERROR: Out of bounds input line!", stderr);
      return EXIT_FAILURE;
    }
    if (c == '\n') {
      *buffer_ptr++ = c;
      *buffer_ptr = '\0';
      lines[total_lines++] = strdup(buffer_start);
      buffer_ptr = buffer_start;
    }
    *buffer_ptr++ = c;
  }

  /*Case where the last character before EOF is not a newline (might happen often in stdin) */
  if (buffer_ptr != buffer_start) {
    *buffer_ptr++ = '\n';
    *buffer_ptr = '\0';
    lines[total_lines++] = strdup(buffer_start);
  }
  
  tail(n_lines, lines, lines + array_length(lines));

  return EXIT_SUCCESS;
}
