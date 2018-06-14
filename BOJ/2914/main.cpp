#include <stdio.h>
#include<math.h>
int main() {
	double n, k; scanf("%lf %lf", &n, &k);
	printf("%d", (int)ceil(n*(k - 1)) + 1);
}