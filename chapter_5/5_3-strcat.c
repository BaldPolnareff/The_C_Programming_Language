#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAXLEN 10000
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1 

static char appendix[] = "PORCAMADONNA";

void str_cat(char *target, char *string) {
  int target_len = strlen(target);
  int string_len = strlen(string);

  char *ptr = target + target_len;

  while (*string != '\0') {
    *ptr++ = *string++;
  }
  *ptr = '\0';
}

int main(void)
{
  char test_string[MAXLEN]; 
  char c;
  int i = 0;
  while ((c = getchar()) != EOF) {
    test_string[i++] = c;
  }
  test_string[i] = '\0';

  puts("\nString before concat:\n");
  printf("%s\n", test_string);
  puts("---------------------------------------------");
  
  str_cat(test_string, appendix);
  printf("String after concat of '%s'\n\n", appendix);
  printf("%s\n", test_string);


  return EXIT_SUCCESS;
}
