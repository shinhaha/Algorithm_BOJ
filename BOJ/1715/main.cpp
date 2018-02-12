#include <stdio.h>
#include <queue>
#include <functional>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int main() {
	int n; scanf("%d", &n);
	while (n--) {
		int input; scanf("%d", &input);
		pq.push(input);
	}
	int ret = 0;
	while (pq.size() >= 2) {
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		ret += a + b;
		pq.push(a + b);
	}
	printf("%d", ret);
	return 0;
}