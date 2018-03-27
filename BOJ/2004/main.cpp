#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	long long n, m; scanf("%lld %lld", &n, &m);
	long long a = 0; long long b = 0;
	long long x = 0; long long y = 0;

	long long mul5 = 5;
	long long mul2 = 2;

	for (long long i = 1; 1; i++) {
		long long tmp = n / mul5;
		long long tmp2 = n / mul2;
		a += tmp;
		b += tmp2;
		if (tmp == 0 && tmp2 == 0)break;
		mul5 *= 5; mul2 *= 2;
	}

	mul5 = 5;
	mul2 = 2;

	for (long long i = 1; 1; i++) {
		long long tmp = (n-m)/ mul5;
		long long tmp2 = (n-m) / mul2;
		x+= tmp;
		y+= tmp2;
		if (tmp == 0 && tmp2 == 0)break;
		mul5 *= 5; mul2 *= 2;
	}

	mul5 = 5;
	mul2 = 2;

	for (long long i = 1; 1; i++) {
		long long tmp = (m) / mul5;
		long long tmp2 = (m) / mul2;
		x += tmp;
		y += tmp2;
		if (tmp == 0 && tmp2 == 0)break;
		mul5 *= 5; mul2 *= 2;
	}

	printf("%lld", min(a - x, b - y));
}