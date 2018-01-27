//boj 1958
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char buf1[103], buf2[103], buf3[103];
int LCS[103][103][103];

int main() {
	scanf("%s %s %s", buf1, buf2, buf3);
	memset(LCS, 0, sizeof(LCS));

	for (int i = 1; i <= strlen(buf1); i++)
		for (int j = 1; j <= strlen(buf2); j++)
			for (int k = 1; k <= strlen(buf3); k++)
				if (buf1[i-1] == buf2[j-1] && buf2[j-1] == buf3[k-1])
					LCS[i][j][k] = LCS[i - 1][j - 1][k - 1] + 1;
				else LCS[i][j][k] = max(LCS[i - 1][j][k], max(LCS[i][j - 1][k], LCS[i][j][k - 1]));

	printf("%d", LCS[strlen(buf1)][strlen(buf2)][strlen(buf3)]);

	return 0;
}