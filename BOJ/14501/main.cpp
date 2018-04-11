#include <cstdio>
#include <vector>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
int n;
ll day[1500003] = { 0 };
ll money[1500003] = { 0 };
ll dp[1500003] = { 0 };
ll proc(int k) {
	if (k == n + 1)return 0;
	if (k >n + 1)return -1000000;
	if (dp[k])return dp[k];
	return dp[k] = max(proc(k + 1), proc(k + day[k]) + money[k]);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a, b; scanf("%d %d", &a, &b);
		day[i] = a;
		money[i] = b;
	}
	ll ret = proc(1);
	printf("%lld", ret);
	return 0;
}