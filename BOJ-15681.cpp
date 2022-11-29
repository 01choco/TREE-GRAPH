#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> input[100001]; 
int dp[100001];
bool check[100001];

void dfs(int node, int parent){
	check[node] = true;
	for(int i=0; i<input[node].size(); i++){
		if(check[input[node][i]] == false) {
			dfs(input[node][i], node);
		}
	}
	if (parent != -1){
		dp[parent]+=dp[node];
	}
}
int main(){
	cin.tie(NULL); ios::sync_with_stdio(false);
	int N, R, Q; 
	cin >> N >> R >> Q;
	for(int i=0; i<100001; i++){
		dp[i] = -1;
	}
	for(int i=0; i<N-1; i++){
		int t1, t2;
		cin >> t1 >> t2;
		input[t1].push_back(t2);
		input[t2].push_back(t1);
	}
	dfs(R, -1);

	for(int i=0; i<Q; i++){
		int a;
		cin >> a;
		cout << -dp[a] << "\n";
	}
	return 0;
}
