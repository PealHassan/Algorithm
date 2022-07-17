#include<bits/stdc++.h>  
using namespace std;
struct point {
	int x, y;  
	point(int p, int q) {
		x = p;  
		y = q;   
	}
};
point originShift(point a, point b) { // measure point b respect to point 'a' as origin
	point c(b.x-a.x,b.y-a.y);
	return c;   
}
int crossProduct(point a, point b) {
	return (a.x*b.y)-(b.x*a.y);  
}
bool isLineSegmentIntersect(point a, point b, point c, point d) {
	int p = crossProduct(originShift(a,b),originShift(a,c));
	int q = crossProduct(originShift(a,b),originShift(a,d));  
	int r = crossProduct(originShift(c,d),originShift(c,a));  
	int s = crossProduct(originShift(c,d),originShift(c,b));  
	if(((p<0 && q>0) || (p>0 && q<0)) && ((r<0 && s>0) || (r>0 && s<0)))
		return true;  


	if(p == 0 && ((c.x>=a.x && c.x<=b.x) || (c.x>=b.x && c.x<=a.x)))  
		return true;  
	if(q == 0 && ((d.x>=a.x && d.x<=b.x) || (d.x>=b.x && d.x<=a.x)))  
		return true; 
	if(r == 0 && ((a.x>=c.x && a.x<=d.x) || (a.x>=d.x && a.x<=c.x)))  
		return true; 
	if(s == 0 && ((b.x>=c.x && b.x<=d.x) || (b.x>=d.x && b.x<=c.x)))  
		return true; 
	return false;  
}
int main() {
	int t;    
	cin >> t;  
	while(t--) {
		int p,q,r,s;  
		cin >> p >> q >> r >> s;  
		point a(p,q), b(r,s);  
		cin >> p >> q >> r >> s;    
		point c(p,q), d(r,s);  
		if(isLineSegmentIntersect(a,b,c,d)) 
			cout << "Line Segment Intersects." << endl;  
		else cout << "Doesn't Intersect." << endl;  
	}
	return 0;  
}