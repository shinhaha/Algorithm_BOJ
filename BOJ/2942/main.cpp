#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	if (!b)return a;
	return gcd(b, a%b);
}
int main() {
	int r, g; scanf("%d %d", &r, &g);
	int k = gcd(r, g);
	for (int i = 1; i <= k; i++) {
		if (k%i == 0)
			printf("%d %d %d\n", i, r / i, g / i);
	}

	return 0;
}