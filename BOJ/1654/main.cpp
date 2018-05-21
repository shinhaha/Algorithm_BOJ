#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
using namespace std;
int k, n;
typedef long long ll;
vector<ll> v;


ll f(ll curr){
	ll c = 0;
	for (int i = 0; i < k; i++)c += v[i] / curr;
	return c;
}

int main() {
	scanf("%d %d", &k, &n);
	for (int i = 0; i < k; i++) {
		ll input; scanf("%lld", &input);
		v.push_back(input);
	}

	ll lo = 0; ll hi = 10000000000;

	while (lo < hi) {
		ll mid = (lo + hi) / 2;
		if (f(mid)>=n)lo=mid+1;
		else hi=mid;
	}
	printf("%lld",lo-1);
	return 0;
}