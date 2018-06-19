#include <cstdio>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <cstdbool>
#include <stdbool.h>
using namespace std;

int main() {
	int hour, min, p;
	scanf("%d %d %d", &hour, &min, &p);
	hour = (hour + p / 60) % 24;
	min = (min + p % 60);
	hour = (hour + min / 60) % 24;
	min = min % 60;
	printf("%d %d",hour,min);
	return 0;
}