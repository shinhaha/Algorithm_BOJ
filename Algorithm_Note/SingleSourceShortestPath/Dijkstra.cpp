//boj 1753
#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
#define PI pair<int,int>//dest,weight
#define INF 123456789

int main() {
	int V, E; scanf("%d %d", &V, &E);
	int* dist = new int[V+1]();
	vector<PI>* v = new vector<PI>[V+1]();
	priority_queue<int,vector<int>,greater<int>> pq;
	int start; scanf("%d", &start);
	for (int i = 1; i <= V; i++)
		dist[i] = INF;
	for (int i = 0; i < E; i++) {
		int q ,w, e; scanf("%d %d %d", &q, &w, &e);
		v[q].push_back({ w,e });
	}
	dist[start] = 0;
	pq.push(start);
	while (!pq.empty()) {
		int curr = pq.top(); pq.pop();
		for(int i=0; i<v[curr].size(); i++)
			if (dist[v[curr][i].first] > dist[curr] + v[curr][i].second) {
				dist[v[curr][i].first] = dist[curr] + v[curr][i].second;
				pq.push(v[curr][i].first);
			}
	}
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF)printf("INF\n");
		else printf("%d\n", dist[i]);
	}
	return 0;
}