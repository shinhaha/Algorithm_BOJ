#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#define PI pair<int,int>
using namespace std;

int main() {
	vector<PI> v;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int k; scanf("%d", &k);
		bool* visit = new bool[k]();
		v.clear();
		for (int j = 0; j < k; j++) {
			int a, b;
			scanf("%d %d", &a, &b);
			v.push_back(make_pair(a, b));
		}
		sort(v.begin(), v.end());
		visit[0] = true;
		int mark = v[0].second;
		for (int x = 1; x < k; x++) {
			if (v[x].second<mark)
				visit[x] = true;
			mark = min(v[x].second, mark);
		}
		int count = 0;
		for (int t = 0; t < k; t++)
			if (visit[t])
				count++;
		printf("%d\n", count);
		free(visit);
	}
}
