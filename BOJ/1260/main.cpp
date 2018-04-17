#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
void recu_dfs(vector<int>* v, int n, bool* chk, bool** visit) {
	chk[n] = true;
	printf("%d ", n);
	for (int i = 0; i<v[n].size(); i++)
		if (!visit[n][v[n][i]] && !chk[v[n][i]]) {
			visit[n][v[n][i]] = visit[v[n][i]][n] = true;
			recu_dfs(v, v[n][i], chk, visit);
		}
}
int main() {
	int V, E, start; scanf("%d %d %d", &V, &E, &start);
	vector<int>* v = new vector<int>[V + 1]();
	for (int i = 0; i < E; i++) {
		int a, b; scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= V; i++)
		sort(v[i].begin(), v[i].end());

	bool** visit = new bool*[V + 1];
	for (int i = 0; i <= V; i++)
		visit[i] = new bool[V + 1];
	bool* chk = new bool[V + 1];

	for (int i = 0; i <= V; i++)
		for (int j = 0; j <= V; j++)
			chk[i] = visit[i][j] = false;

	recu_dfs(v, start, chk, visit);
	printf("\n");

	for (int i = 0; i <= V; i++)
		for (int j = 0; j <= V; j++)
			chk[i] = visit[i][j] = false;

	queue<int> q;
	q.push(start);

	while (q.size()) {
		int tmp = q.front();
		if (!chk[tmp])
			printf("%d ", tmp);
		chk[tmp] = true;
		q.pop();
		for (int i = 0; i < v[tmp].size(); i++) {
			if (!visit[tmp][v[tmp][i]]) {
				visit[tmp][v[tmp][i]] = visit[v[tmp][i]][tmp] = true;
				q.push(v[tmp][i]);
			}
		}
	}
	return 0;
}