#include<stdio.h>
int main() {
	int A, B, V; scanf("%d %d %d", &A, &B, &V);
	int day = (V - A) / (A - B);
	long long curr = day*(A - B);
	day++;
	while (1) {
		curr += A;
		if (curr >= V)break;
		curr -= B;
		day++;
	}
	printf("%d", !day ? 1 : day);
}