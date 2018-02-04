#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define PI pair<int,int>

vector<int> v;
vector<PI> bridge;
int sum = 0;
int time = 0;
void proc() {
	if (bridge.size() != 0) {
		for (int i = 0; i < bridge.size(); i++)
			bridge[i] = { bridge[i].first,bridge[i].second - 1 };
		if (bridge[0].second == 0) {
			sum -= bridge[0].first;
			bridge.erase(bridge.begin());
		}
	}
}
int main() {

	int n, w, l; scanf("%d %d %d", &n, &w, &l);

	for (int i = 0; i < n; i++) {
		int input; scanf("%d", &input);
		v.push_back(input);
	}

	while (true) {
		proc();
		time++;
		if (v.size() != 0 && sum + v.front() <= l)
		{
			bridge.push_back({ v.front(),w });
			sum += v.front();
			v.erase(v.begin());
		}
		if (bridge.size() == 0) {
			printf("%d", time);
			break;
		}
	}


	return 0;
}