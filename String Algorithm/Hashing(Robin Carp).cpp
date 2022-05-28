#include <bits/stdc++.h> 
#define ll long long int
#define mod 10000007
using namespace std;
ll findHashValue(string s) {
	ll i = s.size(), l = 1, val = 0;  
	while(--i >= 0) {
		ll u = s[i] - 'a' + 1;  
		val += (u*l);
		l*=10;  
	}
	return val;
}
void RobinCarp() {
	string str, pattern;  
	cin >> str >> pattern;  
	ll val = findHashValue(pattern)%mod; 
	ll l = 0,q = 1;  
	for(ll i = 0; i+1<pattern.size(); i++) q *= 10;

	for(ll i = 0; i<str.size(); i++) {
		ll u = str[i]-'a' + 1;
		l*=10;
		l+=u;
		if(i>=pattern.size()-1 && val == (l%mod)) {
			ll flag = 1;
			for(ll u = 0, v = i-pattern.size()+1; u<pattern.size(); u++,v++) {
				if(pattern[u] != str[v]) {
					flag = 0;  
					break;
				}
			}
			if(flag) {
				cout << i-pattern.size()+2 << " " << i+1 << endl; 
			}
		} 
		if(i >= pattern.size()-1) {
			l-=(q*(str[i-pattern.size()+1]-'a'+1));
		}
	}
}  
int main() {
	RobinCarp();  
	return 0;  
}