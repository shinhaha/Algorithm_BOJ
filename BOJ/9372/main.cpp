#include <stdio.h>
int test, a, b, n, m, i;
int main() {
	int test; scanf("%d", &test);
	while (test--) {
		scanf("%d %d", &n, &m);
		for (i = 0; i < m; i++)
			scanf("%d %d", &a, &b);
		printf("%d\n", n - 1);
	}
	return 0;
}