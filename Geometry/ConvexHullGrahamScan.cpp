#include<bits/stdc++.h>  
using namespace std; 
struct point {
	int x,y;  
};  
int n;  
vector < point > points;
void swap(point &a, point &b) {
	point c = a;  
	a = b;  
	b = c; 
}
// 2 -> counterclockwise
// 1 -> clockwise
int crossProduct(point a, point b, point c) {
	int val = (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
	if(val == 0) return 0;  
	return (val > 0)? 2 : 1; 
}
int dist(point a, point b) {
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y); 
}
bool cmp(point a, point b) {
	int val = crossProduct(points[0],a,b);
	if(val == 0) {
		return (dist(points[0],b) >= dist(points[0],a)) ? true : false;
	}
	return (val == 2) ? true : false;  
}
point nextToTop(stack <point>& a) {
	point b = a.top();  
	a.pop();  
	point res = a.top();  
	a.push(b);  
	return res;
}
void convexHull() {
	int ymin = points[0].y, min = 0;  
	for(int i = 1; i < n; i++) {
		if(points[i].y < ymin) {
			ymin = points[i].y;  
			min = i;  
		}
		else if(points[i].y == ymin && points[i].x < points[min].x) {
			min = i;  
		} 
	}
	swap(points[0],points[min]);  
	sort(points.begin()+1,points.end(),cmp);
	vector < point > new_points(n);  
	new_points[0] = points[0];
	int m = 1;    
	for(int i = 1; i<n; i++) {
		while(i+1 < n && crossProduct(points[0],points[i],points[i+1]) == 0)
			i++;
		new_points[m] = points[i];  
		m++;  
	}
	if(m < 3) {
		cout << "No Convex Hull exists." << endl;  
		return;
	}
	stack < point > s;  
	s.push(new_points[0]);  
	s.push(new_points[1]);  
	s.push(new_points[2]);
	for(int i = 3; i<m; i++) {
		while(s.size() > 1 && crossProduct(nextToTop(s),s.top(),new_points[i]) != 2)
			s.pop();  
		s.push(new_points[i]);
	}
	while(s.size()) {
		cout << "(" << s.top().x << " " << s.top().y << ")";
		s.pop();  
		if(s.size()) cout << " -> ";  
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