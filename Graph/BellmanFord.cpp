#include<bits/stdc++.h>
#define MXN 1010
using namespace std;
int cost[MXN][MXN];
int node, edge;
vector < pair<int, int> > edges;
void input() {
	memset(cost, 0, sizeof(cost));
	edges.clear();
	cin >> node >> edge;
	for (int i = 0; i < edge; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		cost[x][y] = c;
		cost[y][x] = c;
		edges.push_back({x, y});
	}
}
void bellmanFord() {
	vector<int> dist(node + 1, 2e9 + 7);
	dist[1] = 0;
	for (int i = 0; i < node - 1; i++) {
		for (int j = 0; j < edge; j++) {
			int u = edges[j].first;
			int v = edges[j].second;
			if (dist[u] + cost[u][v] < dist[v])
				dist[v] = dist[u] + cost[u][v];
			if (dist[v] + cost[v][u] < dist[u])
				dist[u] = dist[v] + cost[v][u];
		}
	}
	for (int i = 0; i < edge; i++) {
		int u = edges[i].first;
		int v = edges[i].second;
		if (dist[u] + cost[u][v] < dist[v]) {
			cout << "Negative Cycle Detected" << endl;
			for (int i = 1; i <= node; i++) {
				cout << i << " " << dist[i] << endl;
			}
			return;
		}
		if (dist[v] + cost[v][u] < dist[u]) {
			cout << "Negative Cycle Detected" << endl;
			for (int i = 1; i <= node; i++) {
				cout << i << " " << dist[i] << endl;
			}
			return;
		}
	}
	for (int i = 1; i <= node; i++) {
		cout << i << " " << dist[i] << endl;
	}

}
int main() {
	int t;
	cin >> t;
	while (t--) {
		input();
		bellmanFord();
	}
}