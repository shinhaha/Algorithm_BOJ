//boj 2693
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include<time.h>
using namespace std;
int n;
vector<int> v;

void Swap(int i, int j) {
	int tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;
}

int Partition(int p, int r) {
	int x = v[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (v[j] <= x) {
			i++;
			Swap(i, j);
		}
	}
	Swap(i + 1, r);
	return i + 1;
}

int RandomizedPartition(int p, int r) {
	int i = rand() % (r - p + 1) + p;
	Swap(r, i);
	return Partition(p, r);
}
int Randomized_Select(int p, int r, int i) {
	if (p == r)return v[p];
	int q = RandomizedPartition(p, r);
	int k = q - p + 1;
	if (i == k)return v[q];
	if (i < k)
		return Randomized_Select(p, q - 1, i);
	else
		return Randomized_Select(q + 1, r, i - k);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		v.clear();
		for (int j = 0; j < 10; j++) {
			int input; scanf("%d", &input);
			v.push_back(input);
		}
		printf("%d\n", Randomized_Select(0, v.size() - 1, 8));
	}
}