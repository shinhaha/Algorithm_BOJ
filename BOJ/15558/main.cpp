#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <string.h>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;
struct a {
	int i, j, time;
};
#define A struct a
char buf[2][200002];
bool visit[2][200002] = { 0 };
int main() {
	int n, k; scanf("%d %d", &n, &k);
	scanf("%s %s", buf[0], buf[1]);
	queue<a> q;
	q.push({ 0,0,0 });
	int time = 0;
	while (!q.empty()) {
		int qsize = q.size();
		for (int x = 0; x < qsize; x++) {
			int i = q.front().i;
			int j = q.front().j;
			int t = q.front().time;
			q.pop();
			if (!visit[i][j + 1]&&buf[i][j+1]=='1') {
				visit[i][j + 1] = true;
				q.push({ i,j + 1,t + 1 });
				if (j + 1 >=n) {
					printf("1");
					return 0;
				}
			}
			if (!visit[i][j - 1] &&time<j-1&&buf[i][j-1]=='1') {
				visit[i][j - 1] = true;
				q.push({ i,j - 1,t + 1 });
			}
			if (j + k >=n) {
				printf("1");
				return 0;
			}
			if (j + k < strlen(buf[1]) && !visit[(i + 1) % 2][j + k]&&buf[(i+1)%2][j+k]=='1') {
				visit[(i + 1) % 2][j + k] = true;
				q.push({ (i + 1) % 2,j + k,t + 1 });	
			}
		}
		time++;
	}
	printf("0");
	return 0;
}