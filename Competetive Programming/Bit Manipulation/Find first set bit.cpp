/*
You are given an integer N. You need to return an integer M, in which only one bit is set which at position of lowest set bit of N (from right to left).
Input Format :
Integer N
Output Format :
Integer M
Sample Input 1 :
7
Sample Output 1 :
1
Sample Input 2 :
12
Sample Output 2 :
4

*/

#include <iostream>
using namespace std;

int returnFirstSetBit(int n){
    for(int i=0;i<=n;i++){
        if(n & (1<<i)){
            return (1<<i);
        }
        else{
            continue;
        }
    }
}


int main() {
	int n;

	cin >> n;
	
	cout<< returnFirstSetBit(n) <<endl;
		
	return 0;
}


