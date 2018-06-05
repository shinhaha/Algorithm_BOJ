#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<queue>
using namespace std;
#define PI pair<int,int>

bool chk[2001][2001] = { 0 };

void recu_chk(int i, int j) {
	if (i > j)return;
	chk[i][j] = true;
	recu_chk(i + 1, j - 1);
}
int main() {
	vector<int> v;
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int input; scanf("%d", &input);
		v.push_back(input);
	}

	int k; scanf("%d", &k);

	while (k--) {

		int a, b; scanf("%d %d", &a, &b);
		if (a>b) {
			int tmp = b;
			b = a;
			a = tmp;
		}
		a--; b--;
		if (!chk[a][b]) {
			bool flag = 0;
			for (int i = 0; i <=(b-a)/2; i++) {
				if (v[a + i] != v[b - i])flag = 1;
				if (flag)break;
			}
			if (flag)printf("0\n");
			else recu_chk(a, b), printf("1\n");
		}
		else printf("1\n");
	}

	return 0;
}