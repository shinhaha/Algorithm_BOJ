#include <cstdio>
#include <string.h>

bool isPrime(int v) {
	if (v < 2)return false;
	else if (v == 2)return true;
	else if (!(v % 2))return false;
	else {
		for (int i = 3; i*i <= v; i += 2)
			if (!(v%i))return false;
		return true;
	}
}

bool check[10000];

int main() {
	memset(check,false, sizeof(check));
	int n; scanf("%d", &n);
	for (int i = 2; i<=n; i++) {//에라토스테네스의 체
		if (!check[i])printf("%d ", i);
		for (int j = 2 * i; j <= n; j += i)
			check[j] = true;
	}
}