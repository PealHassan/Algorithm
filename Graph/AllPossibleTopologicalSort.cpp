#include<bits/stdc++.h>
#define MXN 1010  
using namespace std;  
vector<int>graph[MXN];  
int node , edge;  
int indegree[MXN]; 
int vis[MXN];
vector<int>path;  
void fun() {
	if(path.size() == node) {
		for(auto e: path) cout << e << " ";  
		cout << endl;
	}
	for(int i = 0; i<node; i++) {
		if(vis[i]) {
			path.push_back(i);  
			for(int j = 0; j<graph[i].size(); j++) {
				indegree[graph[i][j]]--;
				if(indegree[graph[i][j]] == 0) 
					vis[graph[i][j]] = 1;  
			}
			vis[i] = 0;  
			fun();  
			vis[i] = 1;  
			path.pop_back();  
			for(int j = 0; j<graph[i].size(); j++) {
				if(indegree[graph[i][j]] == 0)
					vis[graph[i][j]] = 0;
				indegree[graph[i][j]]++;
			}
		}
	}
}
void allPossibleTopoSort() { 
	for(int i = 0; i<node; i++) {
		if(indegree[i]) vis[i] = 0;  
		else vis[i] = 1;  
	}
	fun();
} 
void input() {
	cin >> node >> edge;
	memset(indegree,0,sizeof(indegree));  
	for(int i = 0; i<node; i++) graph[i].clear();    
	for(int i = 0; i<edge; i++) {
		int x,y;  
		cin >> x >> y;  // x -> y, x before y
		graph[x].push_back(y);  
		indegree[y]++;
	}
}
int main() {
	int t; 
	cin >> t;  
	while(t--) {
		input();  
		allPossibleTopoSort();
	}
	return 0;  
}