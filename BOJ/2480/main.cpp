#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
	int a, b, c; scanf("%d %d %d", &a, &b, &c);
	int flag = 0;
	if (a == b&&b == c)
		flag = 2;
	else if (b == c || a == b || a == c)
		flag = 1;
	if (flag == 2)
		printf("%d",a * 1000 + 10000);
	if (flag == 1)
		printf("%d",((a + b + c - (a^b^c)) / 2) * 100 + 1000);
	if (flag == 0)
		printf("%d",100 * (max(c,max(a, b))));
	return 0;
}
