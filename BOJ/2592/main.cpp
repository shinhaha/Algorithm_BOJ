#include<stdio.h>
int arr[101] = { 0 };
int main() {
	int sum = 0; int max = 0; int rem = -1;
	for (int i = 0; i < 10; i++) {
		int tmp; scanf("%d", &tmp);
		arr[tmp / 10]++;
		sum += tmp;
		if (max < arr[tmp / 10]) {
			max = arr[tmp / 10];
			rem = tmp;
		}
	}
	printf("%d\n%d", sum / 10, rem);
}