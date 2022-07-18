#include<bits/stdc++.h>
#define MXN 1010 
using namespace std;  
int node, edge; 
multimap < int, pair<int,int> > data;  
int rep[MXN];  
int find(int n) {
	if(rep[n] == n) return n;  
	return rep[n] = find(rep[n]);
}
void MST() {
	for(int i = 1; i<=node; i++)
		rep[i] = i; 
	int sum = 0;   
	for(auto e: data) {
		int u = e.second.first;  
		int v = e.second.second;
		int p = find(u), q = find(v);  
		if(p == q) continue; 
		cout << u << " " << v << endl; 
		sum += e.first;  
		rep[p] = q;  
	}
	cout << "Sum of Edges is : " << sum << endl;  
}
void input() {
	cin >> node >> edge; 
	data.clear();   
	for(int i = 0; i<edge; i++) {
		int x,y,c;  
		cin >> x >> y >> c;   
		data.insert({c, {x,y}});
	}
}
int main() {
	int t;  
	cin >> t;  
	while(t--) {
		input(); 
		MST();   
	}
	return 0;  
}