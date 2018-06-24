#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
char buf[11];
int main() {
	vector<int> v;
	int index=0;
	int k=5;
	while (k--) {
		scanf("%s",buf);
		index++;
		for(int i=0; i<strlen(buf)-2; i++){
			if(buf[i]=='F'&&buf[i+1]=='B'&&buf[i+2]=='I'){
				v.push_back(index);break;}
	}
	}
	sort(v.begin(),v.end());
	for(int i=0; i<v.size(); i++)
		printf("%d ",v[i]);
	return 0;
}