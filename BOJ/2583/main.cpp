#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
int arr[501][501] = { 0 };
#define PI pair<int,int>

int num = 0;
vector<int> v;
int m, n, k;

void bfs(int i, int j) {
	queue<PI> q;
	num = 1;
	arr[i][j] = 1;
	q.push({ i, j });
	int ax[] = { 0,0,1,-1 };
	int ay[] = { 1,-1,0,0 };
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second; q.pop();
		for (int c = 0; c < 4; c++) {
			int newx = x + ax[c];
			int newy = y + ay[c];
			if (newx < 0 || newy < 0 || newx >= n || newy >= m)continue;
			if (arr[newx][newy] == 0) {
				arr[newx][newy] = 1;
				q.push({ newx,newy });
				num++;
			}
		}
	}
	v.push_back(num);
}

int main() {
	scanf("%d %d %d", &n, &m, &k);

	for (int x = 0; x < k; x++) {
		int x1, y1, x2, y2; scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (int i = min(n - y2, n - y1); i <max(n - y1, n - y2); i++)
			for (int j = min(x1, x2); j <max(x1, x2); j++)
				arr[i][j] = 1;
	}

	for (int i = 0; i<n; i++)
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0)
				bfs(i, j);
		}

	sort(v.begin(), v.end());
	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++)
		printf("%d ", v[i]);
}