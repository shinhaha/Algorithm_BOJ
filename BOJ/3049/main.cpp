#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <string.h>
#include <stack>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	printf("%d", n*(n - 1)*(n - 2)*(n - 3) / 24);
}