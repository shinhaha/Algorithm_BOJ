#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <string.h>
#include <string>
using namespace std;
char map[1001][1001];
int c[1000001];
int n, m;
int find(int i) {
	if (c[i] < 0)return i;
	return c[i] = find(c[i]);
}

void unite(int i, int j) {
	int x = find(i);
	int y = find(j);
	if (c[x] < c[y]) {
		c[x] += c[y];
		c[y] = x;
	}
	else {
		c[y] += c[x];
		c[x] = y;
	}
}

int main() {
	scanf("%d %d", &n,&m);
	for (int i = 0; i < n; i++)
		scanf("%s", map[i]);
	memset(c, -1, sizeof(c));

	for(int i=0; i<n; i++)
		for (int j = 0; j < m; j++) {
			switch (map[i][j]) {
			case 'S':
				if (find(i*m + j) != find((i + 1)*m + j))
					unite(i*m + j, (i + 1)*m + j);
				break;
			case 'N':
				if (find(i*m + j) != find((i - 1)*m + j))
					unite(i*m + j, (i - 1)*m + j);
				break;
			case 'E':
				if (find(i*m + j) != find(i*m + j+1))
					unite(i*m + j, i*m +j+1);
				break;
			case 'W':
				if (find(i*m + j) != find(i*m + j-1))
					unite(i*m + j, i*m + j-1);
				break;
			}
		}
	int ret = 0;
	for (int i = 0; i < n*m; i++)
		if (c[i] < 0)ret++;
	printf("%d", ret);
	return 0;
}