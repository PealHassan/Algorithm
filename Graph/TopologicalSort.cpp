#include<bits/stdc++.h>
#define MXN 1010  
using namespace std; 
vector<int> graph[MXN]; 
int indegree[MXN];    
int node, edge; 
void topologicalSort() {
	queue<int>q;  
	vector<int>seq;  
	for(int i = 0; i<node; i++)
		if(indegree[i] == 0) q.push(i);  
	while(q.size()) {
		int l = q.front();  
		seq.push_back(l);  
		q.pop();  
		for(int i = 0; i<graph[l].size(); i++) {
			int u = graph[l][i];  
			indegree[u]--;  
			if(indegree[u] == 0) q.push(u);  
		}
	}
	if(seq.size() != node) {
		cout << "Topological Sort is not possible" << endl; 
		return ;  
	}
	for(auto e: seq) cout << e << " ";   
		cout << endl;  
	for(int i = 0; i<node; i++) graph[i].clear();  
} 
void input() {
	cin >> node >> edge;
	memset(indegree,0,sizeof(indegree));
	for(int i = 0; i<edge; i++) {
		int x,y;  
		cin >> x >> y;  
		graph[x].push_back(y);  // x -> y;  x before y 
		indegree[y]++;  
	}  
} 
int main() {
	int t = 1;  
	cin >> t ;  
	while(t--) {
		input();
		topologicalSort();  
	} 
	return 0;  
}