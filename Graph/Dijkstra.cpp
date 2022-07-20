#include<bits/stdc++.h>
#define MXN 1010  
#define inf 2e9+7
using namespace std;
vector<int> graph[MXN],cost[MXN];  
int node,edge;   
void input() {
	cin >> node >> edge ;  
	for(int i = 0; i<edge; i++) {
		int x,y,c;  
		cin >> x >> y >> c;  
		graph[x].push_back(y);  
		graph[y].push_back(x);  
		cost[x].push_back(c);  
		cost[y].push_back(c);  
	}
} 
void dijkstra() {
	vector<int> dist(node+1,inf);  
	dist[1] = 0;  
	multiset< pair<int,int> > s;  
	s.insert({0,1});  
	while(s.size()) {
		int c = (*s.begin()).first;
		int l = (*s.begin()).second;    
		s.erase(*s.begin());  
		for(int i = 0; i<graph[l].size(); i++) {
			int u = graph[l][i];  
			if(dist[l] + cost[l][i] < dist[u]) {
				dist[u] = dist[l] + cost[l][i];  
				s.insert({dist[u],u});  
			}
		}
	}
	for(int i = 1; i<=node; i++) {
		cout << i << " " << dist[i] << endl; 
	}
}   
int main() {
	int t;  
	cin >> t;  
	while(t--) {
		input();  
		dijkstra();
	}
	return 0;  
}