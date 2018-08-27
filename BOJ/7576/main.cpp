#include<stdio.h>
#include<queue>
using namespace std;
int arr[1001][1001];
#define PI pair<int,int>

int main() {
	queue<PI> q;
	int n, m; scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1) { q.push({ i,j }); }
		}

	// 입력 다 했고 토마토 좌표도 넣었다

	int ax[] = { 0,0,1,-1 };//동 서 남 북
	int ay[] = { 1,-1,0,0 };
	int day = -1;
	while (!q.empty()) {//큐가 빌때까지 한다.
		int qsize = q.size();//토마토 현재 몇개냐

		for (int qs = 0; qs<qsize; qs++) {//토마토 개수만큼
			int i = q.front().first;
			int j = q.front().second; q.pop();

			for (int x = 0; x < 4; x++) {
				int newi = i + ax[x];
				int newj = j + ay[x];//동서남북 움직였을때 위치
				if (newi < 0 || newi >= n || newj < 0 || newj >= m)continue;
				//존재하지 않는경우
				if (arr[newi][newj] == 0) {
					arr[newi][newj] = 1;//익혔다.
					q.push({ newi,newj });
				}
			}//상하좌우살피면서토마토익히는부분
		}
		day++;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0)day = -1;
		}

	printf("%d", day);
}