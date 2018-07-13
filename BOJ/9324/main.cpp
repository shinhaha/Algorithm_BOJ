#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <string.h>
#include <string>
using namespace std;
char buf[100001];
int alp[33];
int main() {
	int n; scanf("%d", &n);

	while (n--) {
		scanf("%s", buf);
		memset(alp, 0, sizeof(alp));
		int len = strlen(buf);
		bool flag = 1;
		for (int i = 0; i < len; i++) {
			int curr=(++alp[buf[i] - 'A']);
			if (!(curr % 3) && curr) {
				if (buf[i + 1] != buf[i])flag = 0;
				i++;
			}
            if(!flag)break;
		}
		if (flag)printf("OK\n");
		else printf("FAKE\n");
	}
	return 0;
}