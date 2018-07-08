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
typedef long long ll;

int main() {
	int n; scanf("%d", &n);
	vector<int> v,lc,rc;
	for (int i = 0; i < n; i++) {
		int input; scanf("%d", &input);
		v.push_back(input);
		lc.push_back(0), rc.push_back(0);
	}
	int retl = 1; int retr = 1;

	int lm = v[0];  int rm = v[n - 1];
	for (int i = 1; i < n; i++) {
		if (lm < v[i])retl++, lm = v[i];
		if (rm < v[n - 1 - i])retr++,rm=v[n-1-i];
	}

	printf("%d\n%d", retl, retr);

	return 0;


}