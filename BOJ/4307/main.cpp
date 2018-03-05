#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <string.h>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;

int main() {
	int test; scanf("%d", &test);
	while (test--) {
		int n, m; scanf("%d %d", &n, &m);
		int maxhi = -1; int maxlo = -1;
		for (int i = 0; i < m; i++) {
			int input; scanf("%d", &input);
			maxhi = max(maxhi, ((input >= (n / 2)) ? (n - input) : input));
			maxlo = max(maxlo, ((input >= (n / 2)) ? (input) : (n - input)));
		}
		printf("%d %d\n", maxhi, maxlo);
	}
	return 0;
}