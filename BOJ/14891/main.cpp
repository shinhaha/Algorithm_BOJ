#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int w[10][8];
int indexrem[10] = { 0 };
int visited[10];
char buf[10];

int plu(int x, int c) {
	x = x + c;
	x %= 8;
	return x;
}
int minu(int x, int c) {
	if (x < c)
		x = x - c + 8;
	else x = x - c;
	return x;
}

void rotate(int idx, int opt) {
	visited[idx] = true;
	if (w[idx][0] != -1) {
		if (opt == -1) {//좌로 회전
			if (w[idx][plu(indexrem[idx], 2)] != w[idx + 1][minu(indexrem[idx + 1], 2)] && !visited[idx + 1]) {
				rotate(idx + 1, 1);
			}
			if (w[idx][minu(indexrem[idx], 2)] != w[idx - 1][plu(indexrem[idx - 1], 2)] && !visited[idx - 1]) {
				rotate(idx - 1, 1);
			}
			indexrem[idx] = plu(indexrem[idx], 1);
		}
		else if (opt == 1) {//우로 회전
			if (w[idx][plu(indexrem[idx], 2)] != w[idx + 1][minu(indexrem[idx + 1], 2)] && !visited[idx + 1]) {
				rotate(idx + 1, -1);
			}
			if (w[idx][minu(indexrem[idx], 2)] != w[idx - 1][plu(indexrem[idx - 1], 2)] && !visited[idx - 1]) {
				rotate(idx - 1, -1);
			}
			indexrem[idx] = minu(indexrem[idx], 1);
		}
	}
}
int main() {
	memset(w, -1, sizeof(w));
	for (int i = 1; i <= 4; i++) {
		scanf("%s", buf);
		for (int j = 0; j < strlen(buf); j++)
			w[i][j] = buf[j] - '0';
	}
	int k; scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		memset(visited, 0, sizeof(visited));
		int a, b; scanf("%d %d", &a, &b);
		rotate(a, b);
	}
	printf("%d", (w[1][indexrem[1]] ? 1 : 0) + (w[2][indexrem[2]] ? 2 : 0) + (w[3][indexrem[3]] ? 4 : 0) + (w[4][indexrem[4]] ? 8 : 0));
	return 0;
}