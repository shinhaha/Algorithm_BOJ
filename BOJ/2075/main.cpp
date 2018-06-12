#include<stdio.h>
#include<algorithm>
using namespace std;
int main() {
	int n; scanf("%d", &n);
	int* Table = new int[n*n + 1]();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			scanf("%d", &Table[i + n*(j - 1)]);
		}
	Table[0] = 2147483647;
	sort(Table, Table + n*n + 1);
	//for (int i = 0; i <= n*n; i++)
	//printf("%d ", Table[i]);
	printf("%d", Table[n*n - n]);
}