#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int ret = 0;
int map[501][501];
bool visit[501][501] = { 0 };
int n, m;

int ax[] = { 0,0,1,-1 };
int ay[] = { 1,-1,0,0 };


int chk(int i, int j) {
	return (i >= 0 && j >= 0 && i < n&&j < m);
}
void dfs(int i, int j, int c, int s) {
	if (c == 3) {
		ret = max(ret, s);
	}
	else
	for (int q = 0; q < 4; q++) {
		int finx = i + ax[q];
		int finy = j + ay[q];
		if (finx >= 0 && finx < n&&finy >= 0 && finy < m && !visit[finx][finy]) {
			visit[finx][finy] = true;
			dfs(finx, finy, c + 1, s + map[finx][finy]);
			visit[finx][finy] = false;
		}
	}
}

void except(int i, int j) {
	int tmp = -1;
	if (chk(i, j + 2)) {
		if (chk(i + 1, j + 1))tmp = max(tmp, map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1]);
		if (chk(i - 1, j + 1))tmp = max(tmp, map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i - 1][j + 1]);
	}
	if (chk(i + 2, j)) {
		if (chk(i + 1, j - 1))tmp = max(tmp, map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j - 1]);
		if (chk(i + 1, j + 1))tmp = max(tmp, map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j + 1]);
	}
	ret = max(ret, tmp);
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &map[i][j]);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			visit[i][j] = true;
			dfs(i, j, 0, map[i][j]);
			except(i, j);
			visit[i][j] = false;
		}

	printf("%d", ret);
	return 0;
}