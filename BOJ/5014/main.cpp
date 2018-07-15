#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <string.h>
#include <string>
#include <queue>
using namespace std;
bool visit[1000001];


int main() {
	int f, s, g, u, d; scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
	queue<int> q;

	q.push(s);
	visit[s] = true;
	int day = -1;
	while (!q.empty()) {
		int qsize = q.size();
		day++;
		for (int x = 0; x < qsize; x++) {
			int curr = q.front(); q.pop();
			if (curr ==g) {
				printf("%d", day);
				return 0;
			}
			if (curr + u <= f && !visit[curr + u]) {
				visit[curr + u] = true;
				q.push(curr + u);
			}
			if (curr - d >= 1 && !visit[curr - d]) {
				visit[curr - d] = true;
				q.push(curr - d);
			}
		}
	}
	printf("use the stairs");
}