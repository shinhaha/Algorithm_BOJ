//boj 1753
#include <cstdio>
#include <vector>
using namespace std;
#define PI pair<int,int>//dest,weight
#define INF 123456789

int main() {
	int V, E; scanf("%d %d", &V, &E);
	int* dist = new int[V+1]();
	vector<PI>* v = new vector<PI>[V+1]();
	int start; scanf("%d", &start);
	for (int i = 1; i <= V; i++)
		dist[i] = INF;
	for (int i = 0; i < E; i++) {
		int q ,w, e; scanf("%d %d %d", &q, &w, &e);
		v[q].push_back({ w,e });
	}
	dist[start] = 0;
	for (int i = 0; i < V - 1; i++)
		for (int j = 1; j <= V; j++)
			for (int k = 0; k < v[j].size(); k++)
				if (dist[v[j][k].first] > dist[j] + v[j][k].second)
					dist[v[j][k].first] = dist[j] + v[j][k].second;

	//for (int j = 1; j <= V; j++)
	//	for (int k = 0; k < v[j].size(); k++)
	//		if (dist[v[j][k].first] < dist[j] + v[j][k].second)
	//			printf("Negative cycle")

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF)printf("INF\n");
		else printf("%d\n", dist[i]);
	}

	return 0;
}