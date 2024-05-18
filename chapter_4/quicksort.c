#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

void initialize_random_seed() {
  srand(time(NULL));
}

int get_random_integer(int min, int max) {
  double normalized_rand = (double)rand() / RAND_MAX;

  return min + (int)(normalized_rand * (max - min + 1)); 
}

int partition(int arr[], int lower, int upper, _Bool use_random_index) {
  /* Use a random integer between the lower and upper bounds of the array or default to the middle index of the array */
  int pivot_index = use_random_index ? get_random_integer(lower, upper) : (lower + upper) / 2;
  
  int pivot = arr[pivot_index];

  int left = lower;
  int right = upper;

  /* Move pivot to the end teporarily */
  int temp = arr[pivot_index];
  arr[pivot_index] = arr[upper];
  arr[upper] = temp;

  /* Initialize partition index before the 0th element */
  int i = lower - 1;

  for (int j = lower; j < upper; j++) {
    if (arr[j] <= pivot) {
      i++;
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }

  /* Place pivot in its correct position */
  temp = arr[i + 1];
  arr[i + 1] = arr[upper];
  arr[upper] = temp;

  return i + 1;
}

void qs(int arr[], int lower, int upper) {
  if (lower >= upper) {
    return;
  }

  int pivot_index = partition(arr, lower, upper, true);

  qs(arr, lower, pivot_index - 1);
  qs(arr, pivot_index + 1, upper);
}

void quicksort(int arr[], int len) {
  qs(arr, 0, len - 1);
}

void print_array(int arr[], int len) {
  printf("{%d, ", arr[0]);
  for (int i = 1; i < len - 1; i++) {
    printf("%d, ", arr[i]);
  }
  printf("%d}\n", arr[len - 1]);
}

int main(void)
{
  int numbers[] = {10, 7, 8, 2, 99, 12, 1, 0, 17, 44, 3, 19, 1000};
  int len = sizeof(numbers) / sizeof(numbers[0]);

  initialize_random_seed();
  
  puts("Before sorting:");
  print_array(numbers, len);

  quicksort(numbers, len);

  puts("After sorting:");
  print_array(numbers, len);

  return EXIT_SUCCESS;
}
