#include <stdio.h>
#include <stdlib.h>
int s[2][10];
int main() {
	bool flag = false;
	for (int i = 0; i < 9; i++)
		scanf("%d", &s[0][i]);
	for (int i = 0; i < 9; i++)
		scanf("%d", &s[1][i]);
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		sum += s[0][i];
		if (sum > 0)flag = true;
		if (flag)break;
		sum -= s[1][i];
	}
	if (flag)printf("Yes");
	else printf("No");
}