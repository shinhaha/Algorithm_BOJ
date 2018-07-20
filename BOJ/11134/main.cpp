#include <stdio.h>
#include <math.h>
int main() {
	int n; scanf("%d", &n);
	while (n--) {
		double a, b; scanf("%lf %lf", &a, &b);
		int ret = ceil(a / b);
		printf("%d\n", ret);
	}
	return 0;
}