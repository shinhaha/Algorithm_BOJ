//BOJ 1012
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
#define PI pair<int,int>//x,y
int** Table;
int m, n;

void BFS(int i, int j) {
	queue<PI> q;
	int nx[] = { -1,1,0,0 };//»óÇÏÁÂ¿ì
	int ny[] = { 0,0,-1,1 };
	q.push({ i,j });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second; q.pop();
		for (int i = 0; i < 4; i++) {
			int finx = x + nx[i];
			int finy = y + ny[i];
			if (finx >= 0 && finx < m&&finy >= 0 && finy < n&&Table[finx][finy] == 1){
				Table[finx][finy] = 0;//visit
				q.push({ finx,finy });
			}
		}
	}
}

int main() {
	int TestCase; scanf("%d", &TestCase);
	for (int t = 0; t < TestCase; t++) {
		int k;
		scanf("%d %d %d", &m, &n, &k);
		Table = new int*[m]();
		for (int i = 0; i < m; i++)
			Table[i] = new int[n];
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				Table[i][j] = 0;
		for (int i = 0; i < k; i++) {
			int x, y; scanf("%d %d", &x, &y);
			Table[x][y] = 1;
		}
		int count = 0;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (Table[i][j]) {
					BFS(i, j);
					count++;
				}
		printf("%d\n", count);
	}
}