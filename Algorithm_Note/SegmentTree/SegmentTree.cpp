//boj 14648
#include <stdio.h>
int N, n, m;
typedef long long ll;
ll dat[4000000];

void init(int n_) {
	N = 1;
	while (N < n_)N *= 2;
	for(int i=0; i<2*N; i++)dat[i] = 0;
}

void update(int x, int a) {
	x += N - 1;
	dat[x] = a;
	while (x > 0) {
		x = (x - 1) / 2;
		dat[x] = dat[x * 2 + 1] + dat[x * 2 + 2];
	}
}

ll query(int a, int b, ll x, int l, int r) {
	if (r <= a || b <= l)return 0;
	if (a <= l&&r <= b)return dat[x];
	else {
		ll vl = query(a, b, x * 2 + 1, l, (l + r) / 2);
		ll vr = query(a, b, x * 2 + 2, (l + r) / 2, r);
		return vl+vr;
	}
}

int main() {
	scanf("%d %d", &n, &m);
	init(n);
	for(int i=0; i<n; i++){
		int input; scanf("%d", &input);
		update(i, input);
	}
	for(int i=0; i<m; i++){
		int a, b, c, d, e; 
		scanf("%d", &a);
		if (a == 1) {
			scanf("%d %d", &b, &c);
			printf("%lld\n", query(b - 1, c, 0, 0, N));
			ll tmp = query(b - 1, b, 0, 0, N);
			update(b - 1, query(c - 1, c, 0, 0, N)),update(c - 1, tmp);
		}
		if (a == 2) {
			scanf("%d %d %d %d", &b, &c, &d, &e);
			printf("%lld\n", query(b - 1, c, 0, 0, N) - query(d - 1, e, 0, 0, N));
		}
	}

	return 0;
}