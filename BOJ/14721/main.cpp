#include <algorithm>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <functional>
#include <string>
using namespace std;
#define PI pair<long long,long long>
int n;
vector<PI> v;
long long sum(long long a,long long b) {
	long long ret = 0;
	for (int i = 0; i < n; i++)
		ret += (v[i].second - (a*v[i].first + b))*(v[i].second - (a*v[i].first + b));
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		long long a, b; scanf("%lld %lld", &a, &b);
		v.push_back({ a,b });
	}
	long long m = 123456789;
	int q=0, w=0;
	for(int i=1; i<=100; i++)
		for (int j = 1; j <= 100; j++) {
			long long s = sum((long long)i,(long long)j);
			if (s < m) {
				m = s;
				q = i;
				w = j;
			}
		}
	printf("%d %d", q, w);
	return 0;
}