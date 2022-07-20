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
	vector< vector<int> > dist(2,vector<int>(node+1,inf));  
	dist[0][1] = 0;  
	multiset< pair<int ,pair<int,int>> > s;  
	s.insert({0,{0,1}});
	while(s.size()) {
		int l = (*s.begin()).second.second;  
		int v = (*s.begin()).first;    
		s.erase(*s.begin());  
		for(int i = 0; i<graph[l].size(); i++) {
			int u = graph[l][i];
			int alt = dist[v][l] + cost[l][i]; 
			if(alt < dist[0][u]) {
				dist[1][u] = dist[0][u];   
				dist[0][u] = alt;   
				s.insert({0,{dist[0][u],u}});  
				s.insert({1,{dist[1][u],u}}); 
			}
			else if(alt > dist[0][u] && alt < dist[1][u]) {
				dist[1][u] = alt;  
				s.insert({1,{dist[1][u],u}});
			}
		}
	}
	for(int i = 1; i<=node; i++) {
		cout << i << " " << dist[0][i] << " " << dist[1][i] << endl; 
	}
}   
int main() {
	int t;  
	cin >> t;  
	while(t--) {
		input();  
		dijkstra();
		for(int i = 0; i<=node; i++) {
			graph[i].clear();  
			cost[i].clear();  
		}
	}
	return 0;  
}