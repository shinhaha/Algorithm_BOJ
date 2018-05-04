#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int main() {
	int n; scanf("%d", &n);
	vector<int> v;
	while (n--) {
		int input; scanf("%d", &input);
		auto iter = lower_bound(v.begin(), v.end(), input);
		if (iter == v.end())v.push_back(input);
		else *iter = input;
	}
	printf("%d", v.size());
}