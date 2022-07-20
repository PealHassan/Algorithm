#include<bits/stdc++.h>  
using namespace std; 
int n;  
vector<int> a; 
#define LOG 15
#define MXN 100010 
int sp[MXN][LOG]; 

void buildSparse() {
	for(int i = 0; i<n; i++)
		sp[i][0] = a[i];  
	for(int i = 1; i<LOG; i++) {
		for(int j = 0; j<n; j++) {
			int u = sp[j][i-1];  
			int v = sp[j+(1 << (i-1))][i-1];  
			sp[j][i] = u + v;  
		}
	}
}
void input() {
	cin >> n;  
	a.clear(); 
	memset(sp,0,sizeof(sp));
	for(int i = 0; i<n; i++) {
		int x;  
		cin >> x;  
		a.push_back(x);  
	}
} 
int query(int left, int right) {
	int u = right - left + 1;  
	bitset<32>b;  
	b = u;  
	int sum = 0;  
	for(int i = 0; i<32; i++) {
		if(b[i]) {
			sum += sp[left][i];  
			left += (1 << i);  
		}
	}
	return sum;  
}
int main() {
	input(); 
	buildSparse();
	cout << query(2,3) << endl;
	return 0;  
}