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
#define MEMSET(x, WITH) memset(x, (WITH), sizeof(x))
#define FOR(i, E) for(int i=0; i<(E); i++)
#define REP(i, LO, HI) for(int i=(LO); i<=(HI); i++)
#define SORT(v) sort(v.begin(),v.end())
#define PI pair<int,char*>
typedef long long ll;

int main() {
	int test; scanf("%d", &test);
	while (test--) {
		ll sum = 0;
		int n; scanf("%d", &n);
		while (n--) {
			int input; scanf("%d", &input);
			sum += input;
		}
		printf("%lld\n", sum);
	}
}