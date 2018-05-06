#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
	vector<ll> v;
	ll ret = 0;
	ll sum = 0;
	ll n; scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		ll input; scanf("%lld", &input);
		sum += input;
		v.push_back(input);
	}
	sort(v.begin(), v.end());

	while (!v.empty()) {
		ll tmp = v[0];
		sum -= tmp;
		v.erase(v.begin());
		ret += 2 * (sum - v.size()*tmp);
	}

	printf("%lld", ret);

	return 0;
}
