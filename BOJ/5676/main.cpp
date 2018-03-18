#include <stdio.h>
int N, n, m;
typedef int ll;
ll dat[400000];

void init(int n_) {
	N = 1;
	while (N < n_)N *= 2;
	for (int i = 0; i<2 * N; i++)dat[i] = 1;
}

void update(int x, int a) {
	x += N - 1;
	dat[x] = a;
	while (x > 0) {
		x = (x - 1) / 2;
		dat[x] = dat[x * 2 + 1] * dat[x * 2 + 2];
	}
}

ll query(int a, int b, ll x, int l, int r) {
	if (r <= a || b <= l)return 1;
	if (a <= l&&r <= b)return dat[x];
	else {
		ll vl = query(a, b, x * 2 + 1, l, (l + r) / 2);
		ll vr = query(a, b, x * 2 + 2, (l + r) / 2, r);
		return vl*vr;
	}
}

int main() {

	while (scanf("%d %d", &n, &m) == 2) {
		init(n);
		for (int i = 0; i<n; i++) {
			int input; scanf("%d", &input);
			if (input > 0)input = 1;
			else if (input < 0)input = -1;
			update(i, input);
		}

		for (int i = 0; i < m; i++) {
			char opt; int a, b;
			scanf(" %c %d %d", &opt, &a, &b);
			if (opt == 'C') {
				if (b > 0)b = 1;
				else if (b < 0)b = -1;
				update(a - 1, b);
			}
			else if (opt == 'P') {
				ll ret = query(a - 1, b, 0, 0, N);
				if (ret > 0)printf("+");
				else if (ret < 0)printf("-");
				else if (!ret)printf("0");
			}
		}

		printf("\n");

	}
	return 0;
}