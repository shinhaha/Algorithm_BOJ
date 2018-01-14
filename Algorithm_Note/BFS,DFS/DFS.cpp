//BOJ 1012
#include<stdio.h>
using namespace std;
int** Table;
int m, n;

void DFS(int i, int j) {
	int nx[] = { -1,1,0,0 };//»óÇÏÁÂ¿ì
	int ny[] = { 0,0,-1,1 };
	for (int q = 0; q < 4; q++) {
		int finx = i + nx[q];
		int finy = j + ny[q];
		if (finx >= 0 && finx < m&&finy >= 0 && finy < n&&Table[finx][finy] == 1){
			Table[finx][finy] = 0;//visit
			DFS(finx, finy);
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
					DFS(i, j);
					count++;
				}
		printf("%d\n", count);
	}
}