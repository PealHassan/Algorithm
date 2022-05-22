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
vi graph[1010],isArticulationPoint(1010,0);
vi dis(1010),low(1010),parent(1010);
vb vis(1010,false);   
ll cnt;
// root is always  1   
void articulationPointFind(ll node) {
	cnt++;  
	dis[node] = cnt;  
	low[node] = cnt; 
	vis[node] = true; 
	ll children = 0;  
	for(ll i = 0; i<graph[node].size(); i++) {
		ll u = graph[node][i];  
		if(u == parent[node]) continue;
		if(!vis[u]) {
			children++;  
			parent[u] = node;
			articulationPointFind(u);  
			low[node] = min(low[node],low[u]);
		}
		else if(vis[u]) low[node] = min(low[node],low[u]);
		if(dis[node] <= low[u] && node != 1) { 
			// root is vertex 1
			isArticulationPoint[node] = 1;  
		}
	}
	if(children>1 && node == 1) isArticulationPoint[1] = 1;
}
void solve() {
  ll node, edge;  
  cin >> node >> edge;  
  loop(edge) {
  	ll x,y;  
  	cin >> x >> y;  
  	graph[x].pb(y);  
  	graph[y].pb(x);
  }
  articulationPointFind(1);  
  vi articulationPoint;
  for(ll i = 1; i<=node; i++) if(isArticulationPoint[i]) articulationPoint.pb(i);
  cout << "Articulation Point : " << articulationPoint.size() << endl;  
  for(ll i = 0; i<articulationPoint.size(); i++) 
  	cout << articulationPoint[i] << " ";  
  cout << endl; 
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