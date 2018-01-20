//boj 1753
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
#define Vertice pair<int,int>//weight,vertice
#define Edge pair<int,int>//dest,weight
#define INF 1e9

int main() {
	int V, E,src; scanf("%d %d %d", &V, &E, &src);
	priority_queue<Vertice, vector<Vertice>, greater<Vertice>> pq;
	vector<Edge>* v = new vector<Edge>[V + 1]();
	int* dist = new int[V + 1](); fill(dist,dist + V + 1,INF);

	for (int i = 0; i < E; i++) {
		int from, to, weight; scanf("%d %d %d", &from, &to, &weight);
		v[from].push_back({to,weight});}

	dist[src] = 0;	pq.push({ dist[src],src });
	while (!pq.empty()) {
		int weight = pq.top().first;
		int curr = pq.top().second; pq.pop();
		if (dist[curr] < weight)continue;
		for (int i = 0; i<v[curr].size(); i++)
			if (dist[v[curr][i].first] > dist[curr] + v[curr][i].second) {
				dist[v[curr][i].first] = dist[curr] + v[curr][i].second;
				pq.push({ dist[v[curr][i].first],v[curr][i].first });
			}
	}
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF)printf("INF\n");
		else printf("%d\n", dist[i]);
	}
	return 0;
}