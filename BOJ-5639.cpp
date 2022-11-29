#include <iostream>

using namespace std;

int tree[10001];

void postorder(int start, int end){
	if(start == end) {
		cout << tree[start] << "\n";
		return;
	}
	if(start>end) return;
	int i = start+1;
	while(true){
		if(tree[start]<tree[i] || i>end){
			break;
		}
		i++;
	}
	postorder(start+1,i-1);
	postorder(i,end);
	cout << tree[start] << "\n";

}
int main(){
	cin.tie(NULL); ios::sync_with_stdio(false);
	
	int num;
	int count = 0;
	while(cin >> num){
		tree[count++] = num;
	}
	postorder(0, count-1);
	return 0;
}
