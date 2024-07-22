#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

static char usage_text[] = "Usage: diff <file1> <file2>";

void diff(char **args) {
  FILE *files[2];
  char line_buffer_0[MAXLINE];
  char line_buffer_1[MAXLINE];

  for (int i = 0; i < 2; i++) {
    if ((files[i] = fopen(args[i], "r")) == NULL) {
      fprintf(stderr, "diff: can't open %s\n", args[i]);
      exit(EXIT_FAILURE);
    } 
  }

  while (fgets(line_buffer_0, MAXLINE, files[0]) != NULL && fgets(line_buffer_1, MAXLINE, files[1]) != NULL) {
    if (strcmp(line_buffer_0, line_buffer_1) != 0) {
      fprintf(stderr, "diff:\n%s\n\n\n%s\n", line_buffer_0, line_buffer_1);
      exit(EXIT_FAILURE);
    }
  }
  fclose(files[0]);
  fclose(files[1]);
}

int main(int argc, char *argv[])
{
  char **args = &argv[1];

  if (argc != 3) {
    fputs(usage_text, stderr);
    exit(EXIT_FAILURE);
  }

  diff(args);
  return EXIT_SUCCESS;
}
