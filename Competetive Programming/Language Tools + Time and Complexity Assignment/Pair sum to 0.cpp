/*
Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.
Note: Array A can contain duplicate elements as well.
Input format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output format :
The first and only line of output contains the count of pair of elements in the array which sum up to 0. 
Constraints :
0 <= N <= 10^4
Time Limit: 1 sec
Sample Input 1:
5
2 1 -2 2 3
Sample Output 1:
2

*/


#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

void pairSum(int *arr, int n)
{
    sort(arr, arr+n);
    int starting_position_of_positive_elements=0;
    while(arr[starting_position_of_positive_elements]<0)
    {
    	starting_position_of_positive_elements++;
	}
	map<int, int>m;
	for(int i=starting_position_of_positive_elements; i<n; i++)
	{
		m[arr[i]]+=1;
	}
	for(int i=0; i<starting_position_of_positive_elements; i++)
	{
        int temp=m[-arr[i]];
		if(temp>0)
		{
			while(temp--)
			{
				cout<<arr[i]<<" "<<-arr[i]<<endl;
			}
		}
	}
}
