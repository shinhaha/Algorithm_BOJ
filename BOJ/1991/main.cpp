#include <stdio.h>
#include <vector>
using namespace std;

bool visit['Z' + '.'] = { 0 };
bool chk[50] = { 0 };
struct Node {
	char curr;
	struct Node* left;
	struct Node* right;
};

struct Word {
	char a, b, c;
};

typedef struct Node node;
typedef struct Word word;

node* root = NULL;

void insert(char curr,char left,char right,node* p){
	if (p->curr == curr) {
		if(left!='.')
		p->left = new node({ left,NULL,NULL });
		if(right != '.')
		p->right = new node({ right,NULL,NULL });
		return;
	}
	else {
		if(p->left!=NULL)
		insert(curr, left, right, p->left);
		if (p->right != NULL)
		insert(curr, left, right, p->right);
	}
}

void preorder(node* curr) {
	printf("%c", curr->curr);
	if (curr->left != NULL)
		preorder(curr->left);
	if (curr->right != NULL)
		preorder(curr->right);
}

void postorder(node* curr) {
	if (curr->left != NULL)
		postorder(curr->left);
	if (curr->right != NULL)
		postorder(curr->right);
	printf("%c", curr->curr);
}

void inorder(node* curr) {
	if (curr->left != NULL)
		inorder(curr->left);
	printf("%c", curr->curr);
	if (curr->right != NULL)
		inorder(curr->right);
}

int main() {
	int n; scanf("%d", &n);
	char a, b, c;

	root = new node({'A' ,NULL,NULL });

	visit['A'] = true;

	vector<word> v;
	for (int i = 0; i < n; i++) {
		scanf("%c", &a);
		scanf("%c %c %c", &a, &b, &c);
		v.push_back({ a,b,c });
	}

	int x = n;

	while (x) {
		for (int i = 0; i < n; i++) {
			if (visit[v[i].a]&&!chk[i]) {
				x--;
				chk[i]=visit[v[i].b] = visit[v[i].c] = true;
				insert(v[i].a,v[i].b,v[i].c,root);
			}
		}
	}
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
	
	return 0;
}