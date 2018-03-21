#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <string.h>
#include <stack>
using namespace std;
char buf[202];
int ansflag[1025];
char ans[1025][202];
bool flag[202];
stack<pair<int, char>> lparen;
vector<pair<int, int>> paren;
int trigger = 0, ansidx = 0;
void print() {
	if (trigger) {
		int q = 0;
		for (int i = 0; i < strlen(buf); i++)
			if (flag[i])
				ans[ansidx][q++] = buf[i];
		ansidx++;
	}
	trigger = 1;
}
void proc(int i) {
	if (i != -1) {
		int start = paren[i].first;
		int end = paren[i].second;
		proc(i - 1);
		flag[start] = flag[end] = 0;
		proc(i - 1);
		flag[start] = flag[end] = 1;
	}
	else print();
}
void swap(int i, int j) {
	char tmp[202];
	strcpy(tmp, ans[i]);
	strcpy(ans[i], ans[j]);
	strcpy(ans[j], tmp);
}
int main() {
	scanf("%s", buf);
	memset(flag, 1, sizeof(flag));
	memset(ansflag, 1, sizeof(ansflag));
	for (int i = 0; i < strlen(buf); i++) {
		if (buf[i] == '(')
			lparen.push({ i,'(' });
		if (buf[i] == ')') {
			paren.push_back({ lparen.top().first,i });
			lparen.pop();
		}
	}
	proc(paren.size() - 1);

	for (int i = 0; i < ansidx - 1; i++)
		for (int j = i + 1; j < ansidx; j++)
			if (strcmp(ans[i], ans[j]) > 0)swap(i, j);

	for (int i = 0; i < ansidx - 1; i++)
		for (int j = i + 1; j < ansidx; j++)
			if (!strcmp(ans[i], ans[j]))ansflag[j] = 0;

	for (int i = 0; i < ansidx; i++) {
		if (!ansflag[i])continue;
		for (int j = 0; j < strlen(ans[i]); j++)
			printf("%c", ans[i][j]);
		printf("\n");
	}
	return 0;
}