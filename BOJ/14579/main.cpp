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
using namespace std;
#define MEMSET(x, WITH) memset(x, (WITH), sizeof(x))
#define FOR(i, E) for(int i=0; i<(E); i++)
#define REP(i, LO, HI) for(int i=(LO); i<=(HI); i++)
#define SORT(v) sort(v.begin(),v.end())
#define PI pair<int,int>
typedef long long ll;

#define MOD 14579

ll dp[1001];

int main() {
	int a, b; scanf("%d %d", &a, &b);
	//printf("%lld\n", 1000 * 1001 / 2);
	for (int i = a; i <= b; i++) {
		dp[i] = ((i*(i + 1)) / 2) % MOD;
		if (dp[i] % MOD == 0) {
			printf("0"); return 0;
		}
	}
	ll ret = 1;
	for (int i = a; i <= b; i++) {
		ret *= dp[i];
		ret %= MOD;
	}
	printf("%lld", ret%MOD);
}