#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n; scanf("%d", &n);
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int input; scanf("%d", &input);
		auto iter = lower_bound(v.begin(), v.end(), input);
		if (iter == v.end())v.push_back(input);
		else *iter = input;
	}
	printf("%d", v.size());
}