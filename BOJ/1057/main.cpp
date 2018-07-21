#include <stdio.h>
#include <math.h>
int main() {
	int n, a, b;

	scanf("%d %d %d", &n, &a, &b);
	int curr = 1;
	int sum = 0;
	while (curr < n)sum += curr, curr *= 2;;
	a += sum; b += sum;

	int ret = 0;

	while (true) {
		if (!a || !b) {
			printf("-1");
			return 0;
		}
		if (a == b) {
			printf("%d", ret);
			return 0;
		}ret++;
		a /= 2; b /= 2;
	}
	return 0;
}