#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <queue>
using namespace std;
int indegree[401] = { 0 };
bool visit[401] = { 0 };
bool done[401] = { 0 };
vector<int> graph[401];
vector<int> dfsret[401];
vector<int> ans;
int n, k;

void dfs(int i, int start) {
	for (int q = 0; q < graph[i].size(); q++) {
		if (!visit[graph[i][q]]) {
			visit[graph[i][q]] = true;
			dfsret[start].push_back(graph[i][q]);
			dfs(graph[i][q], start);
		}
	}
}

void bfs() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (!indegree[i]) {
			q.push(i);
			ans.push_back(i);
		}
	}
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int i = 0; i<graph[here].size(); i++) {
			int there = graph[here][i];
			if (!(--indegree[there])) {
				q.push(there);
				ans.push_back(there);
			}
		}
	}
}
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++) {
		int a, b; scanf("%d %d", &a, &b);
		indegree[b]++;
		graph[a].push_back(b);
	}
	bfs();
	int test; scanf("%d", &test);
	for (int i = 0; i < test; i++) {
		int a, b; scanf("%d %d", &a, &b);
		int next = 0, flag = 0;
		if (!done[a]) {
			done[a] = 1;
			memset(visit, 0, sizeof(visit));
			dfs(a, a);
		}
		if (!done[b]) {
			done[b] = 1;
			memset(visit, 0, sizeof(visit));
			dfs(b, b);
		}
		for (int j = 0; j < dfsret[a].size(); j++)
			if (dfsret[a][j] == b)next = 1;
		if (!next) {
			for (int j = 0; j < dfsret[b].size(); j++)
				if (dfsret[b][j] == a)next = 1;
			if (!next) {
				printf("0\n");
				continue;
			}
		}
		for (int j = 0; j < ans.size(); j++) {
			if (ans[j] == a)printf("-1\n"), flag = 1;
			if (ans[j] == b)printf("1\n"), flag = 1;
			if (flag)break;
		}
	}
	return 0;
}