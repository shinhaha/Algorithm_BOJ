#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	vector<int> v;
	for (int i = 0; i < 3; i++) {
		int tmp; scanf("%d", &tmp);
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	printf("%d", max(v[2] - v[1] - 1, v[1] - v[0] - 1));
}