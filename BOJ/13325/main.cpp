#include <cstdio>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>
#include <functional>
using namespace std;

const int maxN = 2 << 21;
int bst[maxN];
int n;
long long sum = 0;

int rec(int idx) {
	if (idx >= (int)pow(2, n) - 1)return 0;
	int left = rec(2 * idx + 1) + bst[idx * 2 + 1];
	int right = rec(2 * idx + 2) + bst[idx * 2 + 2];
	sum += abs(right - left);
	return max(right, left);
}
int main() {
	scanf("%d", &n);
	int idx = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < pow(2, i); j++) {
			scanf("%d", &bst[idx++]);
			sum += bst[idx - 1];
		}
	}
	rec(0);
	printf("%lld", sum);

	return 0;
}