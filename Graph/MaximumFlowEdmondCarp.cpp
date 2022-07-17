#include<bits/stdc++.h>  
using namespace std;  
#define MXN 1010
int graph[MXN][MXN];
int node, edge;  
int src, sink;
int parent[MXN];  
int visited[MXN];    
void input() {
	cin >> node >> edge;  
	memset(graph,0,sizeof(graph));  
	for(int i = 0; i<edge; i++) {
		int x,y,c;  
		cin >> x >> y >> c;  
		graph[x][y] += c;  
	}
	cin >> src >> sink;  
}  
vector<int> bfs() {
	queue<int>q;  
	memset(visited,0,sizeof(visited));  
	memset(parent, -1 , sizeof(parent));  
	vector<int>path; 
	q.push(src);  
	visited[src] = 1;  
	while(!q.empty()) {
		int u = q.front();  
		q.pop();  
		for(int i = 0; i<node; i++) { // 0 based index; 
			if(!visited[i] && graph[u][i] > 0) {
				q.push(i);  
				visited[i] = 1;  
				parent[i] = u;  
			}
		}
		if(visited[sink]) break;  
	}
	if(parent[sink] == -1) return path; 
	int cur = sink;  
	while(cur != -1) {
		path.push_back(cur);  
		cur = parent[cur];  
	}
	reverse(path.begin(),path.end()); 
	return path;  
}
int findFlow() {
	int flow = 0;  
	while(1) {
		vector<int>path = bfs();
		if(path.size() == 0) return flow;
		int min_flow = 1e9;  
		for(int i = 0; i+1<path.size(); i++) {
			int u = path[i], v = path[i+1];  
			min_flow = min(min_flow,graph[u][v]); 
		}   
		flow += min_flow;  
		for(int i = 0; i+1<path.size(); i++) {
			int u = path[i], v = path[i+1];  
			graph[u][v] -= min_flow;  
			graph[v][u] += min_flow;
		}
	}
}
int main() {
	int t;  
	cin >> t;  
	while(t--) {
		input(); 
		int flow = findFlow();  
		cout << flow << endl;  
	}
	return 0;  
}