#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define MAXLEN 20

_Bool is_newline(char c) {
  return c == '\n';
}

_Bool is_blank(char c) {
  return (c == '\t' || c == ' ' || is_newline(c));
}

void trim(char *string) {
  int i;
  int len = strlen(string);
  if (len == 0) {
    return;
  }

  for (i = len - 1; i >= 0; i--) {
    if (!is_blank(string[i])) {
      string[i + 1] = '\0';
      break;
    }
  }
}

_Bool is_hex_symbol(char c) {
  return (
    ('0' <= c && c <= '9') ||
    ('a' <= c && c <= 'f') ||
    ('A' <= c && c <= 'F')
  );
}

_Bool is_hex(char *string) {
  int i;
  int start_index = 0;
  if (string[0] == '0' && (string[1] == 'x' || string[1] == 'X')) {
    start_index = 2;
  }

  for (i = start_index; i < strlen(string); i++) {
    if (!is_hex_symbol(string[i])) {
      return false;
    }
  }
  return true;
}

long int htoi(char *string) {
  long num = 0;
  int start_index = 0;
  int len = strlen(string);

  if (string[0] == '0' && (string[1] == 'x' || string[1] == 'X')) {
    start_index = 2;
  }

  for (int i = start_index; i < len; i++) {
    char c = tolower(string[i]);
    if (isdigit(string[i])) {
      num = num * 16 + (c - '0');
    } else {
      num = num * 16 + (c - 'a' + 10); // It's a formula you can find, it just takes into account the character ranges in ASCII tables ('0'-'9', 'a'-'z', 'A'-'Z' are contiguous)
    }
  }

  return num;
}


int main(void)
{
  int c, i;
  i = 0;

  char hex[MAXLEN];

  while ((c = getchar()) != EOF) {
    if (i >= MAXLEN - 1) {
      printf("Input is too long.\n");
      return EXIT_FAILURE;
    }
    hex[i] = c;
    i++;
  }
  /* Trim the string, you accidentally append a newline when pressing enter in STDIN. 
   * The method also makes sure the string is null terminated.*/
  trim(hex);
  
  if (!is_hex(hex)) {
    printf("%s is not a valid hexadecimal number.\n", hex);
    return EXIT_FAILURE;
  }
  
  long num = htoi(hex);
  printf("Hex: %s\tParsed integer: %ld\n", hex, num);

  return EXIT_SUCCESS;
}
