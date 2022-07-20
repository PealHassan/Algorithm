#include<bits/stdc++.h> 
#define MXN 1010 
using namespace std;
int node, edge;
int cost[MXN][MXN];      
void input() {
	cin >> node >> edge;
	for(int i = 0; i<=node; i++)
		for(int j = 0; j<=node; j++) {
			cost[i][j] = 2e9, cost[j][i] = 2e9;
			if(i == j) cost[i][j] = 0;  
		}

	for(int i = 0; i<edge; i++) {
		int x,y,c;    
		cin >> x >> y >> c;  
		cost[x][y] = c;  
		cost[y][x] = c; 
	}
}  
void floyWarshall() {
	for(int i = 1; i<=node; i++) {
		for(int j = 1; j<=node; j++) {
			for(int k = 1; k<=node; k++) {
				if(cost[j][i] + cost[i][k] < cost[j][k]) {
					cost[j][k] = cost[j][i] + cost[i][k];  
				}
			}
		}
	}
	for(int i = 1; i<=node; i++) {
		for(int j = 1; j<=node; j++) {
			cout << cost[i][j] << " ";  
		}
		cout << endl;  
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