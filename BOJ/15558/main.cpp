#include <cstdio>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;
struct a {
	int i, j;
};
#define A struct a
char buf[2][100005];
bool visit[2][100005] = { 0 };
int main() {
	queue<a> q;
	int n, k; scanf("%d %d", &n, &k);
	scanf("%s %s", buf[0],buf[1]);
	q.push({0,0});
	int time = 0;
	while (!q.empty()) {
		int qsize = q.size();
		for (int x = 0; x < qsize; x++) {
			int i = q.front().i;
			int j = q.front().j; q.pop();
			if (j+k>= n||j+1>=n) {
				printf("1");
				return 0;
			}
			if (!visit[i][j + 1]&&buf[i][j+1]=='1') {
				visit[i][j + 1] = true;
				q.push({ i,j + 1});
			}
			if (!visit[i][j - 1] &&time<j-1&&buf[i][j-1]=='1') {
				visit[i][j - 1] = true;
				q.push({ i,j - 1});
			}
			if (j + k < strlen(buf[1]) && !visit[(i + 1) % 2][j + k]&&buf[(i+1)%2][j+k]=='1') {
				visit[(i + 1) % 2][j + k] = true;
				q.push({ (i + 1) % 2,j + k});	
			}
		}
		time++;
	}
	printf("0");
	return 0;
}