#include<bits/stdc++.h>
#define MXN 1010  
using namespace std;
vector<int>arr;  
int n;  
void input() {
	cin >> n; 
	arr.clear(); 
	for(int i = 0; i<n; i++) {
		int x;  
		cin >> x;  
		arr.push_back(x);  
	}
}
void LIS() {
	vector<int> path(n), dp(n,1);
	for(int i = 0; i<n; i++) path[i] = i;  
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<i; j++) {
			if(arr[j] < arr[i]) {
				int u = dp[j] + 1;  
				if(u>dp[i]) {
					dp[i] = u;  
					path[i] = j;
				}
			}
		}
	}
	int pos = 0;  
	for(int i = 1; i<n; i++)
		if(dp[i] > dp[pos]) pos = i;  
	cout << "Length is : " << dp[pos] << endl; 
	cout << "Sequence is :";  
	int l = pos;  
	vector<int> res;
	while(path[l] != l) {
		res.push_back(arr[l]);
		l = path[l];  
	}
	res.push_back(arr[l]);  
	reverse(res.begin(),res.end());  
	for(auto e: res) 
		cout << " " << e;  
	cout << endl;  
}

int main() {
	int t;  
	cin >> t;
	while(t--) {
		input();
		LIS();  
	}
	return 0;  
}