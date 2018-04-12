#include <stdio.h>
#include <string.h>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int n, m, x, y, k;
int map[21][21];
struct dice {
	int u, b, r, l, f, d;
};

typedef struct dice DICE;
DICE* d = new DICE({ 0,0,0,0,0,0 });
void swap(int flag)
{
	int dummy = 0;

	if (flag == 1)
	{
		dummy = d->u;
		d->u = d->b;
		d->b = d->d;
		d->d = d->f;
		d->f = dummy;
	}
	else if (flag == 2)
	{
		dummy = d->u;
		d->u = d->f;
		d->f = d->d;
		d->d = d->b;
		d->b = dummy;
	}
	else if (flag == 3)
	{
		dummy = d->u;
		d->u = d->r;
		d->r = d->d;
		d->d = d->l;
		d->l = dummy;
	}
	else if (flag == 4)
	{
		dummy = d->u;
		d->u = d->l;
		d->l = d->d;
		d->d = d->r;
		d->r = dummy;
	}
}
void move(int opt) {
	if (opt == 1) {
		if (y + 1<m) {
			y++;
			swap(opt);
			if (map[x][y] == 0)
				map[x][y] = d->d;
			else {
				d->d = map[x][y];
				map[x][y] = 0;
			}
			printf("%d\n", d->u);
		}
	}
	if (opt == 2) {
		if (y - 1 >= 0) {
			y--;
			swap(opt);
			if (map[x][y] == 0) {
				map[x][y] = d->d;
			}
			else {
				d->d = map[x][y];
				map[x][y] = 0;
			}
			printf("%d\n", d->u);
		}
	}
	if (opt == 3) {
		if (x - 1 >= 0) {
			x--;
			swap(opt);
			if (map[x][y] == 0) {
				map[x][y] = d->d;
			}
			else {
				d->d = map[x][y];
				map[x][y] = 0;
			}
			printf("%d\n", d->u);
		}
	}
	if (opt == 4) {
		if (x + 1<n) {
			x++;
			swap(opt);
			if (map[x][y] == 0)
				map[x][y] = d->d;
			else {
				d->d = map[x][y];
				map[x][y] = 0;
			}
			printf("%d\n", d->u);
		}
	}
}

int main() {
	scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &map[i][j]);

	for (int i = 0; i < k; i++) {
		int opt; scanf("%d", &opt);
		move(opt);
		//µ¿1 ¼­2 ºÏ3 ³²4
	}
	return 0;
}