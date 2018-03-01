#include <algorithm>
#include <cstdio>
#include <queue>
#include <functional>
#define INF 1e9;
#define PI pair<int,int>
using namespace std;
int m,n;
int map[101][101];
int dp[101][101];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
bool chk(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}
void bfs(int px, int py) {
	dp[px][py] = 0;
	queue<PI> q;
	q.push({px, py});
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (chk(nx, ny)&& dp[x][y]+map[nx][ny]<dp[nx][ny]) {
				dp[nx][ny]=dp[x][y]+map[nx][ny];
				q.push({nx, ny});
			}
		}
	}
}
int main() {
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
			dp[i][j] = INF;
		}
	bfs(0, 0);
	printf("%d\n",dp[n - 1][m - 1]);
	return 0;
}