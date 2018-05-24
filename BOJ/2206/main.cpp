#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include <queue>
using namespace std;
#define PI pair<int,int>
int n, m;
int map[1001][1001];
int visit[1001][1001][2] = { 0 };
char buf[1001];

bool chk(int i, int j) {
	return i >= 0 && i < n&&j < m&&j >= 0;
}

void bfs() {
	int ax[] = { 1,-1,0,0 };
	int ay[] = { 0,0,1,-1 };
	queue<pair<PI, int>> q;
	memset(visit, -1, sizeof(visit));
	q.push({ { 0,0 },1 });
	visit[0][0][1] = 1;
	while (!q.empty()) {
		pair<PI, int> curr = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int finx = curr.first.first + ax[i];
			int finy = curr.first.second + ay[i];
			if (!(chk(finx, finy)))continue;
			if (map[finx][finy]) {
				if (curr.second == 0) continue;
				if (visit[finx][finy][0] != -1)continue;
				visit[finx][finy][0] = visit[curr.first.first][curr.first.second][curr.second] + 1;
				q.push({ { finx,finy },0 });
			}
			else {
				if (visit[finx][finy][curr.second] != -1) continue;
				visit[finx][finy][curr.second] = visit[curr.first.first][curr.first.second][curr.second] + 1;
				q.push({ { finx,finy },curr.second });
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", buf);
		for (int j = 0; j < strlen(buf); j++)
			map[i][j] = buf[j] - '0';
	}

	bfs();

	int ans = 1e9;

	if (visit[n - 1][m - 1][0] != -1)ans = min(ans, visit[n - 1][m - 1][0]);
	if (visit[n - 1][m - 1][1] != -1)ans = min(ans, visit[n - 1][m - 1][1]);

	printf("%d", ans == 1e9 ? -1 : ans);
	return 0;
}