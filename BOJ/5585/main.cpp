#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <string.h>
using namespace std;//500,100,50,10,5,1
int dp[1001];
int main() {
	int money; scanf("%d", &money);
	money = 1000 - money;
	fill(dp, dp + 1000, 1001);
	dp[0] = 0;
	int table[] = { 1,5,10,50,100,500 };
	for (int i = 0; i < 6; i++)
		for (int j = table[i]; j <= 1000; j++)
			dp[j] = min(dp[j], dp[j - table[i]] + 1);
	printf("%d", dp[money]);
}