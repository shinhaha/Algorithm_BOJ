#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <stdlib.h>
using namespace std;
int main() {
	while (1) {
		int a, b, c, d; scanf("%d %d %d %d", &a, &b, &c, &d);
		if (!a && !b && !c && !d)return 0;
		printf("%d %d\n", c - b, d - a);
	}
}
