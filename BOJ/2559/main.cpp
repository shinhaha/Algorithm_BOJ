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
vector<int> v;

int sum(int i, int j) {
	int ret = 0;

	for (int idx = i; idx <= j; idx++)
		ret += v[idx];
	return ret;
}

int main() {
	int n, k; scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		int input; scanf("%d", &input);
		v.push_back(input);
	}

	int q = -10000001;
	int old = q;

	for (int i = 0; i < n - k + 1; i++) {
		int j = i + k - 1;
		if (!i)old = sum(i, j);
		else
			old = old - v[i - 1] + v[j];
		q = max(q, old);
	}

	printf("%d", q);

	return 0;
}