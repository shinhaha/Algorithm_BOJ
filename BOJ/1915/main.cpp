#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <string.h>
#include <string>
using namespace std;
char map[1001][1001];
int dp[1001][1001];
int n, m;
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)scanf("%s",map[i]);
	int ret = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (map[i][j]=='1') {
				if (i == 0 || j == 0) dp[i][j] = 1;
				else if(i&&j) {
					int m = 1e9;
					m = min(m, dp[i - 1][j]);
					m = min(m, dp[i][j - 1]);
					m = min(m, dp[i - 1][j - 1]);
					if (m == 1e9) m = 0;
					dp[i][j] = m + 1;
				}
				ret = max(ret, dp[i][j]);
			}
	printf("%d",ret*ret);
	return 0;
}