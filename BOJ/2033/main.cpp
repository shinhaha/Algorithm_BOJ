#include <stdio.h>
#include <math.h>
int main() {
	double n; scanf("%lf", &n);
	double mul = 10.0;
	while (true) {
		if (n > mul) {
			n /= mul;
			n = round(n);
			n *= mul;
		}
		else break;
		mul *= 10.0;
	}
	printf("%.0lf", n);
	return 0;
}