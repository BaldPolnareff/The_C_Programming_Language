#include <stdio.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
static int choice = 7;

char *month_name(int n) {
  char *month[] = {
    "Illegal number: pick between 1 and 12!", 
    "January", 
    "February", 
    "March", 
    "April", 
    "May", 
    "June", 
    "July", 
    "August", 
    "September", 
    "October", 
    "November", 
    "December"
  };

  return (n < 1 || n > 12) ? month[0] : month[n];
}
int main(void)
{
  printf("Month with number %d: \n", choice);
  printf("%s\n", month_name(choice));
  return EXIT_SUCCESS;
}
