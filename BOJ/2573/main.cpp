#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
int n, m;
int map[301][301];
int chk[301 * 301] = { 0 };
bool visit[301*301];
void mark(int i,int j){
	int flag = 0;
	flag += i && !map[i - 1][j] ? 1 : 0;
	flag += j && !map[i][j-1] ? 1 : 0;
	flag += (i+1)<n&&!map[i+1][j] ? 1 : 0;
	flag += (j+1)<m&&!map[i][j+1] ? 1 : 0;
	chk[i*m + j] = flag;
}
void dfs(int i,int j) {
	visit[i*m+j] = true;
	if (i&&!visit[(i-1)*m+j]&&map[i-1][j])dfs(i - 1, j);
	if (j&&!visit[i*m+j-1]&&map[i][j-1])dfs(i, j - 1);
	if (i + 1 < n&&!visit[(i+1)*m+j]&&map[i+1][j])dfs(i + 1, j);
	if (j + 1 < m&&!visit[i*m+j+1]&&map[i][j+1])dfs(i, j + 1);
}
int main() {
	scanf("%d %d", &n, &m);
	int bingsan = 0, day = 0,c;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j])bingsan++;
		}
	while (bingsan>0) {
		day++; c = 0;
		memset(visit,false, sizeof(visit));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)if(map[i][j])mark(i, j);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (map[i][j]) {
					if (map[i][j] - chk[i*m + j] <= 0) {
						map[i][j] = 0;
						bingsan--;
					}
					else map[i][j] -= chk[i*m + j];
				}
			}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			if (!visit[i*m + j]&&map[i][j])dfs(i, j), c++;
		if (c >= 2) {
			printf("%d", day);
			return 0;
		}
	}
	printf("0");
	return 0;
}