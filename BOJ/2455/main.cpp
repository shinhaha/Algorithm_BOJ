#include<stdio.h>
#include<algorithm>
using namespace std;

int main() {
	int ret = -1;
	int sum = 0;
	for (int i = 0; i<4; i++) {
		int in, out; scanf("%d %d", &out, &in);
		sum += in; sum -= out;
		ret = max(sum, ret);
	}
	printf("%d", ret);
}