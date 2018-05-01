#include <algorithm>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <functional>
#include <string>
#include <deque>
using namespace std;
int n;

bool x(vector<int> vec) {
	int k = vec.size();
	for (int i = 0; i<k/2; i++) 
		if (vec[i] != vec[k- 1 - i])return false;
	return true;
}
int main() {
	scanf("%d", &n);
	for (int t = 0; t < n; t++) {
		int input; scanf("%d", &input);
		int flag = 0;
		vector<int> v;
		for (int i = 2; i <= 64; i++) {
			v.clear();
			int curr = input;
			while (curr) {
				v.push_back(curr%i);
				curr /= i;
			}
			if (x(v)) {
				flag = 1;
				break;
			}
		}
		if (flag)printf("1\n");
		else printf("0\n");
	}
	return 0;
}