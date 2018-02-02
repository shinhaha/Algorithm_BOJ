#include <cstdio>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>
#include <functional>
using namespace std;
#define PI pair<double,double>
vector<PI> graph[101]; //dist,dest;
bool visit[101];

int main() {
	memset(visit, 0, sizeof(visit));
	vector<PI> v;
	priority_queue<PI, vector<PI>, greater<PI>> pq;
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		double x, y; scanf("%lf %lf", &x, &y);
		v.push_back({ x,y });
	}

	int ver = 0;
	double sum = 0.0;
	for (int i = 0; i < v.size(); i++)
		for (int j = 0; j < v.size(); j++)
			if (i == j)continue;
			else {
				double d = sqrt(pow(v[i].first - v[j].first, 2) + pow(v[i].second - v[j].second, 2));
				graph[i].push_back({ d,j });
			}

			int src = 0;

			for (int i = 0; i < graph[src].size(); i++)
				pq.push(graph[src][i]);
			visit[src] = true;
			while (!pq.empty()) {
				double dist = pq.top().first;
				int dest = pq.top().second; pq.pop();
				if (visit[dest])continue;
				visit[dest] = true;
				ver++; sum += dist;
				if (ver == n - 1)break;
				for (int i = 0; i < graph[dest].size(); i++) {
					if (!visit[(int)graph[dest][i].second])
						pq.push(graph[dest][i]);
				}
			}

			printf("%.2lf", sum);


}