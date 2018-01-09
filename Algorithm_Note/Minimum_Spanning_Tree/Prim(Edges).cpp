#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
#define ver pair<int,int>//dest,Edgeweight;
#define edge pair<int,int>//EdgeWeight,dest;
int main() {
	int v, e; scanf("%d %d", &v, &e);
	bool* visit = new bool[v]();
	priority_queue<edge, vector<edge>, greater<edge> > pq;
	vector<ver>* Vec = new vector<ver>[v]();
	for (int i = 0; i < e; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		Vec[a - 1].push_back(make_pair(b - 1, c)); Vec[b - 1].push_back(make_pair(a - 1, c));
	}
	int ret = 0; int size = 0; int src = 0;
	visit[src] = true;

	for (int i = 0; i < Vec[src].size(); i++)
		pq.push(make_pair(Vec[src][i].second, Vec[src][i].first));

	while (!pq.empty()) {
		int weight = pq.top().first;//EdgeWeight
		int vertices = pq.top().second;//dest
		pq.pop();
		if (visit[vertices])continue;
		visit[vertices] = true;
		ret += weight;
		size++; if (size == v - 1)break;
		for (int i = 0; i < Vec[vertices].size(); i++) {
			int dest = Vec[vertices][i].first;
			int Edgeweight = Vec[vertices][i].second;
			if (!visit[dest])
				pq.push(make_pair(Edgeweight, dest));
		}
	}
	printf("%d", ret);
}