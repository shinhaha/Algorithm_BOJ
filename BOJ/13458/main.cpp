#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll n, b, c;
vector<ll> v;
ll ans = 0;

void proc() {
	for (int i = 0; i < v.size(); i++) {
		ll curr = v[i];
		if (curr - b <= 0) {
			ans++; continue;
		}
		else {
			curr -= b; ans++;
			ans += curr / c;
			curr = curr%c;
			if (curr)ans++;
		}
	}
}
int main()
{
	scanf("%lld", &n);

	for (int i = 0; i < n; i++) {
		ll input; scanf("%lld", &input);
		v.push_back(input);
	}
	scanf("%lld %lld", &b, &c);
	proc();
	printf("%lld", ans);
	return 0;
}