#include<bits/stdc++.h>  
using namespace std; 
int n;  
vector<bool> vis(100,false);
vector<int> ans;
void Combination() {
	for(auto e: ans) cout << e + 1 << " "; 
	cout << endl;  
	if(ans.size() == n) return;
	int p = ans.size()-1;  
	if(p>=0) p = ans[p];
	else p = -1;
	for(int i = 0; i<n; i++) {
		if(i>p && !vis[i]) {
			vis[i] = true;
			ans.push_back(i);    
			Combination();
			vis[i] = false;  
			ans.pop_back();
		}
	}
} 
int main() { 
	cin >> n;  
	Combination();  
	return 0;  
}