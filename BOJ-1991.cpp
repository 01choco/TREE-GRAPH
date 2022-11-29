#include <iostream>
#include <vector>

using namespace std;

struct node{
	char c;
	node* left = NULL;
	node* right = NULL;
};
void preorder(node* A){
	cout << A->c;
	if(A->left != NULL) preorder(A->left);
	if(A->right != NULL) preorder(A->right);
}
void inorder(node* A){
	if(A->left != NULL) inorder(A->left);
	cout << A->c;
	if(A->right != NULL) inorder(A->right);
}
void postorder(node* A){
	if(A->left != NULL) postorder(A->left);
	if(A->right != NULL) postorder(A->right);
	cout << A->c;
}
int main(){
	cin.tie(NULL); ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<node> nod(26);
	node *root;
	
	for(int i=0; i<N; i++){
		char left, right, me;
		cin >> me >> left >> right;
		nod[me-'A'].c = me; 
		if(left != '.') nod[me-'A'].left = &nod[left-'A'];
		if(right != '.') nod[me-'A'].right = &nod[right-'A'];
	}
	preorder(&nod[0]);
	cout << "\n";
	inorder(&nod[0]);
	cout << "\n";
	postorder(&nod[0]);
	return 0;
}
