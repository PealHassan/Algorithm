#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
#define sz 1000009
#define pb push_back
#define mp make_pair
#define mod (ll)(1000000007)
#define in(x) scanf("%lld",&x)
#define ins(x) scanf("%s",x)
#define out(x) printf("%lld",x)
#define outs(x) printf("%s",x)
#define loop(x) for(ll i=0; i<x;i++)
#define loop2(x) for(ll j=0;j<x;j++)
#define eps 0.000000001
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define C 0.57721566490153286060651209
#define SORT(a) sort(a.begin(),a.end())
#define RSORT(a) sort(a.rbegin(),a.rend())
#define lb(a,x) lower_bound(a.begin(),a.end(),x)
#define ub(a,x) upper_bound(a.begin(),a.end(),x)
#define rev(a) reverse(a.begin(),a.end())
#define pi 3.141592653589793238
#define vi std::vector<ll>
#define vc std::vector<char>
#define vf std::vector<float>
#define vs std::vector<string>
#define vb std::vector<bool>
#define vpi std::vector<pair<ll,ll>>
#define mi std::map<ll, ll>
#define mmi std::multimap<ll,ll>
#define mmc std::multimap<char,ll>
#define mv std::map<ll, std::vector<ll>>
#define MIN(a) min_element(a.begin(),a.end())
#define MAX(a) max_element(a.begin(),a.end())
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
ll inputi() {ll x; std::cin >> x;return x;}
std::string inputs() {std::string x; std::cin >> x;return x;}
float inputf() {float x; std::cin >> x;return x;}
ll SUM(vi a) {ll sum = 0; loop(a.size()) sum+=a[i]; return sum;}
using namespace std;
using namespace __gnu_pbds;
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



void solve() {
  ll node, edge, source;  
  cin >> node >> edge >> source;   
  vi graph[node+1],cost[node+1];  
  vi dist(node+1,10e15); 
  dist[source] = 0;  
  loop(edge) {
  	ll x,y,c;   
  	cin >> x >> y >> c;  
  	graph[x].pb(y);  
  	graph[y].pb(x);  
  	cost[x].pb(c);  
  	cost[y].pb(c);
  }
  multiset<pair<ll,ll>>s;  
  s.insert({0,source});  
  while(s.size()) {
  	pair<ll,ll>p = *(s.begin());
  	s.erase(s.begin());
  	ll u = p.second;  
  	for(ll i = 0; i<graph[u].size(); i++) {
  		ll v = graph[u][i];  
  		if(dist[p.second] + cost[u][i] < dist[v]) {
  			dist[v] = dist[p.second] + cost[u][i];  
  			s.insert({dist[v],v});
  		}
  	}
  }
  loop(node) cout << i+1 << " " << dist[i+1] << endl;  
  return;
} 
int main()
{  
   fast;
   // ll  tt = 1;
   // cin >> tt;
   // while(tt--)
      solve();
   return 0;
}