#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;
char buf[1000];
int main() {
	int i = 0;
	scanf("%s", buf);
	int wina = 0; int winb = 0;
	while (wina != 2 && winb != 2) {
		int a = 0; int b = 0;
		while (a != 21 && b != 21) {
			if (buf[i] == 'A')a++;
			else if (buf[i] == 'B')b++;
			i++;
		}
		printf("%d-%d\n", a, b);
		if (a == 21)wina++;
		else if (b == 21)winb++;
	}
	if (wina > winb)printf("A");
	else printf("B");
}