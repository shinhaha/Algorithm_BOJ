#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
char buf[1000];
typedef long long ll;
map<ll, ll> m;
int main() {
	scanf("%s", buf);
	ll n = (buf[0] - '0')*(strlen(buf));
	ll org = n;
	m[n]++;
	while(1){
		sprintf(buf,"%lld",org);
		ll neworg = (buf[0] - '0')*(strlen(buf));
		org = neworg;
		if (m.count(org)) {
			if(org<10)
			printf("FA");
			else printf("NFA");
			return 0;
		}
		m[org]++;
	} 
}