#include<bits/stdc++.h>  
#define MXN 1010
using namespace std;
string word, pattern;  
int dp[MXN][MXN]; 
int editDistance(int i, int j) {
	if(j == pattern.size()) return word.size() - i;
	if(i == word.size()) return pattern.size()-j;
	if(dp[i][j] != -1) return dp[i][j];
	int sum = 1e9; 
	if(word[i] == pattern[j]) 
		sum = min(sum,editDistance(i+1,j+1));  
	sum = min(sum,editDistance(i+1,j+1)+1);
	sum = min(sum,editDistance(i+1,j)+1);  
	sum = min(sum,editDistance(i,j+1)+1);
	return dp[i][j] = sum;   
} 
void input() {
	cin >> word >> pattern ;  
	memset(dp,-1,sizeof(dp));  
}  
int main() {
	int t;  
	cin >> t;  
	while(t--) {
		input();  
		cout << editDistance(0,0) << endl;  
	}
}