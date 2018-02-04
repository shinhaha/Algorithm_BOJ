#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main() {

	int n, m; scanf("%d %d", &n, &m);

	int cache = 0;

	for (int i = 0; i < n; i++) {
		int input; scanf("%d", &input);
		cache += input;
		if (cache > m) {
			printf("%d", i);
			return 0;
		}
	}
	if (cache > m)
		printf("%d", n - 1);
	else printf("%d", n);



	return 0;
}