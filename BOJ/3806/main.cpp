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
			}//1�� ���� ä���ش�
		}
		for (int i = 0; i < strlen(T); i++) {
			if (T[i] == '1'&&S[i] == '0'&&one) {
				S[i] = '1';
				one--;
				zero++;
				ans++;
			}//0�� �ڸ��� 1�� ���� ä���ش�
		}
		for (int i = 0; i < strlen(T); i++) {
			if (one&&S[i] == '?') {//1�� ���� �������� 1���� ä��
				S[i] == '1';
				one--;
				ques--;
				ans++;
			}
			else if (S[i] == '?') {//������ 0���� ä��
				S[i] = '0';
				zero--;
				ques--;
				ans++;
			}
		}
		if (zero || one || ques) {//�ȸ����� �Ұ���
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