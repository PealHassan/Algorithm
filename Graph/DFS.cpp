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


// for graph -> 
// time complexity is O(node + edge) -> O(node)
// space complexity ->  
// worst case O(node)
// average case O(log(node))
// best case O(1)

// uses of DFS
// 1. DFS is used for Depth First Search  
// 2. DFS uses Stack Data Structure
// 3. It travers children before siblings  
// 4. DFS is more suitable to find vertex far away from a vertex  
// 5. It is used to find the longest distance to a vertex from a source 
// 6. DFS uses the concept of backtracking.  
// 7. It requires less memory than bfs  
// 8. It also can be used to find cyclic detection  



ll cnt;  
vi travers[10000+1];
void dfs(ll node, vi& vis, vector<vector<int>>& graph) {
	vis[node] = true;  
	cnt++; 
	travers[node].pb(cnt);  
	for(ll i = 0; i<graph[node].size(); i++) {
		if(!vis[graph[node][i]]) dfs(graph[node][i],vis,graph);
	}
	cnt++;  
	travers[node].pb(cnt);   
	return;
}
void solve() {
  ll node, edge;  
  cin >> node >> edge;  
  vector<vector<int>> graph(node+1);
  loop(edge) {
  	ll x,y;  
  	cin >> x >> y;  
  	graph[y].pb(x);  
  	graph[x].pb(y);  
  }
  vi vis(node+1,0);
  dfs(1,vis,graph);
  for(ll i = 1; i<=node; i++) 
  	cout << i << " -> " << travers[i][0] << " " << travers[i][1] << endl;  

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