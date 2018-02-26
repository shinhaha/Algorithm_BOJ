#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <string.h>
#include <string>
#include <functional>
using namespace std;
int pre[1001];
#define Vertice pair<int,int>//weight,vertice
#define Edge pair<int,int>//dest,weight
#define INF 1e9
int main() {
	int V, E; scanf("%d %d", &V, &E);
	priority_queue<Vertice, vector<Vertice>, greater<Vertice>> pq;
	vector<Edge>* v = new vector<Edge>[V + 1]();
	int* dist = new int[V + 1](); fill(dist, dist + V + 1, INF);
	for (int i = 0; i < E; i++) {
		int from, to, weight; scanf("%d %d %d", &from, &to, &weight);
		v[from].push_back({ to,weight });
		pre[to] = from;
	}
	int src;  int des; scanf("%d %d", &src, &des);

	dist[src] = 0;	pq.push({ dist[src],src });
	while (!pq.empty()) {
		int weight = pq.top().first;
		int curr = pq.top().second; pq.pop();
		if (dist[curr] < weight)continue;
		for (int i = 0; i<v[curr].size(); i++)
			if (dist[v[curr][i].first] > dist[curr] + v[curr][i].second) {
				dist[v[curr][i].first] = dist[curr] + v[curr][i].second;
				pre[v[curr][i].first] = curr;
				pq.push({ dist[v[curr][i].first],v[curr][i].first });
			}
	}
	printf("%d\n", dist[des]);
	stack<int> s;
	int k = des;
	while (k !=src) {
		s.push(k);
		k = pre[k];
	}
	printf("%d\n", s.size()+1);
	printf("%d ", src);
	while (!s.empty())
		printf("%d ", s.top()), s.pop();
	return 0;
}