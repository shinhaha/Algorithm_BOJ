#define _CRT_SECURE_NO_WARNINGS // scanf(), gets() (needed for Visual C++)
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define MEMSET(x, WITH) memset(x, (WITH), sizeof(x))
#define FOR(i, E) for(int i=0; i<(E); i++)
#define REP(i, LO, HI) for(int i=(LO); i<=(HI); i++)
#define SORT(v) sort(v.begin(),v.end())
#define PI pair<int,int>
typedef long long ll;

typedef vector<ll> vec;
typedef vector<vec> mat;

const ll MOD = 10000;

mat mul(mat &A, mat &B) {
	mat C(A.size(), vec(B[0].size()));
	for (int i = 0; i < A.size(); i++)
		for (int k = 0; k < B.size(); k++)
			for (int j = 0; j < B[0].size(); j++)
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
	return C;
}


mat pow(mat A, ll n) {
	mat B(A.size(), vec(A.size()));
	for (int i = 0; i < A.size(); i++)B[i][i] = 1;
	while (n > 0) {
		if (n & 1)B = mul(B, A);
		A = mul(A, A);
		n >>= 1;
	}
	return B;
}

int main() {
	while (1) {
		ll n; scanf("%lld", &n);
		if (n == -1)break;
		mat A(2, vec(2));
		A[0][0] = 1; A[0][1] = 1;
		A[1][0] = 1; A[1][1] = 0;
		A = pow(A, n);
		printf("%lld\n", A[1][0]);
	}
}