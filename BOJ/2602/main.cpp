#include <cstdio>
#include <string.h>
#include <string>
typedef long long ll;

int lenR = 0, lenA = 0;
char RINGS[23];
char ANGEL[103];
char DEVIL[103];

ll dp[103][2][103] = { 0 };
ll ret = 0;
ll f(ll i, ll j, ll curr) {
	if (curr == lenR)return 1;
	if (dp[i][j][curr] != 0)return dp[i][j][curr];
	if (i < lenA && curr<lenR) {
		if (j & 1) {
			if (DEVIL[i] == RINGS[curr])
				return dp[i][j][curr] = (f(i + 1, 0, curr + 1) + f(i + 1, 1, curr));
			else return dp[i][j][curr] = f(i + 1, 1, curr);
		}
		else {
			if (ANGEL[i] == RINGS[curr])
				return dp[i][j][curr] = (f(i + 1, 1, curr + 1) + f(i + 1, 0, curr));
			else return dp[i][j][curr] = f(i + 1, 0, curr);
		}
	}
	return 0;
}

int main() {
	scanf("%s %s %s", RINGS, ANGEL, DEVIL);
	lenR = strlen(RINGS), lenA = strlen(ANGEL);
	f(0, 0, 0), f(0, 1, 0);
	printf("%lld", dp[0][0][0] + dp[0][1][0]);
	return 0;
}