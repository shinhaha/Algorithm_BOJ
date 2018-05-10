#define _CRT_SECURE_NO_WARNINGS // scanf(), gets() (needed for Visual C++)
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define MEMSET(x, WITH) memset(x, (WITH), sizeof(x))
#define FOR(i, E) for(int i=0; i<(E); i++)
#define REP(i, LO, HI) for(int i=(LO); i<=(HI); i++)
#define SORT(v) sort(v.begin(),v.end())
#define PI pair<int,char*>
typedef long long ll;

char buf[30][30];

int main() {
	int n, i;
	vector<PI> v;
	int index = 1;
	while (1234) {
		v.clear();
		scanf("%d", &n);
		if (!n)break;
		printf("SET %d\n", index++);
		FOR(i, n) {
			scanf("%s", buf[i]);
			v.push_back({ strlen(buf[i]),buf[i] });
		}
		sort(v.begin(), v.end());

		if (n & 1) {
			for (int i = 0; i < n; i += 2)printf("%s\n", v[i].second);
			for (int i = n - 2; i >= 1; i -= 2)printf("%s\n", v[i].second);

		}
		else {
			for (int i = 0; i < n; i += 2)printf("%s\n", v[i].second);
			for (int i = n - 1; i >= 1; i -= 2)printf("%s\n", v[i].second);
		}
	}
}