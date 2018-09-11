#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
#include<vector>
#define PI pair<int,int>
using namespace std;

int n, k;
int ans = -1;
int rem = 0;
int visit[100001];
void bakok2(int start) {
	queue<PI> q;
	q.push({ start, 0 });
	visit[start] = true;
	while (!q.empty()) {
	int	a = q.front().first;
	int	c = q.front().second;
	q.pop();
	if (a - 1 >= 0&&c+1<=visit[a-1]) {
		q.push({ a - 1, c + 1 });
		visit[a - 1] = c+1;
	}
	if (a + 1 <= 100000&&c+1<=visit[a+1]) {
		q.push({ a + 1,c + 1 });
		visit[a + 1] = c + 1;
	}
	if (a * 2 <= 100000&&c+1<=visit[a*2]) {
		q.push({ a * 2, c + 1 });
		visit[a * 2] = c + 1;
	}
	if (a == k) { //a와 k가 같을 경우 도착했다고 판단
		if (ans == -1)
			ans = c;
		if (ans == c)
			rem++;
		}
	}
}

int main(int) {
	fill(visit, visit + 100001, 1e9);
	scanf("%d %d", &n, &k);
	bakok2(n);
	printf("%d\n", ans); //결과 c 출력      
	printf("%d\n", rem);
}