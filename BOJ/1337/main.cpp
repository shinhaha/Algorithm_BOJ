#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
#include <functional>
using namespace std;
int main() {
	int n; scanf("%d", &n);
	vector<int> v;
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 0; i < n; i++) {
		int input; scanf("%d", &input);
		q.push(input);
	}
	int size = 0;
	int ret = 4;
	while (!q.empty()) {
		int curr = q.top(); q.pop();
		v.push_back(curr);
		int size = v.size();

		if (v[size - 1] - v[0] <= 4) {
			int ans = 5 - size;
			ans = ans <= 0 ? 0 : ans; ret = min(ans, ret);
		}
		else v.erase(v.begin());
	}
	printf("%d", ret);
	return 0;
}