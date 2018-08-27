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

	// �Է� �� �߰� �丶�� ��ǥ�� �־���

	int ax[] = { 0,0,1,-1 };//�� �� �� ��
	int ay[] = { 1,-1,0,0 };
	int day = -1;
	while (!q.empty()) {//ť�� �������� �Ѵ�.
		int qsize = q.size();//�丶�� ���� ���

		for (int qs = 0; qs<qsize; qs++) {//�丶�� ������ŭ
			int i = q.front().first;
			int j = q.front().second; q.pop();

			for (int x = 0; x < 4; x++) {
				int newi = i + ax[x];
				int newj = j + ay[x];//�������� ���������� ��ġ
				if (newi < 0 || newi >= n || newj < 0 || newj >= m)continue;
				//�������� �ʴ°��
				if (arr[newi][newj] == 0) {
					arr[newi][newj] = 1;//������.
					q.push({ newi,newj });
				}
			}//�����¿���Ǹ鼭�丶�������ºκ�
		}
		day++;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0)day = -1;
		}

	printf("%d", day);
}