#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct cartesian_point {
    double x;
    double y;
};

static struct cartesian_point cartesian_origin = {0.0, 0.0};

static char *usage_text = "Usage: point_distance x_0 y_0 x_1 y_1\nUse . as a decimal separator\n";

double distance(struct cartesian_point a, struct cartesian_point b) {
  return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

bool is_digit(char c) {
  return c >= '0' && c <= '9';
}

void parse_points_from_argv(char *args[], struct cartesian_point *points) {
  char *endptr;
  for (int i = 0; i < 2; i++) {
    points[i].x = strtod(*args++, &endptr);
    if (*endptr != '\0') {
      fputs(usage_text, stderr);
      exit(EXIT_FAILURE);
    }
    points[i].y = strtod(*args++, &endptr);
    if (*endptr != '\0') {
      fputs(usage_text, stderr);
      exit(EXIT_FAILURE);
    }
  } 
}

int main(int argc, char *argv[])
{
  double d = 0.0;
  char **args = &argv[1];

  struct cartesian_point points[] = {cartesian_origin, cartesian_origin};

  if (argc != 5) {
    fputs(usage_text, stderr);
    return EXIT_FAILURE;
  }

  parse_points_from_argv(args, points);
  d = distance(points[0], points[1]);

  printf("Distance between points (%f, %f), (%f, %f): d = %f\n", points[0].x, points[0].y, points[1].x, points[1].y, d);
  return EXIT_SUCCESS;
}
