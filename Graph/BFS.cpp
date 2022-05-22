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
// in graph ->
// time complexity O(node + edge) -> O(node^2)
// memory complexity
// worst case O(node)
// average case O(2^(log(node)))
// best case O(1)

// in Tree ->  
// time complexity O(node + edge) -> O(node)
// memory complexity O(node);


// Uses of BFS ->  
// 1. BFS stands for Breadth First Search   
// 2. BFS used queue data structure for finding the shortest path
// 3. BFS is used for finding the single source shortest path in a unweighted graph
// 4. Here Siblings are visited before children
// 5. BFS requires more memory  
// 6. BFS is used in bipartite graph and shortest path
// 7. BFS is more suitable to find vertices closer to given source
// 9. It is performed on a graph level by level
// 10. It is useful to decrease the height of the tree.
// 11. It can be used for cycle detection

// Algorithm -> 

void solve() {
  ll node, edge;  
  cin >> node >> edge;  
  vi graph[node+1];
  loop(edge) {
  	ll x, y ;  
  	cin >> x >> y;  
  	graph[x].pb(y);  
  	graph[y].pb(x);  
  }
  queue<ll>q;  
  vi vis(node+1,0),parent(node+1),level[node+1],lev(node+1);
  vis[1] = 1;  
  q.push(1);  
  parent[1] = 1;  
  level[0].pb(1);     
  while(!q.empty()) {
  	ll l = q.front();  
  	q.pop();  
  	for(ll i = 0; i<graph[l].size(); i++) {
  		ll u = graph[l][i];  
  		if(!vis[u]) {
  			vis[u] = true; 
  			lev[u] = lev[l] + 1;  
  			level[lev[u]].pb(u);   
  			parent[u] = l;
  			q.push(u);  
  		}
  	}
  }
  ll i = 0;  
  while(level[i++].size()) {
  	for(ll j = 0; j<level[i-1].size(); j++)
  		cout << level[i-1][j] <<  " ";  
  	cout << endl;  
  }
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