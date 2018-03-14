#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <stdlib.h>
using namespace std;
int main() {
	int a, b; scanf("%d %d", &a, &b);
	if (a <= 2) {
		if (a == 2 && b == 18)
			printf("Special");
		else if (a == 2 && b>18)printf("After");
		else printf("Before");
		return 0;
	}
	else printf("After");
}