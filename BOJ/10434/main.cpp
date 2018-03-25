#define _CRT_SECURE_NO_WARNINGS // scanf(), gets() (needed for Visual C++)
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <queue>
#include <stack>

bool p[10001] = { 0 };
bool chk[10002];
int main() {
	p[0] = p[1] = true;//false°¡ ¼Ò¼ö
	for (int i = 2; i <= 5000; i++)
		for (int j = 2*i; j <= 10000; j += i)
			p[j] = true;
	int t; scanf("%d", &t);
	while (t--) {
		int num, input; scanf("%d %d", &num, &input);
		if (p[input]) {
			printf("%d %d NO\n", num, input);
			continue;
		}
		memset(chk, 0, sizeof(chk));
		int org = input;
		while (!chk[input]&&input!=1) {
			int tmp = 0;
			chk[input] = true;
			while (input > 0) {
				tmp += (input % 10)*(input%10);
				input/= 10;
			}
			input = tmp;
		}
		if (input == 1)
			printf("%d %d YES\n", num, org);
		else printf("%d %d NO\n", num, org);
	}
}