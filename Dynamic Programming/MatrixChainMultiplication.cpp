#include<bits/stdc++.h> 
#define MXN 1010 
using namespace std;  
vector<int>row,col;
int dp[MXN][MXN];  
int n;  
void input() {
	cin >> n; 
	row.clear();  
	col.clear();
	memset(dp,-1,sizeof(dp));  
	for(int i = 0; i<n; i++) {
		int x,y; 
		cin >> x >> y;  
		row.push_back(x);  
		col.push_back(y);
	}
}
bool valid() {
	for(int i = 1; i<n; i++) {
		if(col[i-1] != row[i])
			return false;  
	}
	return true;  
}
int matrixChainMultiplication(int begin, int end) {
	if(begin>=end) return 0;
	if(dp[begin][end] != -1) return dp[begin][end];
	int sum = 2e9;  
	for(int i = begin; i<end; i++) {
		int p = matrixChainMultiplication(begin,i);  
		int q = matrixChainMultiplication(i+1,end); 
		int r = row[begin]*col[i]*col[end];  
		sum = min(sum,p+q+r);
	}
	return dp[begin][end] = sum;  
}
int main() {
	int t;  
	cin >> t;
	while(t--) {
		input();
		if(!valid) {
			cout << "Invalid Matrix" << endl; 
			continue;
		}
		cout << matrixChainMultiplication(0,n-1) << endl;
	}
	return 0;  
}