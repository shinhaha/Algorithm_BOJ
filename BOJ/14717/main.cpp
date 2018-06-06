#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
inline int score(int a, int b) {
	if (a == b) return 10+a;
	return (a + b) % 10;
}
int main() {
	int a, b, s;
	scanf("%d %d", &a, &b);

	for (int i = 0; i<20; i++)
		v.push_back(i / 2 + 1);
	s = score(a, b);
	v.erase(find(v.begin(), v.end(), a));
	v.erase(find(v.begin(), v.end(), b));

	int win = 0;
	for (int i = 0; i<17; i++)
		for (int j = i + 1; j<18; j++)
			if (s > score(v[i], v[j])) win++;
	printf("%.3lf\n", win / 153.0);
}