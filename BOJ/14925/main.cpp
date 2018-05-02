#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <string.h>
#include <string>
using namespace std;
int map[1001][1001];
int dp[1001][1001];
int n, m;
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)scanf("%d", &map[i][j]);

	int ret = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if ((i == 0 || j == 0) && map[i][j] == 0) {
				dp[i][j] = 1;
			}
			else if (i&&j&&map[i][j] == 0) {
				if (map[i][j] == 0) {
					int t = 1e9;
					t = min(t, dp[i - 1][j]);
					t = min(t, dp[i][j - 1]);
					t = min(t, dp[i - 1][j - 1]);
					if (t == 1e9) t = 0;
					dp[i][j] = t + 1;
					ret = max(ret, dp[i][j]);
				}
			}
			ret = max(ret, dp[i][j]);
		}

	printf("%d", ret);
	return 0;
}