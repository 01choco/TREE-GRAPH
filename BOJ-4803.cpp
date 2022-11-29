#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> input[501]; 
bool check[501];

bool dfs(int node, int parent){
	check[node] = true;
	for(int i=0; i<input[node].size(); i++){
		if(parent == input[node][i]) continue;
		if(check[input[node][i]] == true) return false;
		if(dfs(input[node][i], node) == false) return false;
	}
	return true;
}
int main(){
	cin.tie(NULL); ios::sync_with_stdio(false);
	int cnt = 0;
	while(true){
		cnt++;
		int N, M;
		cin >> N >> M;
		if (N == 0 && M == 0) break;
		for(int i=0; i<501; i++){
			if(check[i] == true) check[i] = false;
			input[i].clear();
		}
		for(int i=0; i<M; i++){
			int t1, t2;
			cin >> t1 >> t2;
			input[t1].push_back(t2);
			input[t2].push_back(t1);
		}
		int ans = 0;
		if(dfs(1, -1) == true) ans++;
	
		for(int i=2; i<=N; i++){
			if(!check[i]) {
				if(dfs(i, -1) == true) {
					ans++;
				}
			}
		}
		if(ans==0) cout << "Case " << cnt << ": No trees.\n";
		else if(ans==1) cout << "Case " << cnt << ": There is one tree.\n";
		else cout << "Case " << cnt << ": A forest of " << ans << " trees.\n";
	}
	return 0;
}
