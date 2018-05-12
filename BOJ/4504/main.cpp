#include <stdio.h>

int main() {
	int input; scanf("%d", &input);
	while (1) {
		int n; scanf("%d", &n);
		if (!n)break;
		if (n%input)printf("%d is NOT a multiple of %d.\n", n, input);
		else printf("%d is a multiple of %d.\n", n, input);
	}
}