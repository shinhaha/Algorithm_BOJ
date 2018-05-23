#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
using namespace std;
#define PI pair<int,int>
vector<PI> v[100001];
bool visit[100001] = { 0 };
PI dfs(PI curr) {
	PI ret = { curr.first,curr.second };
	for (int i = 0; i < v[curr.first].size(); i++) {
		if (!visit[v[curr.first][i].first]) {
			visit[v[curr.first][i].first] = true;
			PI tmp = dfs({ v[curr.first][i].first,curr.second + v[curr.first][i].second });
			if (ret.second <tmp.second)
				ret.first = tmp.first, ret.second = tmp.second;
		}
	}
	return ret;
}
int main() {
	int test; scanf("%d", &test);
	for (int t = 0; t<test; t++) {
		int ver; scanf("%d", &ver);
		int curr = true, dis = true;
		while (true) {
			scanf("%d", &curr); if (curr == -1)break;
			scanf("%d", &dis);
			v[ver].push_back({ curr,dis });
		}
	}
	visit[1] = true; PI a = dfs({ 1,0 });
	memset(visit, 0, sizeof(visit));
	visit[a.first] = true; PI b = dfs({ a.first,0 });
	printf("%d", b.second);
	return 0;
}