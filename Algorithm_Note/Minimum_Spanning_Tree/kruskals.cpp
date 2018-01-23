//boj 1197
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;

struct edge {
	int from, to, weight;
};
typedef struct edge Edge;

bool operator<(edge a,edge b) {
	return a.weight>b.weight;
}
priority_queue<edge> pq;
int parent[10001];

int CollapsingFind(int i) {
	if (parent[i] < 0)return i;
	return parent[i] = CollapsingFind(parent[i]);
}

void WeightedUnion(int i, int j) {
	int x = CollapsingFind(i);
	int y = CollapsingFind(j);
	if (parent[x] < parent[y]) {
		parent[x] += parent[y];
		parent[y] = x;
	}
	else {
		parent[y] += parent[x];
		parent[x] = y;
	}
}

int main() {
	memset(parent, -1, sizeof(parent));
	int V, E; scanf("%d %d", &V,&E);

	for (int i = 0; i < E; i++) {
		Edge* e = new Edge();
		scanf("%d %d %d", &e->from, &e->to, &e->weight);
		pq.push(*e);
	}

	int TreeSize = 0; int MinCost = 0;
	
	while (!pq.empty()) {
		Edge curr = pq.top(); pq.pop();
		if (CollapsingFind(curr.from) != CollapsingFind(curr.to))
			WeightedUnion(curr.from, curr.to),TreeSize++, MinCost += curr.weight;
		if (TreeSize == V - 1)break;
	}

	printf("%d", MinCost);
	
	return 0;
}