#include<bits/stdc++.h>  
using namespace std;
int n;  
vector<int> arr;   
void input() {
	cin >> n;  
	arr.clear();
	for(int i = 0; i<n; i++) {
		int x;  
		cin >> x;   
		arr.push_back(x); 
	}
} 
void merge(int begin, int mid, int end) {
	int l1 = mid-begin+1;  
	int l2 = end-mid;  
	int a1[l1],a2[l2]; 
	for(int i = 0,j = begin; i<l1; i++,j++)
		a1[i] = arr[j];
	for(int i = 0,j = mid+1; i<l2; i++,j++)
		a2[i] = arr[j];  
	int p = begin, i = 0, j = 0;
	for(; i<l1 && j<l2; ) {
		if(a1[i] <= a2[j]){
			arr[p] = a1[i];
			i++;
		}
		else {
			arr[p] = a2[j];  
			j++;
		}
		p++;  
	}
	while(i<l1) {
		arr[p] = a1[i];  
		i++; 
		p++;
	}
	while(j<l2) {
		arr[p] = a2[j];  
		j++;  
		p++;
	}

}
void mergeSort(int begin, int end) {
	if(begin < end) {
		int mid = (begin+end)/2; 
		mergeSort(begin,mid);  
		mergeSort(mid+1,end);
		merge(begin,mid,end);
	}
}
int main() {
	int t;  
	cin >> t;  
	while(t--) {
		input();  
		mergeSort(0,n-1);

		for(auto e: arr)
			cout << e << " ";  
		cout << endl;
	}
	return 0;  
}