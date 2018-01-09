#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
#define ver pair<int,int>
struct Edge {
	int dest;
	int weight;
};
#define edge struct Edge

int main() {
	int v, e; scanf("%d %d", &v, &e);
	bool* visit = new bool[v]();
	int* key = new int[v]();
	priority_queue<ver, vector<ver>, greater<ver>> pq;
	vector<edge>* Vec = new vector<edge>[v]();
	for (int i = 0; i < v; i++)key[i] = 2000000000;
	for (int i = 0; i < e; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		edge* tmp1 = new edge(); edge* tmp2 = new edge();
		tmp1->dest = b - 1; tmp2->dest = a - 1; tmp1->weight = c; tmp2->weight = c;
		Vec[a - 1].push_back(*tmp1); Vec[b - 1].push_back(*tmp2);
	}
	int sum = 0;
	int size = 0;
	key[0] = 0;
	pq.push(make_pair(0, 0));
	while (!pq.empty()) {
		int vertices = pq.top().second;//vertices
		pq.pop();
		if (visit[vertices])continue;
		visit[vertices] = true;
		sum += key[vertices];
		size++;
		if (size == v)break;
		for (int i = 0; i < Vec[vertices].size(); i++) {
			edge tmp = Vec[vertices][i];
			int dest = tmp.dest;
			int w = tmp.weight;
			if (!visit[dest] && key[dest] > w) {
				key[dest] = w;
				pq.push(make_pair(key[dest], dest));
			}
		}
	}
	printf("%d", sum);
}