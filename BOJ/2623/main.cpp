#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <queue>
using namespace std;
int indegree[1001] = { 0 };
vector<int> graph[1001];
char buf[3000];
vector<int> ans;
int n, k;
int flag = 0;
void bfs() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (!indegree[i]) {
			q.push(i);
			ans.push_back(i);
		}
	}
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int i = 0; i<graph[here].size(); i++) {
			int there = graph[here][i];
			if ((--indegree[there])<=0) {
				q.push(there);
				ans.push_back(there);
			}
		}
	}
}
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++) {
		int tmp; scanf("%d", &tmp);
		int a = -1; int b = -1;
		scanf("%d", &a);
		for(int j=0; j<tmp-1; j++){
			scanf("%d", &b);
		indegree[b]++;
		graph[a].push_back(b);
		a = b;
		}
	}
	bfs();
	if(ans.size()==n)
	for (auto it : ans)
		printf("%d\n", it);
	else printf("0");
	return 0;
}