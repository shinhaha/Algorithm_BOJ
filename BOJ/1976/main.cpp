#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int map[201][201];
int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i == j)map[i][j] = 0;
			else map[i][j] = 1e9;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++) {
					int input; scanf("%d", &input);
					if (input)map[i][j] = input;
				}
			for (int k = 0; k<n; k++)
				for (int i = 0; i < n; i++) {
					if (map[i][k] == 1e9)continue;
					for (int j = 0; j < n; j++)
						map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
				}
			vector<int> v;
			for (int i = 0; i < m; i++) {
				int input; scanf("%d", &input);
				v.push_back(input);
			}

			for (int i = 0; i < m - 1; i++) {
				if (map[v[i]][v[i + 1]] == 1e9) {
					printf("NO");
					return 0;
				}
			}
			printf("YES");
			return 0;
}