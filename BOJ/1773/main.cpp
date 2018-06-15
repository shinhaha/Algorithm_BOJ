#include <cstdio>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <cstdbool>
#include <stdbool.h>
using namespace std;

bool table[2000001];

int main() {
	memset(table, false, sizeof(table));
	int n, m; scanf("%d %d", &n, &m);
	int ret = 0;
	for (int i = 0; i < n; i++) {
		int input; scanf("%d", &input);
		for (int j = input; j <= m; j += input)
			table[j] = true;
	}
	for (int i = 1; i <= m; i++)
		ret += table[i];
	printf("%d\n", ret);

	return 0;
}