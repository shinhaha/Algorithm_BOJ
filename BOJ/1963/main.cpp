#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
bool chk[10001] = { 0 };
bool visit[10001] = { 0 };
queue<int> q;
int org = 0, target = 0; int ret = 0;
int bfs() {
	ret = 0;
	q.push(org);
	while (!q.empty()) {
		ret++;
		int qsize = q.size();
		for (int i = 0; i < qsize; i++) {
			int k = q.front(); q.pop();
			if (k == target)return 1;
			visit[k] = true;
			int a = k / 1000; int b = k % 1000 / 100; int c = k % 100 / 10; int d = k % 10;
			for (int i = 0; i <= 9; i++) {
				int ret = 1e9 + 1;
				if (i >= 1 && !chk[1000 * i + k % 1000] && !visit[1000 * i + k % 1000]) {
					visit[1000 * i + k % 1000] = true;
					q.push(1000 * i + k % 1000);
				}
				if (!chk[100 * i + 1000 * a + 10 * c + d] && !visit[100 * i + 1000 * a + 10 * c + d]) {
					visit[100 * i + 1000 * a + 10 * c + d] = true;
					q.push(100 * i + 1000 * a + 10 * c + d);
				}
				if (!chk[10 * i + 1000 * a + 100 * b + d] && !visit[10 * i + 1000 * a + 100 * b + d]) {
					visit[10 * i + 1000 * a + 100 * b + d] = true;
					q.push(10 * i + 1000 * a + 100 * b + d);
				}
				if (!chk[i + 1000 * a + 100 * b + 10 * c] && !visit[i + 1000 * a + 100 * b + 10 * c]) {
					visit[i + 1000 * a + 100 * b + 10 * c] = true;
					q.push(i + 1000 * a + 100 * b + 10 * c);
				}
			}
		}
	}
	return 0;
}
int main() {
	chk[0] = chk[1] = true;
	for (int i = 2; i<10000; i++) {
		for (int j = 2 * i; j <10000; j += i)
			chk[j] = true;
	}
	int n; scanf("%d", &n);

	while (n--) {
		scanf("%d %d", &org, &target);
		memset(visit, false, sizeof(visit));
		if (bfs())printf("%d\n", ret-1);
		else printf("Impossible\n");
		while (!q.empty())q.pop();
	}

	return 0;
}