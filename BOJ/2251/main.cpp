#include <cstdio>
#include <vector>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;
bool visit[201][201][201] = { 0 };
bool chk[201] = { 0 };
int x, y, z;
void bfs(int a, int b, int c) {
	if (!visit[a][b][c]) {
		if(a==0)chk[c] = true;
		visit[a][b][c] = true;
		bfs(a + c > x ? x : a + c, b, a + c > x ? a + c - x : 0);//c a
		bfs(a, b + c > y ? y : b + c, b + c > y ? b + c - y : 0);//c b
		bfs(a + b > x ? x : a + b, a + b > x ? a + b - x : 0, c);//b a
		bfs(a, b + c > z ? b + c - z : 0, b + c > z ? z : b + c);//b c
		bfs(a + b > y ? a + b - y : 0, a + b > y ? y : a + b, c);//a b
		bfs(a + c > z ? a + c - z : 0, b, a + c > z ? z : a + c);//a c
	}
}

int main() {
	scanf("%d %d %d", &x, &y, &z);
	bfs(0, 0, z);
	for (int i = 0; i <= 200; i++)
		if (chk[i])printf("%d ", i);
	return 0;
}