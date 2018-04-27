#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	vector<int> v;
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int input; scanf("%d", &input);
		v.push_back(input);
	}
	int ret = 1e9, lo = 0, hi = n - 1;
	do {
		if (abs(ret) > abs(v[lo] + v[hi]))
			ret = v[lo] + v[hi];
		if (abs(v[lo] + v[hi]) >= abs(v[lo] + v[hi - 1])) 
			hi--;
		else if (hi + 1 < n && abs(v[lo] + v[hi]) > abs(v[lo] + v[hi + 1]))
			hi++;
		else
			lo++;
	} while (lo < hi);
	printf("%d", ret);
	
	return 0;
}