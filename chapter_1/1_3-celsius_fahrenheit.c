#include <stdio.h>

/* print Fahrenheit-Celsius table 
 * for fahr = 0, 20, ..., 300
 */

float fahrenheit_to_celsius(float temp) {
  float celsius = 5.0 * (temp - 32.0) / 9.0;
  return celsius;
}

int main(void)
{
  float fahr;
  float celsius;
  float lower, upper, step;

  /* x[C] = (5/9) * (x[F] - 32) */

  lower = 0.0;
  upper = 300.0;
  step = 20.0;

  fahr = lower;

  printf("  [F]\t    [C]\n");
  while (fahr <= upper) {
    celsius = fahrenheit_to_celsius(fahr);
    printf("%3.0f\t%6.1f\n", fahr, celsius);
    fahr += step;
  }
  return 0;
}
