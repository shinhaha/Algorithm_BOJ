#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <queue>
using namespace std;
char S[101], T[101];
int main() {
	int t; scanf("%d", &t);
	for (int test = 1; test <= t; test++) {
		int one = 0, zero = 0;
		scanf("%s %s", S, T);
		if (strlen(S) != strlen(T)) {
			printf("Case %d: -1\n", test);
			continue;
		}
		for (int i = 0; i < strlen(T); i++) {
			if (T[i] == '1')one++;
			else zero++;
		}
		int ques = 0;
		for (int i = 0; i < strlen(T); i++) {
			if (S[i] == '1')one--;
			else if (S[i] == '0')zero--;
			else ques++;
		}
		int ans = 0;
		for (int i = 0; i < strlen(T); i++) {
			if (T[i] == '1'&&S[i] == '?'&&one) {
				S[i] = '1';
				one--;
				ques--;
				ans++;
			}//1을 먼저 채워준다
		}
		for (int i = 0; i < strlen(T); i++) {
			if (T[i] == '1'&&S[i] == '0'&&one) {
				S[i] = '1';
				one--;
				zero++;
				ans++;
			}//0인 자리의 1을 먼저 채워준다
		}
		for (int i = 0; i < strlen(T); i++) {
			if (one&&S[i] == '?') {//1이 아직 남았으면 1부터 채움
				S[i] == '1';
				one--;
				ques--;
				ans++;
			}
			else if (S[i] == '?') {//나머지 0으로 채움
				S[i] = '0';
				zero--;
				ques--;
				ans++;
			}
		}
		if (zero || one || ques) {//안맞으면 불가능
			printf("Case %d: -1\n", test);
			continue;
		}
		for (int i = 0; i < strlen(T); i++)
			for (int j = 0; j < strlen(S); j++)
				if (S[i] == '1'&&S[j] == '0'&&T[i] == '0'&&T[j] == '1') {
					swap(S[i], S[j]);
					ans++;
				}
		printf("Case %d: %d\n", test, ans);
	}
	return 0;
}