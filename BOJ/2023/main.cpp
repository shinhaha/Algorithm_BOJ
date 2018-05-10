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
using namespace std;
int n;
bool isPrime(int n) {
	if (n == 1)return false;
	if (n == 2)return true;
	for (int i = 2; i*i <= n; i++)
		if (n%i == 0)return false;
	return true;
}

void proc(int x, int depth) {
	if (!isPrime(x))return;
	if (n == depth)printf("%d\n", x);
	else {
		proc(10 * x + 1, depth + 1);
		proc(10 * x + 3, depth + 1);
		proc(10 * x + 7, depth + 1);
		proc(10 * x + 9, depth + 1);
	}
}
int main() {
	scanf("%d", &n);
	proc(2, 1);
	proc(3, 1);
	proc(5, 1);
	proc(7, 1);
}