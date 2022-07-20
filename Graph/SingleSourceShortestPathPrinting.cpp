// psuedo code ->   
// procedure dijkstra(G,source,cost):  
// 	Q = priority_queue(), distance[] = infinity
// 	distance[source] = 0  
// 	Q.enqueue({distance[source],source})
// 	while Q is not empty 
// 		u = nodes in Q with minimum distance
// 		remove u from Q  
// 		for all edges from u to v in G do  
// 			if distance[u] + cost[u][v] < distance[v]
// 				distance[v] = distance[u] + cost[u][v]
// 				Q.enqueue({distance[v],v})
// 			end if
// 		end for  
// 	end while  
// 	return distance

// time complexity -> O(ElogV + V) -> O(node^2)
// uses for Dijkstra:  
// 1. It is used to find single source shortest path in weighted or unweighted graph



#include<bits/stdc++.h>
#define MXN 1010  
#define inf 2e9+7
using namespace std;
vector<int> graph[MXN],cost[MXN],path(MXN);  
int node,edge;   
void input() {
   cin >> node >> edge ;  
   for(int i = 0; i<=node; i++) path[i] = -1;  
   path[1] = 1;   
   for(int i = 0; i<edge; i++) {
      int x,y,c;  
      cin >> x >> y >> c;  
      if(x == 1) path[y] = 1;  
      if(y == 1) path[x] = 1;  
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
            path[u] = l;  
            s.insert({dist[u],u});  
         }
      }
   }
   for(int i = 1; i<=node; i++) {
      cout << "Cost for " << i << " is :  " << dist[i] << endl;
      cout << "Path is : ";  
      int u = i;  
      while(u != 1) {
         cout << u << " -> ";  
         u = path[u];
      } 
      cout << 1 << endl;  
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