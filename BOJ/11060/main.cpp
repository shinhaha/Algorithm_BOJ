#include <stdio.h>
#include <vector>
#include <algorithm>
#define INF 2000000000
using namespace std;
int main() {
	int n; scanf("%d", &n);
	int* arr = new int[n]();
	int* dp = new int[n]();
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		dp[i] = INF;
	}
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		int tmp = arr[i];
		for (int j = i; (j<n) && (j <= i + tmp); j++)
			if (i != j)dp[j] = min(dp[i] + 1, dp[j]);
	}
	if (dp[n - 1] == INF)
		printf("-1");
	else
		printf("%d", dp[n - 1]);
}