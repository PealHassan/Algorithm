#include<bits/stdc++.h>
#define sz 100000 
#define ll long long int
#define LOG 32
#define loop(s,d,in) for(ll i = s; i<d; i+=in)
using namespace std;
using V = std::vector<ll>;  
V graph[sz]; // number of nodes
ll up[sz][LOG]; 
V depth(sz); 
V vis(sz);  
void input() {
	ll n,m;  
	cin >> n >> m;  
	for(ll i = 0; i<m; i++) {
		ll x,y;  
		cin >> x >> y ;  
		graph[x].push_back(y);  
		graph[y].push_back(x);
	}
}
void dfs(ll n) {
	vis[n] = 1;  
	for(ll i = 0; i<graph[n].size(); i++) {
		ll v = graph[n][i];  
		if(!vis[v]) {
			vis[v] = 1;  
			depth[v] = depth[n] + 1;  
			up[v][0] = n;  
			dfs(v);  
		}
	}
}
void buildAncestorTable() {
	for(ll i = 1; i<LOG; i++) {
		for(ll j = 0; j<sz; j++) {
			up[j][i] = up[up[j][i-1]][i-1];  
		}
	}
}
ll kthAncestor(ll node, ll k) {
	bitset<32>b; 
	b = k;  
	for(ll i = 0; i<32; i++) {
		if(b[i] == 1) node = up[node][i]; 
	}
	return node;  
}
ll lca(ll x, ll y) {
	if(depth[x]<depth[y]) swap(x,y);  
	if(depth[x]>depth[y]) {
		x = kthAncestor(x,depth[x]-depth[y]);
	}
	if(x == y) return x;  
	for(ll j = LOG-1; j>=0; j--) {
		if(up[x][j] != up[y][j]) {
			x = up[x][j];  
			y = up[y][j];
		}
	}
	return up[x][0];  

}
int main() { // complexity O(query*log(node) + node*log(node))
	input(); // complexity O(edge)
	dfs(1);  // complexity O(node + edge)
	buildAncestorTable(); // O(node*log(node))
	ll q;  
	cin >> q;  // queries 
	for(ll i = 0; i<q; i++) {
		ll x,y;  
		cin >> x >> y;  
		cout << lca(x,y) << endl;  
	}
	return 0;  
}