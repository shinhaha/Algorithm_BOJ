#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;
void proc(vector<int> v, int start, int end) {
	if (start == end) {
		for (auto it : v)
			printf("%d ", it);
		printf("\n");
	}
	for (int i = start; i < end; i++) {
		swap(v[i], v[start]);
		proc(v, start + 1, end);
	}
}
int main() {
	vector<int> v;
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		v.push_back(i);
	proc(v, 0, n);
}