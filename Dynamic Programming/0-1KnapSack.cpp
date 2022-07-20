#include<bits/stdc++.h>  
#define MXN 1010
using namespace std;  
int n, weight;  
vector<int>arr,profit;
int dp[MXN][MXN];  
void input() {
	cin >> n >> weight;
	memset(dp,-1,sizeof(dp));    
	for(int i = 0; i<n; i++) {
		int x,y;  
		cin >> x >> y;  
		arr.push_back(x);
		profit.push_back(y);  
	}
}
int knapSack(int i, int amount) {
	if(amount < 0) return -2e9;  
	if(i == n) return 0;  
	if(dp[i][amount] != -1) return dp[i][amount];  
	return dp[i][amount] = max(knapSack(i+1,amount-arr[i])+profit[i],knapSack(i+1,amount));
}
int main() {
	int t;  
	cin >> t;  
	while(t--) {
		input(); 
		cout << knapSack(0,weight) << endl;  
	}
	return 0;  
}