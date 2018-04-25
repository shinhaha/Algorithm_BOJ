#include <stdio.h>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

priority_queue<int, vector<int>, greater<int>> q;

void rec(int n) {
	bool flag = false;
	for (int i = 2; i < n; i++)
		if (n%i == 0) {
			rec(n / i);
			rec(i);
			flag = true;
			break;
		}
	if (n != 1 && !flag)q.push(n);
}

int main() {
	int N;
	scanf("%d", &N);
	rec(N);
	int e = q.size();
	for (int i = 0; i < e; i++) {
		printf("%d\n", q.top());
		q.pop();
	}

	return 0;
}