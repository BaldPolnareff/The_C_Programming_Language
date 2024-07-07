#include <stdio.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int main(int argc, char *argv[])
{
  while (--argc > 0) {
    printf("%s%s", *++argv, (argc > 1) ? " " : "");
  }
  puts("");
  return EXIT_SUCCESS;
}
