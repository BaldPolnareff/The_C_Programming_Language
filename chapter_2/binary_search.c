#include <stdio.h>
#include <stdbool.h>

#define MAXLEN 100000
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1 

_Bool binary_search(int nums[], int needle, int size) {
  int lower = 0;
  int upper = size - 1;
  int mid;
  int guess;
  while (lower <= upper) {
    mid = (lower + upper) / 2; // no need to floor with integers in C ;)
    guess = nums[mid];

    if (guess == needle) {
      return true;
    } else if (guess < needle) {
      lower = mid + 1;
    } else {
      upper = mid - 1;
    }
  }

  return false;
}

int main(void)
{
  int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 10, 12, 69, 100, 200, 201, 300, 400, 420};
  int needle = 1000;
  int size = sizeof(numbers) / sizeof(numbers[0]);

  if (binary_search(numbers, needle, size)) {
    printf("%d is in array!\n", needle);
  } else {
    printf("%d is not in the array!\n", needle);
  }

  return EXIT_SUCCESS;
}
