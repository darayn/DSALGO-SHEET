/*
Hasan has finally finished his final exams and he decided to go in a trip among cities in Syria.
There are N cities in Syria and they are numbered from 1 to N, each city has coordinates on plane, i-th city is in (Xi, Yi).
Hasan is in first city and he wants to visit some cities by his car in the trip but the final destination should be N-th city and the sequence of cities he will visit should be increasing in index (i.e. if he is in city i he can move to city j if and only if i < j ).
Visiting i-th city will increase Hasan's happiness by Fi units (including first and last cities), also Hasan doesn't like traveling too much, so his happiness will decrease by total distance traveled by him.
Help Hasan by choosing a sequence of cities to visit which maximizes his happiness.
Input format:
First line contain integer N.
Next N lines contains three integers each, i-th line contains coordinates of i-th city Xi, Yi and Fi.
Output format:
Output one number rounded to 6 digits after floating point, the maximum possible happiness Hasan can get. Note: If answer is 2 print 2.000000
Constraints:
1 <= N <= 3,000
0 <= Xi, Yi, Fi <= 100,000
Sample Input
3
0 0 1
3 1 1
6 0 9
Sample Output
4.675445
Explanation for the first test case:
According to the input, we have three coordinates: (0, 0), (3, 1) and (6, 0) and each of these coordinates have following happiness: 1, 1 and 9 respectively. 
Now, to get maximum happiness Hasan will start with (0, 0) and happiness of 1 units and he will travel from:
1. (0, 0) to (3, 1): This will increase its happiness by 1 and decrease it happiness by distance between these points, i.e. 3.162278 or square root of 10.
2. (3, 1) to (6, 0): This will increase its happiness by 9 and decrease it happiness by distance between these points, i.e. 3.162278 or square root of 10.

Hence, Hasan's happiness will be: 1 + 1 - 3.162278 + 9 - 3.162278 = 4.675445.

*/
#include<bits/stdc++.h>
using namespace std;
double distance(double * x, double * y, int i, int j){
	double difference_x = x[i] - x[j];
	double difference_y = y[i] - y[j];
	double ans =sqrt((difference_x*difference_x) + (difference_y* difference_y));
	return ans;
}
void maximum_happiness(double *x, double *y, double *z, int n){
	double *dp = new double [3030];
	for(int i=0;i<n;i++){
		dp[i] = INT_MIN;
	}
	dp[0] = 0;
	for(int i = 0;i<n;i++){
		dp[i] += z[i];
		for(int j=i+1;j<n;j++){
			double dist = distance(x,y,i,j);
			dp[j] = max(dp[j], dp[i] - dist);
		}
	}
	cout<<fixed;
	cout.precision(6);
	cout<< dp[n-1];
	delete [] dp;
}

int main(){
	int n;
	cin>>n;
	double *x = new double [3030];
	double *y = new double [3030];
	double *z = new double [3030];
	
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i]>>z[i];
	}
	maximum_happiness(x,y,z,n);
	delete [] x;
	delete [] y;
	delete [] z;
}
