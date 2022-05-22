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
vi graph[1010];
vi degree(1010,0);  
ll vis[1010][1010];
ll src = 1;  
vpi path;  
ll n,edge;
bool isBridge(ll u, ll v) {
   queue<ll>q;  
   q.push(u);  
   vi vis2(1010,0);  
   vis2[u] = 1; 
   ll cnt = 1; 
   while(q.size()) {
      ll l = q.front();  
      q.pop();  
      for(ll i = 0; i<graph[l].size(); i++) {
         ll x = graph[l][i];  
         if(vis[x][l] == 0 && !(x == u && l == v) && !(x == v && l == u) && !vis2[x]) {
            vis2[x] = 1;  
            q.push(x);
            cnt++;
         }
      }
   }
   if(cnt == n) return false;  
   return true;
}
void Euler(ll node) {
   if(path.size() == edge) return;
   vi bridge;
	for(ll i = 0; i<graph[node].size(); i++) {
		ll u = graph[node][i];  
		if(isBridge(node,u)) bridge.pb(u);
      else if(!vis[node][u]){
         vis[node][u] = 1;  
         vis[u][node] = 1;  
         path.pb({node,u});
         degree[u]--;  
         degree[node]--;  
         if(degree[u] == 0) n--;  
         if(degree[node] == 0) n--;  
         Euler(u);  
         return;
      }
	}
   vis[node][bridge[0]] = 1;
   vis[bridge[0]][node] = 1;  
   path.pb({node,bridge[0]});
   degree[bridge[0]]--;  
   degree[node]--;  
   if(degree[bridge[0]] == 0) n--;  
   if(degree[node] == 0) n--;  
   Euler(bridge[0]);  
   return;
}
void solve() { 
  cin >> n >> edge;  
  loop(edge) {
  	ll x,y;  
  	cin >> x >> y;  
  	degree[x]++;  
  	degree[y]++;  
  	graph[x].pb(y);  
  	graph[y].pb(x);
  }
  ll cnt = 0;  
  for(ll i = 1; i<=n; i++) if(degree[i]%2) {
  	src = i;  
  	cnt++;  
  } 
  if(cnt == 0 || cnt == 2) {
   Euler(src);
   for(ll i = 0; i<edge; i++) {
      if(i>0) cout << " -> ";  
      cout << "{" << path[i].first << "," << path[i].second << "}";
   }
   cout << endl; 
  	return;  
  }
  cout << "Euler Doesn't Exist.." << endl; 
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