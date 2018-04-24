#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <queue>
#include <functional>
using namespace std;
#define PI pair<int,int>

priority_queue<PI, vector<PI>, greater<PI>> pq;

int main() {
	int n; scanf("%d", &n);
	while (n--) {
		int input; scanf("%d", &input);
		if (!input) {
			if (pq.empty())printf("0\n");
			else {
				printf("%d\n", pq.top().second);
				pq.pop();
			}
		}
		else pq.push({ abs(input),input });
	}
}