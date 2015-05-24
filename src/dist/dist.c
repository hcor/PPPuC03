#include <stdio.h>
#include <math.h>

typedef struct {
	double x, y;
} Point;

int main()
{
	Point p1, p2;
	if (scanf("%lf%lf\n", &p1.x, &p1.y) == 2 &&
	    scanf("%lf%lf"  , &p2.x, &p2.y) == 2)
		printf("%.2f\n", sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)));
	return 0;
}

