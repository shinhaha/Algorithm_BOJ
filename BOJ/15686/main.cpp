#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <queue>
using namespace std;
#define PI pair<int,int>
vector<PI> city, person;
int n,m;
int q = 1e9;
bool visit[15] = { 0 };
int map[51][51];
int chk() {
	int sum = 0;
	for (int i = 0; i <person.size(); i++) {
		int ret = 1e9;
		for (int j = 0; j < city.size(); j++) {
			if (visit[j]) {
				ret = min(ret, abs(city[j].first - person[i].first) + abs(city[j].second - person[i].second));
			}
		}
		sum += ret;
	}
	return sum;
}
void proc(int depth,int c){
	if (c == m)
		q=min(q,chk());
	else {
		for (int i = depth; i < city.size(); i++) {
			visit[i] = true;
			proc(i + 1, c + 1);
			visit[i] = false;
		}
	}
}
int main() {
	scanf("%d %d", &n,&m);
	for(int i=0; i<n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1)person.push_back({ i,j });
			else if (map[i][j] == 2)city.push_back({ i,j });
		}
	proc(0, 0);
	printf("%d", q);
	return 0;
}