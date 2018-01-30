//boj 11375
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
typedef unsigned long long ll;

vector<int> G[1001];
char visit[1001];
int match[1001];
int n, m;


int dfs(int here) {
	if (visit[here])return 0;
	visit[here] = true;
	for (int i = 0; i < G[here].size(); i++) {
		int there = G[here][i];
		if (!match[there] || dfs(match[there])) {
			match[there] = here;
			return 1;
		}
	}
	return 0;
}

int max_flow() {
	int flow = 0;
	for (int i = 1; i <= n; i++) {
		memset(visit, false, sizeof(visit));
		if (dfs(i))flow++;
	}
	return flow;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int v, x;
		scanf("%d", &v);
		while (v--) {
			scanf("%d", &x);
			G[i].push_back(x);
		}
	}
	printf("%d", max_flow());

	return 0;

}