#define _CRT_SECURE_NO_WARNINGS // scanf(), gets() (needed for Visual C++)
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define MEMSET(x, WITH) memset(x, (WITH), sizeof(x))
#define FOR(i, E) for(int i=0; i<(E); i++)
#define REP(i, LO, HI) for(int i=(LO); i<=(HI); i++)
#define SORT(v) sort(v.begin(),v.end())
#define PI pair<int,int>
typedef long long ll;

int parent[10000001];

int find(int i) {
	if (parent[i] < 0)return i;
	return parent[i] = find(parent[i]);
}
void unite(int i, int j) {
	int x = find(i);
	int y = find(j);
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
	MEMSET(parent, -1);
	int n, m; scanf("%d %d", &n, &m);
	while (m--) {
		int q, w, e; scanf("%d %d %d", &q, &w, &e);
		if (!q) {
			if (find(w) != find(e))
				unite(w, e);
		}
		else {
			if (find(w) == find(e))printf("YES\n");
			else printf("NO\n");
		}
	}

}