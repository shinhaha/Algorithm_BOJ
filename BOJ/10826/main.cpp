#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;

char adder1[10000];
char adder2[10000];
char adder3[10000];

void add(char* a,char* b){
	int aIndex = strlen(a)-1;
	int bIndex = strlen(b)-1;
	int carry = 0;
	int addIndex = 0;
	while (true) {
		if (aIndex<0 &&bIndex<0)break;
		int numa = aIndex>=0?a[aIndex--] - '0':0;
		int numb = bIndex>=0?b[bIndex--] - '0':0;
		adder3[addIndex++] = (numa + numb+carry) % 10 + '0';
		carry = (numa + numb + carry) / 10;
	}
	if (carry)adder3[addIndex++] = carry + '0';
	reverse(adder3, adder3 + addIndex);
	strcpy(adder1, adder2);
	strcpy(adder2, adder3);
}

char* fib(int n) {
	if (n == 0)return "0";
	if (n == 1)return "1";
	sprintf(adder1, "%c",'0');
	sprintf(adder2, "%c",'1');
	for (int i = 2; i <= n; i++)
		add(adder1, adder2);
	return adder2;
}

int main() {
	int n; scanf("%d", &n);
	printf("%s", fib(n));
	return 0;
}
