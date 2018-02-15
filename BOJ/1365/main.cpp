#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	vector<int> v;
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int input; scanf("%d", &input);
		auto it = lower_bound(v.begin(), v.end(), input);
		if (it == v.end())v.push_back(input);
		else *it = input;
	}
	printf("%d", n - v.size());
	return 0;
}
