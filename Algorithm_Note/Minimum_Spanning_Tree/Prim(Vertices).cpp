#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
#define ver pair<int,int>//Verweight,source;
#define edge pair<int,int>//dest,Edgeweight;
#define INF 1e9
int main() {
	int v, e; scanf("%d %d", &v, &e);
	bool* visit = new bool[v]();
	int* key = new int[v]();
	priority_queue<ver, vector<ver>, greater<ver> > pq;
	vector<edge>* Vec = new vector<edge>[v]();
	for (int i = 0; i < v; i++) {
		visit[i] = false; key[i] = INF;
	}
	for (int i = 0; i < e; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		Vec[a - 1].push_back(make_pair(b - 1, c)); Vec[b - 1].push_back(make_pair(a - 1, c));
	}
	int ret = 0; int size = 0; int src = 0; key[0] = 0;
	pq.push(make_pair(0,src));//weight,source
	while (!pq.empty()) {
		int weight = pq.top().first;//VerWeight
		int vertices = pq.top().second;//source
		pq.pop();
		if (visit[vertices])continue;
		visit[vertices] = true;
		ret += weight;
		size++; if (size == v)break;
		for (int i = 0; i < Vec[vertices].size(); i++) {
			int dest = Vec[vertices][i].first;
			int Edgeweight = Vec[vertices][i].second;
			if (!visit[dest] && key[dest] > Edgeweight) {
				key[dest] = Edgeweight;
				pq.push(make_pair(Edgeweight, dest));
			}
		}
	}
	printf("%d", ret);
}