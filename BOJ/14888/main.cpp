#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
vector<int> num, op;
int ans1 = -1e10 - (1e8);
int ans2 = 1e10 + 1e8;

int cal(int a, int operation, int b) {
	if (operation == 1)
		return a + b;
	if (operation == 2)
		return a - b;
	if (operation == 3)
		return a*b;
	if (operation == 4)
		return a / b;
}
void per(int depth, vector<int> v) {
	if (depth == v.size()) {
		int q = 0;
		int ret = num[q++];
		for (int i = 0; i < v.size(); i++) {
			ret = cal(ret, v[i], num[q++]);
		}
		ans1 = max(ans1, ret);
		ans2 = min(ans2, ret);
	}
	else {
		for (int i = depth; i < v.size(); i++) {
			swap(v[depth], v[i]);
			per(depth + 1, v);
		}
	}

}
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int input; scanf("%d", &input);
		num.push_back(input);
	}
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++)//+
		op.push_back(1);
	scanf("%d", &k);
	for (int i = 0; i < k; i++)//-
		op.push_back(2);
	scanf("%d", &k);
	for (int i = 0; i < k; i++)//x
		op.push_back(3);
	scanf("%d", &k);
	for (int i = 0; i < k; i++)//%
		op.push_back(4);
	per(0, op);
	printf("%d\n%d", ans1, ans2);
	return 0;
}