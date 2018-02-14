#include <cstdio>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;
typedef long long ll;
ll dp[70][10];
ll sum(int len, int n) {
	ll ret = 0;
	for (int i = 0; i <= n; i++)
		ret += dp[len][i];
	return ret;
}

int main() {
	for (int i = 0; i < 10; i++)
		dp[1][i] = i + 1;//9==10

	for (int i = 1; i < 64; i++)
		for (int j = 0; j < 10; j++)
			dp[i + 1][j] = sum(i, j);

	int n; scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int input; scanf("%d", &input);
		printf("%lld\n", dp[input][9]);
	}

	return 0;
}