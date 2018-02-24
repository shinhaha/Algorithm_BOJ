#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	int a, b, c, d, e; scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	int ret = min(min(a, b), c) + min(c, d) - 50;
	printf("%d", ret);
}