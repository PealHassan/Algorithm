#include<bits/stdc++.h>
using namespace std;
int n;  
vector<int>arr;  
void input() {
	cin >> n;  
	arr.clear();  
	for(int i = 0; i<n; i++) {
		int x; 
		cin >> x;   
		arr.push_back(x);  
	}
}  
int partition(int begin, int end) {
	int p = arr[end];
	int i = begin-1;    
	for(int j = begin; j < end; j++) {
		if(arr[j] < p) {
			i++;  
			swap(arr[i],arr[j]);  
		}
	}
	swap(arr[i+1],arr[end]);  
	return i+1;  
}
void quickSort(int begin,int end) {
	if(begin >= end) return;  
	int pivot = partition(begin,end);  
	quickSort(begin,pivot-1);  
	quickSort(pivot+1,end);
}
int main() {
	int t;  
	cin >> t;  
	while(t--) {
		input();
		quickSort(0,n-1);  
		for(auto e: arr)
			cout << e << " "; 
		cout << endl;
	}
	return 0;  
}