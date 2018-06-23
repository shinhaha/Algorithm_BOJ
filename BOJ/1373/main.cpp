#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
char buf[1000001];
int main() {
	scanf("%s", buf);
	int len = strlen(buf);
	vector<int> v;
	int mok = len / 3;
	int rest = len % 3;
	int i;
	
	for (i = len-1; i >=len-1-3*(mok-1); i-=3) {
		int curr = 0;
		curr += 2 * 2 * (buf[i- 2] - '0');
		curr += 2 * (buf[i- 1] - '0');
		curr += (buf[i] - '0');
		v.push_back(curr);
	}

	if (rest) {
		int curr = 0;
		int mul = 1;
		for (int k = rest-1; k >=0; k--) {
			curr += mul*(buf[k] - '0');
			mul *= 2;
		}
		if (curr)
			v.push_back(curr);
	}
	reverse(v.begin(), v.end());
	if(v.size())
	for (auto it : v)
		printf("%d", it);
	else printf("0");
	return 0;
}