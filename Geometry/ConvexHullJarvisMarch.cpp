#include<bits/stdc++.h>  
using namespace std;
struct point {
	int x,y;  
};  
int n;
vector<point>points;  
int crossProduct(point a, point b, point c) {
	int val = (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
	if(val == 0) return 0;  
	return (val > 0)? 2 : 1;  
}
void convexHull() {
	if(n < 3) {
		cout << "No Convex Hull exists." << endl; 
		return;
	}
	int xmin = points[0].x, min = 0;  
	for(int i = 1; i<n; i++) {
		if(points[i].x < xmin) {
			xmin = points[i].x;  
			min = i;  
		}
	}
	vector<point>hull;
	int p = min;    
	do {
		hull.push_back(points[p]);
		int q = (p+1)%n;  
		for(int i = 0; i<n; i++) {
			if(crossProduct(points[p],points[q],points[i]) == 2)
				q = i;  
		}
		p = q;  
	}while(p != min);
	for(int i = 0; i<hull.size(); i++) {
		cout << "(" << hull[i].x << " " << hull[i].y << ")";
		if(i+1 < hull.size()) cout << " -> ";  
	}    
	cout << endl;  


}  
void input() {
	cin >> n;  
	for(int i = 0; i<n; i++) {
		int x,y;  
		cin >> x >> y;  
		point c;  
		c.x = x;  
		c.y = y;  
		points.push_back(c);  
	}
}
int main() {
	int t;  
	cin >> t; 
	while(t--) {
		input();  
		convexHull();  
		points.clear();  
	} 
	return 0;  
}