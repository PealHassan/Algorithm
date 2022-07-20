#include<bits/stdc++.h> 
#define MXN 1010 
using namespace std;
int node, edge;
int cost[MXN][MXN];     
int path[MXN][MXN];   
void input() {
	cin >> node >> edge;
	for(int i = 0; i<=node; i++)
		for(int j = 0; j<=node; j++) {
			cost[i][j] = 2e9, cost[j][i] = 2e9;
			path[i][j] = -1;  
			if(i == j) {
				cost[i][j] = 0;
				path[i][j] = i;  
			}  
		}

	for(int i = 0; i<edge; i++) {
		int x,y,c;    
		cin >> x >> y >> c;  
		cost[x][y] = c;  
		cost[y][x] = c; 
		path[x][y] = y;  
		path[y][x] = x;  
	}
}  
void floyWarshall() {
	for(int i = 1; i<=node; i++) {
		for(int j = 1; j<=node; j++) {
			for(int k = 1; k<=node; k++) {
				if(cost[j][i] + cost[i][k] < cost[j][k]) {
					cost[j][k] = cost[j][i] + cost[i][k];
					path[j][k] = i;    
				}
			}
		}
	}
	for(int i = 1; i<=node; i++) {
		for(int j = 1; j<=node; j++) {
			cout << "Cost is : " << cost[i][j] << " for " << i << " to " << j << endl;  
			cout << "Path : ";  
			int u= i, v = j;  
			do {
				cout << u << " -> ";  
				u = path[u][v];
			}while(u != j); 
			cout << j << endl;  
		}
	}
}
int main() {
	int t;  
	cin >> t;  
	while(t--) {
		input();  
		floyWarshall();
	}
	return 0;  
}