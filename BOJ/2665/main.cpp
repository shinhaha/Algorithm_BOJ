#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
#define PI pair<int,int>
char map[55][55];
char buf[55];
int rem[55][55];
int ax[] = { 0,0,1,-1 };
int ay[] = { 1,-1,0,0 };
int main() {
	int n; scanf("%d", &n);
	queue <pair<pair<int, int>, int>> q;
	for (int i = 0; i < n; i++) {
		scanf("%s", buf);
		for (int j = 0; j < n; j++) {
			map[i][j] = buf[j];
			rem[i][j] = 1e9;
		}
	}
	rem[0][0] = 0;
	q.push({ { 0,0 },0 });
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int c = q.front().second; q.pop();
		for (int z = 0; z < 4; z++) {
			int finx = x + ax[z];
			int finy = y + ay[z];
			if (finx >= 0 && finx<n&&finy >= 0 && finy<n) {
				if (map[finx][finy] == '0'&&rem[finx][finy] >c + 1)q.push({ { finx,finy }, c + 1 }), rem[finx][finy] = c + 1;
				else if (map[finx][finy] == '1'&&rem[finx][finy]>c)
					q.push({ { finx,finy },c }), rem[finx][finy] = c;
			}
		}
	}
	printf("%d", rem[n - 1][n - 1]);
	return 0;
}