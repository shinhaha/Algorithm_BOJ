#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
	int sum;
	int c;
	int upload;
	int idx;
};
#define Node struct node
vector<node> v;
bool operator<(node t, node u) {
	if (t.sum != u.sum)
		return t.sum > u.sum;
	else
		if (t.c != u.c)
			return t.c < u.c;
		else
			return t.upload<u.upload;
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		Node x; x.sum = a; x.c = b; x.upload = c; x.idx = i;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	printf("%d", v[0].idx);
	return 0;
}