//boj 11404
#include <stdio.h>
#include <algorithm>
using namespace std;
#define INF 10000000
int main() {
	int n, m; scanf("%d %d", &n, &m);
	int** arr = new int*[n + 1]();
	for (int i = 0; i <= n; i++)
		arr[i] = new int[n + 1]();

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j)arr[i][j] = INF;
			else arr[i][j] = 0;

			for (int i = 0; i < m; i++) {
				int a, b, c; scanf("%d %d %d", &a, &b, &c);
				arr[a][b] = min(arr[a][b],c);
			}

			for (int k = 1; k <= n; k++)
				for (int i = 1; i <= n; i++) {
					if (arr[i][k] == INF)continue;
					for (int j = 1; j <= n; j++)
						arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
				}

			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (arr[i][j] == INF)arr[i][j] = 0;
					printf("%d ", arr[i][j]);
				}
				printf("\n");
			}

}