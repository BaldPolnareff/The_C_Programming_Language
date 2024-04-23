#include <stdio.h>
#include <stdbool.h>

float fahrenheit_to_celsius(float temp) {
  float celsius = (5.0/9.0) * (temp - 32.0);
  return celsius;
}

void print_temperature_table(float lower, float upper, float step, _Bool reverse) {
  printf("   [F]\t  [C]\n\n");

  if (reverse == true) {
    for (float fahr = upper; fahr >= lower; fahr -= step) {
      float celsius = fahrenheit_to_celsius(fahr);
      printf("%3.0f\t%6.1f\n", fahr, celsius);
    }
  } else {
    for (float fahr = lower; fahr <= upper; fahr += step) {
      float celsius = fahrenheit_to_celsius(fahr);
      printf("%3.0f\t%6.1f\n", fahr, celsius);
    }
  }
}

int main(void)
{
  print_temperature_table(0, 500, 20, true); 
  return 0;
}
