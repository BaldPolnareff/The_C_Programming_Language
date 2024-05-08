#include <stdio.h>
#include <stdbool.h>

#define MAXLEN 1000
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1 


void escape(char *input, char *output, char delim_open, char delim_close) {
  int i, j;

  for (i = j = 0; input[i] != EOF; i++) {
    switch (input[i]) {
      case '\n': {
        output[j++] = delim_open;
        output[j++] = '\\';
        output[j++] = 'n';
        output[j++] = delim_close;
        break;
      }
      case '\t': {
        output[j++] = delim_open;
        output[j++] = '\\';
        output[j++] = 't';
        output[j++] = delim_close;
        break;
      }
      default: {
        output[j++] = input[i];
        break;
      }
    }
  }
  output[j] = '\0';
}

int main(void)
{
  int c, i;
  char input_string[MAXLEN];
  char output_string[MAXLEN];

  i = 0;
  while ((c = getchar()) != EOF) {
    input_string[i] = c;
    i++;
  }
  input_string[i + 1] = '\0';

  escape(input_string, output_string, '{', '}');
  printf("%s\n", output_string);
  return EXIT_SUCCESS;
}
