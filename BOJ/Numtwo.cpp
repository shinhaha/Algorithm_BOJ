#include <stdio.h>
#include <stdlib.h>
long long numtwo(long long *arr, int n) {
	for (int i = 3; i <= n; i++)
		arr[i] = arr[i - 1] + arr[i - 2];//Á¡È­½Ä

	return arr[n];
}

int main() {
	long long *arr;
	int n;
	arr = (long long*)malloc(91 * sizeof(long long));
	arr[1] = 1;//1 
	arr[2] = 1;//10
	scanf("%d", &n);
	long long x = numtwo(arr, n);
	printf("%lld", x);
	free(arr);
}