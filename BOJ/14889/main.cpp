#include <stdio.h>
#include <string.h>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#define PI pair<int,int>
int t, n;
int map[20][20];
vector<PI> v[20];
bool visit[20] = { 0 };
int ans = 1e10;
void chk() {
	int a = 0; int b = 0;
	for (int i = 0; i<n; i++)
		for (int j = i + 1; j < n; j++) {
			if (visit[i] && visit[j])a += map[i][j];
			else if (!visit[i] && !visit[j])b += map[i][j];
		}
	ans = min(ans, abs(a - b));
}
void proc(int c, int depth) {
	if (c == n / 2)
		chk();
	else
		for (int i = depth + 1; i < n; i++) {
			visit[i] = true;
			proc(c + 1, i);
			visit[i] = false;
		}
}

int main() {

	scanf("%d", &n);
	ans = 1e10;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			map[i][j] = 0;
			int input; scanf("%d", &input);
			if (i <= j)map[i][j] += input;
			else map[j][i] += input;
		}

	proc(0, 0);

	printf("%d", ans);
	return 0;
}