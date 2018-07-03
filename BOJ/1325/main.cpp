#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
#define PI pair<int,int>
using namespace std;

vector<int> com[10001];
bool visit[10001];
int c;

int f(int curr) {
	visit[curr] = true;
	c++;
	for (int i = 0; i < com[curr].size(); i++) {
		if (!visit[com[curr][i]])
			f(com[curr][i]);
	}
	return c;
}

int main() {
	int n, m; scanf("%d %d", &n, &m);
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);
		com[b].push_back(a);
	}
	vector<PI> ret;
	int rem = -1;
	for (int i = 1; i <= n; i++) {
		c = 0;
		memset(visit, false, sizeof(visit));
		int q = f(i); rem = max(rem, q);
		ret.push_back({ i,q });
	}
	for (int i = 0; i < ret.size(); i++)
		if (rem == ret[i].second)
			printf("%d ", ret[i].first);
}