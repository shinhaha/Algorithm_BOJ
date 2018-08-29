#include <cstdio>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>
#include <functional>
#define PI pair<int,int>
using namespace std;
int n, m;
bool chk[100001];
int rem[100001];
vector<int> v;
int bfs(int start, int target) {
	queue<PI> q;
	q.push({ start,0 });

	while (!q.empty()) {
		int curr = q.front().first;
		int d = q.front().second; q.pop();
		if (curr == target) {
			for (int i = target; i != start; i = rem[i])v.push_back(i);
			v.push_back(start);
			return d;
		}

		if (curr + 1 <= 100000 && !chk[curr + 1]) {
			chk[curr + 1] = true;
			rem[curr + 1] = curr;
			q.push({ curr + 1,d + 1 });
		}
		if (curr - 1 >= 0 && !chk[curr - 1]) {
			rem[curr - 1] = curr;
			chk[curr - 1] = true;
			q.push({ curr - 1,d + 1 });
		}
		if (curr * 2 <= 100000 && !chk[curr * 2]) {
			rem[curr * 2] = curr;
			chk[curr * 2] = true;
			q.push({ curr * 2,d + 1 });
		}
	}
}
int main() {
	memset(chk, 0, sizeof(chk));
	scanf("%d %d", &n, &m);
	printf("%d\n", bfs(n, m));
	reverse(v.begin(), v.end());
	for (auto it : v)
		printf("%d ", it);
	return 0;
}