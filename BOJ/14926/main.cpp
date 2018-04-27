#include <stdio.h>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
int n;
bool visit[502][502] = { 0 };
int c[502];

bool chk(int a,int b) {//다 돌았냐
	for (int i = 1; i <= n; i++)
		if (i == a||i==b)continue;
	else if (c[i])return false;
	return true;
}
int main() {
	scanf("%d", &n);
	if (n == 1) {
		printf("a1 "); return 0;
	}
	fill(c, c + 502, n-1);
	printf("a1 a2 ");
	visit[1][2] = visit[2][1] = 1;
	c[1]--; c[2]--;
	int curr = 2;
	int i = 1;
	for (; i<=n;) {
		if ((!visit[curr][i] && curr != i&&c[i]>1)&&(!chk(curr,i))) {
			visit[curr][i] = visit[i][curr] = 1;
			c[curr]--; c[i]--;
			printf("a%d ", i);
			curr = i;
			i = 1;
		}
		else i++;
	}
	printf("a1 ");
	return 0;
}