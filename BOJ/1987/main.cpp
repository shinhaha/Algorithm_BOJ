#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <queue>
using namespace std;
char map[21][21];
int chk[30] = { 0 };
int ret = 0;
int n, m;
int ax[] = { 0,0,1,-1 };
int ay[] = { 1,-1,0,0 };
void proc(int x, int y, int c) {
	ret = max(ret, c);
	for (int q = 0; q < 4; q++) {
		int finx = x + ax[q];
		int finy = y + ay[q];
		if (finx >= 0 && finx < n&&finy >= 0 && finy < m && !chk[map[finx][finy] - 'A']) {
			chk[map[finx][finy] - 'A'] = 1;
			proc(finx, finy, c + 1);
			chk[map[finx][finy] - 'A'] = 0;
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", map[i]);
	chk[map[0][0] - 'A'] = 1;
	proc(0, 0, 1);
	printf("%d", ret);
}