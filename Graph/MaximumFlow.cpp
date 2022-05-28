#include<bits/stdc++.h> 
#define MXN 1010
using namespace std;

int n,e,src,sink;
int capacity[MXN][MXN];
int visited[MXN];  
int Parent[MXN];   

void dfs(int p) {
	visited[p] = 1;  
	for(int i = 0; i<n; i++) {
		if(visited[i] || capacity[p][i] == 0) continue;  
		Parent[i] = p;
		dfs(i);  
	}
}

vector<int> Path(int st, int ed) {
	queue<int>q; 
	q.push(st);  
	memset(visited,0,sizeof(visited));
	memset(Parent,-1,sizeof(Parent));
	visited[st] = 1;  
	dfs(st);  
	vector<int>path;  
	if(Parent[ed] == -1) return path;  
	int cur = ed;  
	while(cur != -1) {
		path.push_back(cur);  
		cur = Parent[cur];
	}
	reverse(path.begin(),path.end());  
	return path;
}

int findFlow(int sc, int sk) {
	int flow = 0;  
	while(true) {
		vector<int>path = Path(sc,sk);   
		if(path.size() == 0) return flow; 
		int min_cap = 1e9 + 7;  
		for(int i = 0; i<path.size()-1; i++) {
			int u = path[i], v = path[i+1];
			min_cap = min(min_cap,capacity[u][v]);  
		}
		flow += min_cap;
		for(int i = 0; i<path.size()-1; i++) {
			int u = path[i], v = path[i+1];
			capacity[u][v] -= min_cap;  
			capacity[v][u] += min_cap; 
		}
	}
}

void input() {
	cin >> n >> e;  
	memset(capacity,0,sizeof(capacity));
	for(int i = 0; i<e; i++) {
		int x,y,w;  
		cin >> x >> y >> w; // x -> y
		capacity[x][y] += w;  
	}
	cin >> src >> sink;  
}

int main() {
	int t;  
	//freopen("00_input.txt","r",stdin); 
	cin >> t;  
	while(t--) {
		input();
		int flow = findFlow(src,sink);  
		cout << flow << endl;  
	}
	return 0 ;
}