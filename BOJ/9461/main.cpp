#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <string.h>
using namespace std;
typedef long long ll;
ll dp[101];
int main() {
	//dp[i]=dp[i-1]+dp[i-5]
	int test; scanf("%d", &test);
	while (test--) {
		memset(dp, 0, sizeof(dp));
		dp[1] = dp[2] = dp[3] = 1;
		dp[4] = dp[5] = 2;
		int n; scanf("%d", &n);
		if (n <= 3)printf("1\n");
		else if (n <= 5)printf("2\n");
		else {
			for (int i = 5; i <= n; i++)
				dp[i] = dp[i - 1] + dp[i - 5];
			printf("%lld\n", dp[n]);
		}
	}
}