/* boj 1238

N개의 숫자로 구분된 각각의 마을에 한 명의 학생이 살고 있다.

어느 날 이 N명의 학생이 X (1 ≤ X ≤ N)번 마을에 모여서 파티를 벌이기로 했다.

이 마을 사이에는 총 M개의 단방향 도로들이 있고 i번째 길을 지나는데 Ti(1 ≤ Ti ≤ 100)의 시간을 소비한다.

각각의 학생들은 파티에 참석하기 위해 걸어가서 다시 그들의 마을로 돌아와야 한다. 

하지만 이 학생들은 워낙 게을러서 최단 시간에 오고 가기를 원한다.

이 도로들은 단방향이기 때문에 아마 그들이 오고 가는 길이 다를지도 모른다. 

N명의 학생들 중 오고 가는데 가장 많은 시간을 소비하는 학생은 누구일지 구하여라.

---------------------------------------------------------------------------------------------------------------------------

<<Solution>>

X번 마을에서 다른 마을로 가는 최단거리는 X번 마을을 source로 하여 다익스트라 알고리즘을 사용하여 얻어낼 수 있다.

하지만, 어느 마을 U에서 X로 오는 최단거리는 U1, U2, U3... Un-1을 source로 각 정점마다 다익스트라 알고리즘을 돌려야 할까?

그렇지 않다. Edge의 방향을 반대로 바꾼 뒤에 X번 마을을 source로 하여 다익스트라 알고리즘을 사용하면

다른 마을에서 X번 마을로 오는 최단거리를 구해낼 수 있다.

간단한 예를 통해 수학적 귀납법을 사용한다면,

임의의 두 점 U,X에 대한 최단경로 P에 대해 X1이 P에 속하고 X1과 X가 이웃하다고 가정했을 때,

Edge의 방향을 반대로 하면 X->X1은 최단경로가 된다. 이러한 방식을 확장해서 반복한다.

이 문제는 플로이드-워셜 알고리즘으로도 해결할 수 있지만 플로이드-워셜 알고리즘은 O(v^3)으로 무거운 알고리즘이다.

그러므로 피할 수 있다면 피해야 하고 위와 같이 다익스트라 알고리즘을 2번 사용하는 방법으로 O(|E|logV) 만에 해결할 수 있다.

*/

#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
#define Vertice pair<int,int>//weight,vertice
#define Edge pair<int,int>//dest,weight
#define INF 1e9

int main() {
	int V, E,src; scanf("%d %d %d", &V, &E,&src);
	priority_queue<Vertice, vector<Vertice>, greater<Vertice>> pq;
	vector<Edge>* v = new vector<Edge>[V + 1]();//Edge vector
	vector<Edge>* _v = new vector<Edge>[V + 1]();//Swap Edge vector
	int* dist = new int[V + 1](); fill(dist, dist + V + 1, INF);
	vector<int> party; int ret = -1;

	for (int i = 0; i < E; i++) {
		int from, to, weight; scanf("%d %d %d", &from, &to, &weight);
		v[from].push_back({ to,weight }),_v[to].push_back({ from,weight });
	}

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

	for (int i = 1; i <= V; i++)
		party.push_back(dist[i]),v[i].clear();

	fill(dist, dist + V + 1, INF);

	dist[src] = 0;	pq.push({ dist[src],src });
	while (!pq.empty()) {
		int weight = pq.top().first;
		int curr = pq.top().second; pq.pop();
		if (dist[curr] < weight)continue;
		for (int i = 0; i<_v[curr].size(); i++)
			if (dist[_v[curr][i].first] > dist[curr] + _v[curr][i].second) {
				dist[_v[curr][i].first] = dist[curr] + _v[curr][i].second;
				pq.push({ dist[_v[curr][i].first],_v[curr][i].first });
			}
	}

	for (int i = 1; i <= V; i++) 
		_v[i].clear(),ret = max(ret, dist[i] + party[i - 1]);

	printf("%d", ret);
	
	return 0;
}