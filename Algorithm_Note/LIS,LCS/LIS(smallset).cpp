//boj 11053
#include<stdio.h>
#include<algorithm>
using namespace std;
int main() {
	int n; scanf("%d", &n);
	int* arr = new int[n]();
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	int* dp = new int[1001]();
	int ret = 0;
	for (int i = 0; i<n; i++) {
		dp[i] = 1;
		for (int j = 0; j <i; j++) {
			if (arr[i]>arr[j])
				dp[i] = max(dp[i],dp[j]+1);
		}
		ret = max(dp[i], ret);
	}
	printf("%d", ret);
}
