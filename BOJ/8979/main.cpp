#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
struct a{
	int num,q,w,e;
};
#define A struct a
bool operator<(a x,a y) {
	if (x.q == y.q)
		if (x.w == y.w)
			if (x.e == y.e)
				return false;
			else return x.e < y.e;
		else return x.w <y.w;
	else return x.q < y.q;
}
int main(){
	int n, k; scanf("%d %d", &n, &k);
	vector<a> vec;  A rem;
	for (int i = 0; i < n; i++) {
		int z, x, c, v; scanf("%d %d %d %d", &z, &x, &c, &v);
		A* tmp = new A();
		tmp->num = z; tmp->q = x; tmp->w = c; tmp->e = v;
		vec.push_back(*tmp);
		if (z == k)rem =*tmp;}
	int ret = 1;
	for (int i = 0; i < n; i++) 
		if (rem < vec[i])ret++;
	printf("%d", ret);	
	return 0;
}
