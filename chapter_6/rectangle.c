#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

static char *usage_text = "Provide two diagonally opposite points to build a rectangle in cartesian space and get its area back.\nUsage: rectangle x_0 y_0 x_1 y_1.\nUse '.' as a decimal separator.\ne.g. rectangle 0.0 0.0 1.0 1.0 >> 1.0\n";

struct cartesian_point {
  double x;
  double y;
};

/*I can represent a rectangle with two diagonally opposite points. 
 * That also means I can simply check that two provided points can build a valid
 * rectangle in cartesian space by checking that both provided points have
 * different x and y coordinates.
 */

struct rectangle {
  struct cartesian_point a;
  struct cartesian_point a_prime;
  struct cartesian_point b;
  struct cartesian_point b_prime;
  double base; /*a-a_prime */ 
  double height; /*a-b_prime*/
  double area;
};

/*Convention: 
 *
 * b'---------------b
 * |                |
 * |                |
 * |                |
 * a----------------a'
 */

double distance(struct cartesian_point a, struct cartesian_point b) {
  return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

void parse_points_from_args(char **args, struct cartesian_point *points) {
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
  
};

bool is_diagonal(struct cartesian_point *points) {
  if (points[0].x == points[1].x || points[0].y == points[1].y) {
    return false;
  }
  return true;
};

void build_rectangle(struct cartesian_point *points, struct rectangle *rect) {
  if (!is_diagonal(points)) {
    fputs("Not enough info to build a rectangle! Provide diagonally opposite points!\n\n\n", stderr);
    fputs(usage_text, stderr);
    exit(EXIT_FAILURE);
  }
  
  rect->a = points[0];
  rect->b = points[1];
  rect->a_prime.y = points[0].y;
  rect->a_prime.x = points[1].x;
  rect->b_prime.y = points[1].y;
  rect->b_prime.x = points[0].x;

  rect->base = distance(rect->a, rect->a_prime);
  rect->height = distance(rect->a, rect->b_prime);

  rect->area = rect->base * rect->height;
};

int main(int argc, char *argv[])
{
  char **args = &argv[1];
  
  struct cartesian_point points[] = {{0.0, 0.0}, {0.0, 0.0}}; /*Intentionally defaulting to a pair of invalid points to build a rectangle*/

  struct rectangle rect;

  if (argc != 5) {
    fputs(usage_text, stderr);
    exit(EXIT_FAILURE);
  }

  parse_points_from_args(args, points);
  build_rectangle(points, &rect);

  printf("\nCoordinates: (%f, %f), (%f, %f), (%f, %f), (%f, %f)\nArea: %f\n", rect.a.x, rect.a.y, rect.a_prime.x, rect.a_prime.y, rect.b.x, rect.b.y, rect.b_prime.x, rect.b_prime.y, rect.area);
}


