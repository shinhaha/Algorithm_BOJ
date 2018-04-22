#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
	int test = 3; vector<ll> v;
	while (test--) {
		v.clear();
		int n; scanf("%d", &n);
		while (n--) {
			ll input; scanf("%lld", &input);
			v.push_back(input);
		}
		sort(v.begin(), v.end());
		ll sum = 0; int p = 0; int q = v.size() - 1;
		while (p <= q) {
			if (sum >= 0 && v[p] >= 0) {
				sum += v[p];
				break;
			}
			if (sum < 0 && v[q] <= 0)
				break;
			if (q<0 || p>v.size() - 1)break;
			if (sum < 0) {
				sum += v[q];
				q--;
			}
			else {
				sum += v[p];
				p++;
			}
		}
		if (sum > 0)printf("+\n");
		else if (!sum)printf("0\n");
		else printf("-\n");
	}
}