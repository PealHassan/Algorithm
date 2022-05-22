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
// complexity -> O(E + V)

vi graph[1010],rgraph[1010],scc[1010];   
vb vis(1010,false),vis2(1010,false);   
stack<ll>s;  
ll mark;  
void dfs(ll node) {
	vis[node] = true;  
	for(ll i = 0; i<graph[node].size();  i++) {
		ll u = graph[node][i];  
		if(!vis[u]) {
			dfs(u);  
		}
	}
	s.push(node);
}
void dfs2(ll node) {
	vis2[node] = true;  
	scc[mark].pb(node);  
	for(ll i = 0; i<rgraph[node].size(); i++) {
		ll u = rgraph[node][i];  
		if(!vis2[u]) dfs2(u);
	}
}
void solve() {
  ll node, edge;  
  cin >> node >> edge;  
  loop(edge) {
  	ll x,y;  
  	cin >> x >> y;  
  	graph[x].pb(y); // x -> y;  
  	rgraph[y].pb(x);  
  }
  for(ll i = 1; i<=node; i++) if(!vis[i]) dfs(i);  
  while(s.size()) {
  	ll l = s.top();  
  	s.pop();  
  	if(!vis2[l]) {
  		dfs2(l);  
  		mark++;
  	}
  }
  cout << "Strongly Connected Component : " << mark << endl;
  for(ll i = 0; i<mark; i++) {
  	for(ll j = 0; j<scc[i].size(); j++)
  		cout << scc[i][j] << " ";  
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