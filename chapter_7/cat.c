#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void filecopy(FILE *ifp, FILE *ofp) {
  char c;

  while ((c = getc(ifp)) != EOF) {
    putc(c, ofp);
  }
}

void parse_cat_input_files(char **args) {
  FILE *fp;
  while (*args) {
    if ((fp = fopen(*args++, "r")) == NULL) {
      fprintf(stderr, "cat: can't open %s\n", *args);
      exit(EXIT_FAILURE);
    } else {
      filecopy(fp, stdout);
      fclose(fp);
    }
  }
}

int main(int argc, char *argv[])
{
  char **args = &argv[1];

  if (argc == 1) {
    filecopy(stdin, stdout);
  }

  parse_cat_input_files(args);

  return EXIT_SUCCESS;
}
