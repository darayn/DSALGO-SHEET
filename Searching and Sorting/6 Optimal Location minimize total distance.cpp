#include<bits/stdc++.h>
using namespace std;

#define sq(x) ((x) * (x))
#define EPS 1e-6
//#define N 5
struct point{
	int x, y;
	point() {}
	point(int a, int b){
		x = a;
		y = b;
	}
};

struct line{
	int a, b, c;
	line(int x, int y, int z){
		a = x;
		b = y;
		c = z;
	}
};

double dist(double x, double y, point p){
	return sqrt(sq(x-p.x) + sq(y-p.y));
}

double compute(point p[], int n, line l, double X){
	double res = 0;
	double Y = -1 * (l.c + l.a * X) / l.b;
	for(int i = 0;i< n;i++){
		res+= dist(X, Y, p[i]);
		
	}
	return res;
}

double findOptimumCostUtil(point p[], int n, line l){
	double low = -1e6;
	double high = 1e6;
	
	while((high - low) > EPS){
		double mid1 = low + (high - low) / 3;
		double mid2 = high - (high - low) / 3;
		
		double dist1 = compute(p, n, l, mid1);
		double dist2 = compute(p, n, l, mid2);
		
		if(dist1 < dist2){
			high = mid2;
		}
		else{
			low = mid1;
		}
	}
	
	return compute(p, n, l, (low + high) / 2);
}

double findOptimumCost(int points[][2], line l, int n){
	point p[n];
	
	for(int i=0; i < n;i++){
		p[i] = point(points[i][0], points[i][1]);
	}
	return findOptimumCostUtil(p,n, l);
}

int main(){
	int a,b,c;
	cout<<"Enter a, b, and c of line"<<endl;
	cin>>a>>b>>c;
	line l(a, b, c);
	cout<<"Enter the number of of points"<<endl;
	int n;
	cin>>n;
	int points[n][2];
	for(int i=0;i<n;i++){
		cin>>points[i][0]>>points[i][1];
	}
	cout<<findOptimumCost(points, l, n );
}
