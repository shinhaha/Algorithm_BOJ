#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <stdlib.h>
#include <functional>
#include <algorithm>
using namespace std;
#define PI pair<int,int>

int map[1001][1001];
int dp[1001][1001][3] = { 0 };

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &map[i][j]);
	if (!map[0][0])dp[0][0][0] = 1;
	for (int i = 0; i<n; i++)
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0) {
				dp[i][j][0] = max(dp[i][j][0], max(max(i ? dp[i - 1][j][0] : 0, j ? dp[i][j - 1][0] : 0), max(i ? dp[i - 1][j][2] + 1 : 0, j ? dp[i][j - 1][2] + 1 : 0)));
				dp[i][j][1] = max(i ? dp[i - 1][j][1] : 0, j ? dp[i][j - 1][1] : 0);
				dp[i][j][2] = max(i ? dp[i - 1][j][2] : 0, j ? dp[i][j - 1][2] : 0);
			}
			else if (map[i][j] == 1) {
				dp[i][j][0] = max(i ? dp[i - 1][j][0] : 0, j ? dp[i][j - 1][0] : 0);
				dp[i][j][1] = max(max(i ? dp[i - 1][j][1] : 0, j ? dp[i][j - 1][1] : 0), max(i&&dp[i - 1][j][0]>0 ? dp[i - 1][j][0] + 1 : 0, j&&dp[i][j - 1][0]>0 ? dp[i][j - 1][0] + 1 : 0));
				dp[i][j][2] = max(i ? dp[i - 1][j][2] : 0, j ? dp[i][j - 1][2] : 0);
			}
			else if (map[i][j] == 2) {
				dp[i][j][0] = max(i ? dp[i - 1][j][0] : 0, j ? dp[i][j - 1][0] : 0);
				dp[i][j][1] = max(i ? dp[i - 1][j][1] : 0, j ? dp[i][j - 1][1] : 0);
				dp[i][j][2] = max(max(i ? dp[i - 1][j][2] : 0, j ? dp[i][j - 1][2] : 0), max(i&&dp[i - 1][j][1]>0 ? dp[i - 1][j][1] + 1 : 0, j&&dp[i][j - 1][1]>0 ? dp[i][j - 1][1] + 1 : 0));
			}
		}
	int ret = max(dp[n - 1][n - 1][2], max(dp[n - 1][n - 1][0], dp[n - 1][n - 1][1]));
	printf("%d", ret);

	return 0;
}