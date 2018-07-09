#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	int map[101][101];

	int n, m; scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			map[i][j] = 1e9;
			if (i == j)map[i][j] = 0;
		}
	
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		map[a][b] = map[b][a] = 1;
	}

	for(int k=1; k<=n; k++)
		for (int i = 1; i <= n; i++) {
			if (map[i][k] == 1e9)continue;
			for (int j = 1; j <= n; j++) {
				if (map[i][j] > map[i][k] + map[k][j])
					map[i][j] = map[i][k] + map[k][j];
			}
		}

	int s = 1e10; int index = -1;
	for (int i = 1; i <= n; i++) {
		int q = 0;
		for (int j = 1; j <= n; j++)q += map[i][j];
		if (q < s) {
			s = q;
			index = i;
		}
	}
	printf("%d", index);
	return 0;
}