#include<bits/stdc++.h>  
using namespace std; 
int n;  
vector<bool> vis(100,false);
vector<int> ans;
void AllPossiblePermuationAmongN() {
	for(auto e: ans) cout << e + 1 << " "; 
	cout << endl;  
	if(ans.size() == n) return;
	for(int i = 0; i<n; i++) {
		if(!vis[i]) {
			vis[i] = true;
			ans.push_back(i);    
			AllPossiblePermuationAmongN();
			vis[i] = false;  
			ans.pop_back();
		}
	}
} 
int main() { 
	cin >> n;  
	AllPossiblePermuationAmongN();  
	return 0;  
}