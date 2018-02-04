#include <cstdio>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>
#include <functional>
using namespace std;

char buf[20];
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", buf);
		for (int j = 0; j <16; j++) {
			if (!(j % 2)) {
				int tmp = buf[j] - '0';
				tmp *= 2;
				if (tmp >= 10)
					tmp = 1 + tmp % 10;
				buf[j] = tmp + '0';
			}
		}
		int ret = 0;
		for (int i = 0; i <16; i++)
			ret += buf[i] - '0';

		if (ret % 10)printf("F\n");
		else printf("T\n");

	}

}