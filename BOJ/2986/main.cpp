#include <stdio.h>
#include <vector>
using namespace std;
int main() {
	int n; scanf("%d", &n);
	if (n <= 3)printf("%d", n - 1);
	else {
		for (int i = 2; i*i <= n; i++) {
			if (n%i == 0) {
				printf("%d", n - (n / i));
				return 0;
			}
		}
		printf("%d", n - 1);
	}
}