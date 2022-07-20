#include<bits/stdc++.h>
#define MXN 3010
using namespace std;
int n;  
string x,y;  
int dp[MXN][MXN];
void input() {
	cin >> x >> y;
	memset(dp,-1,sizeof(dp));      
}
int LCS(int i, int j) {
	if(i == x.size() || j == y.size()) return 0;  
	if(dp[i][j] != -1) return dp[i][j];  
	int sum = 0;  
	if(x[i] == y[j]) 
		sum = LCS(i+1,j+1) + 1;
	sum = max(max(LCS(i+1,j),LCS(i,j+1)),max(LCS(i+1,j+1),sum));
	return dp[i][j] = sum;
}
int main() {
	int t;  
	cin >> t;  
	while(t--) {
		input();  
		cout << LCS(0,0) << endl;  
	}
	return 0;  
}