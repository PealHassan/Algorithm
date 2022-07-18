#include<bits/stdc++.h> 
#define MXN 1010 
using namespace std;  
vector<int>graph[MXN],cost[MXN];  
int vis[MXN][MXN],vis2[MXN];   
int node, edge; 
void MST() {
	multiset< pair < int, pair<int,int> > > s;
	memset(vis,0,sizeof(vis)); 
	memset(vis2,0,sizeof(vis2));   
	for(int i = 0; i<graph[1].size(); i++) {
		s.insert({cost[1][i], {1,graph[1][i]}});
		vis[1][graph[1][i]] = 1;  
		vis[graph[1][i]][1] = 1;  
	}
	int sum = 0;  
	while(s.size()) {
		int p = (*s.begin()).first;  
		int u = (*s.begin()).second.first;
		int v = (*s.begin()).second.second;  
		s.erase(s.begin());
		if(vis2[u] == 1 && vis2[v] == 1) continue;  
		vis2[u] = 1;  
		vis2[v] = 1;
		cout << u << " " << v << endl;  
		sum += p;  
		for(int i = 0; i<graph[u].size(); i++) {
			int t = graph[u][i];  
			if(!vis[u][t]) {
				s.insert({cost[u][i], {u,t}});
				vis[u][t] = 1;  
				vis[t][u] = 1;  
			}
		}
		for(int i = 0; i<graph[v].size(); i++) {
			int t = graph[v][i];  
			if(!vis[v][t]) {
				s.insert({cost[v][i], {v,t}});
				vis[v][t] = 1;  
				vis[t][v] = 1;  
			}
		}
	}
	cout << sum << endl;  
} 
void input() {
	cin >> node >> edge;
	for(int i = 0; i<=node; i++) {
		graph[i].clear();   
		cost[i].clear();  
	}
	for(int i = 0; i<edge; i++) {
		int x,y,c;  
		cin >> x >> y >> c;  
		graph[x].push_back(y);  
		graph[y].push_back(x);  
		cost[x].push_back(c);  
		cost[y].push_back(c);  
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