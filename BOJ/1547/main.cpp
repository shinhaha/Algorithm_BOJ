#include <cstdio>
int main() {
	int n; scanf("%d", &n);
	int ret = 1;
	for (int i = 0; i < n; i++) {
		int a, b; scanf("%d %d", &a, &b);
		if (a == ret)ret = b;
		else if (b == ret)ret = a;
	}
	printf("%d", ret);
}