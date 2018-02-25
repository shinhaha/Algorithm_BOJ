#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;
double dp[10001];
int main() {
	vector<double> v;
	int n; scanf("%d", &n);
	while (n--) {
		double input; scanf("%lf", &input);
		v.push_back(input);
	}
	n = v.size();
	dp[0] = v[0];
	double ret = dp[0];
	for (int i = 0; i < n - 1; i++) {
		dp[i + 1] = max(dp[i], 1.0)*v[i + 1];
		ret = max(ret, dp[i + 1]);
	}
	printf("%.3lf", ret);

	return 0;
}