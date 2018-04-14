#include <stdio.h>
#include <string.h>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#define PI pair<int,int>
int map[51][51];
int n, m, ans = 0;
int r, c, dir;
bool chk(int i, int j) {
	return i >= 0 && i<n&&j >= 0 && j<m&&map[i][j] == 0;
}
int proc(int depth) {
	if (map[r][c] != 2) {
		ans++;
	}
	map[r][c] = 2;
	if (depth == 4) {
		if (dir == 1)c--;
		if (dir == 2)r--;
		if (dir == 3)c++;
		if (dir == 0)r++;
		if (r >= 0 && r<n&&c >= 0 && c<m&&map[r][c] != 1)
			proc(0);
		else
		{
			printf("%d", ans);
			return 0;
		}
	}
	else if (dir == 0) {//ºÏ
		if (chk(r, c - 1)) {
			dir = 3, c--;
			proc(0);
		}
		else dir = 3, proc(depth + 1);
	}
	else if (dir == 3) {//¼­
		if (chk(r + 1, c)) {
			dir = 2, r++;
			proc(0);
		}
		else dir = 2, proc(depth + 1);
	}
	else if (dir == 2) {//³²
		if (chk(r, c + 1)) {
			dir = 1, c++;
			proc(0);
		}
		else dir = 1, proc(depth + 1);
	}
	else if (dir == 1) {//µ¿
		if (chk(r - 1, c)) {
			dir = 0, r--;
			proc(0);
		}
		else dir = 0, proc(depth + 1);
	}
}
int main() {
	//d 0ºÏ 1µ¿ 2³² 3¼­
	//ºóÄ­Àº 0 º®Àº 1
	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &r, &c, &dir);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &map[i][j]);

	proc(0);
}