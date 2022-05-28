#include <bits/stdc++.h> 
using namespace std;
void kmp() {
	string str, pattern;  
	cin >> str >> pattern;  
	vector<int> lps(pattern.size()); 
	int prevLPS = 0, i = 1;  
	lps[0] = 0;
	while(i < pattern.size()) {
		if(pattern[prevLPS] == pattern[i]) {
			prevLPS++;  
			lps[i] = prevLPS;  
			i++;  
		}
		else if(prevLPS == 0) {
			lps[i] = 0;  
			i++;  
		}
		else prevLPS = lps[prevLPS-1];  
	}
	for(int i = 0, j = 0; i<str.size();) {
		if(str[i] == pattern[j]) {
			j++;
			i++;
		}
		if(j == pattern.size()) {
			cout << i-pattern.size()+1 << " " << i << endl;  
			j = lps[j-1];
		}
		else {
			while(str[i] != pattern[j]) {
				if(j == 0) {
					i++;  
					break;
				}
				j = lps[j-1];
			}
		}
	}
}
int main() {
	kmp();
	return 0;  
}