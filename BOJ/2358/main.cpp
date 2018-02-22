#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
map<ll, ll> x, y;
int main() {
	int n; scanf("%d", &n);
	for(int i=0; i<n; i++) {
		int a, b; scanf("%d %d", &a, &b);
		x[a]++;
		y[b]++;
	}
	ll ret = 0;
	for (auto i = x.begin(); i != x.end(); i++) {
		ll &n = i->second;
		if (n > 1) ret++;
	}
	for (auto i = y.begin(); i != y.end(); i++) {
		ll &n = i->second;
		if (n > 1) ret++;
	}
	printf("%lld", ret);
	return 0;
}