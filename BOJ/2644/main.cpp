#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <string.h>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;
int map[101][101] = { 0 };
bool visit[101][101] = { 0 };
int main() {
	int n, a, b, m; scanf("%d %d %d %d", &n, &a, &b, &m);

	for (int i = 0; i < m; i++) {
		int q, w; scanf("%d %d", &q, &w);
		map[q][w] = map[w][q] = 1;//q는 w의 부모
	}

	queue<int> q;

	q.push(a);

	int ret = -1;
	while (!q.empty()) {
		ret++;
		int qsize = q.size();
		for (int x = 0; x < qsize; x++) {
			int curr = q.front(); q.pop();
			if (curr == b) {
				printf("%d", ret);
				return 0;
			}
			for(int i=1; i<=n; i++)
				if (map[i][curr] && !visit[i][curr]) {
					q.push(i);
					visit[i][curr]= visit[curr][i] = true;
				}
		}
	}
	printf("-1");
	return 0;
}