#include <stdio.h>

int main() {
	double w;
	double h;
	double area;
	double perimeter;

	w = 10.0;
	h = 5.0;
	area = w * h;
	perimeter = 2 * (w + h);
	
	printf("사각형의 넓이 : %lf\n", area);
	printf("사각형의 둘레 : %lf", perimeter);

	return 0;
}