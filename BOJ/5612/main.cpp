#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n,m; scanf("%d %d", &n,&m);
	int ret = m;
	for (int i = 0; i < n; i++) {
		int a, b; scanf("%d %d", &a, &b);
		m = m + a - b;
		ret = max(ret,m);
		if (m < 0) {
			printf("0"); return 0;
		}	
	}
	printf("%d", ret);
	return 0;
}
