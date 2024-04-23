#include <stdio.h>

float celsius_to_fahrenheit(float temp) {
  float fahr = (9.0/5.0) * temp + 32.0;
  return fahr;
}

int main(void)
{
  float fahr, celsius;
  float lower;
  float upper;
  float step;

  lower = 0.0;
  step = 20.0;
  upper = 300.0;
  celsius = lower;
  
  printf("  [C]\t  [F]\n");
  while (celsius <= upper) {
    fahr = celsius_to_fahrenheit(celsius);
    printf("%3.1f\t%6.1f\n", celsius, fahr);
    celsius += step;
  }

  return 0;
}
