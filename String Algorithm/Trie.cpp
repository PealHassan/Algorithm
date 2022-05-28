#include <bits/stdc++.h>
using namespace std;
struct node {
	bool ending = false;  
	node *next[100];
};
struct Trie {
	node *root;  
	void insert(string&);
	bool find(string&);
	void Delete(string&);
	void showAll(string&);
	void Traverse(node*,string&);
};
void Trie::insert(string& x) {
	node *cur;  
	if(root == NULL) root = new node();
	cur = root; 
	int len = x.size();
	for(int i = 0; i<len; i++) {
		node *temp = new node();
		int p = x[i] - 'a';  
		if(cur->next[p] == NULL) 
			cur->next[p] = temp;  
		cur = cur->next[p];
		if(i == len-1) 
			cur->ending = true;
	}
}
void Trie::Traverse(node *cur,string& y) {
	for(int i = 0; i<100; i++) {
		if(cur->next[i] != NULL) {
			char p = 'a'+i;
			string z = y + p;
			if(cur->next[i]->ending)
				cout << z << endl;
			Traverse(cur->next[i],z);
		}
	}
}
void Trie::showAll(string& x) {
	if(root == NULL) return;
	node *cur = root,*temp;
	int len = x.size();
	string y = "";
	for(int i = 0; i<len; i++) {
		int u = x[i] - 'a';  
		y+=x[i];
		if(cur->next[u] == NULL) 
			return;
		if(i == len-1) {
			temp = cur->next[u];
			break;
		}
		cur = cur->next[u];
	}
	if(temp->ending) cout << y << endl;  
	Traverse(temp,y);

}
void Trie::Delete(string& x) {
	if(root == NULL) return;
	node *cur = root;  
	int len = x.size();
	for(int i = 0; i<len; i++) {
		int u = x[i] - 'a';  
		if(cur->next[u] == NULL) 
			return;
		if(i == len-1 && cur->next[u]->ending) {
			cur->next[u]->ending = false;
			return;
		}
		cur = cur->next[u];
	}
}
bool Trie::find(string& x) {
	if(root == NULL) return false;
	node *cur = root;  
	int len = x.size();
	for(int i = 0; i<len; i++) {
		int u = x[i] - 'a';  
		if(cur->next[u] == NULL) 
			return false;
		if(i == len-1 && cur->next[u]->ending)
				return true;
		cur = cur->next[u];
	}
	return false;
}

int main() {
	Trie *trie = new Trie();  
	int n;  
	cin >> n;  
	for(int i = 0; i<n; i++) {
		string x;  
		cin >> x;  
		trie->insert(x);
	}
	string x = "aa";
	trie->showAll(x);
	
	return 0;  
}