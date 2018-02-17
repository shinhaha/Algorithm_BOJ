//boj 2512
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<ll> v;

ll proc(int k) {
	ll ret = 0;
	for (int i = 0; i < v.size(); i++)
		if (v[i] > k)ret += k;
		else ret += v[i];
		return ret;
}
int main() {
	int n; scanf("%d", &n);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		ll input; scanf("%lld", &input);
		v.push_back(input);
		sum += input;
	}
	ll limit; scanf("%lld", &limit);

	if (limit >= sum) {
		printf("%lld", *max_element(v.begin(), v.end()));
		return 0;
	}

	int lo = 0; int hi = *max_element(v.begin(), v.end());

	while (lo<hi) {
		int mid = (lo + hi) / 2;
		ll f = proc(mid);
		if (f <= limit)
			lo = mid + 1;
		else hi = mid;
	}

	printf("%d", lo - 1);

	return 0;
}
