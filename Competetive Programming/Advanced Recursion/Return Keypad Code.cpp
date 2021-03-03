/*
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf

*/

#include <string>
using namespace std;


int keypad_code(string* arr,string* output,int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        int k=0;
        for(int i = 0;i<arr[0].size(); i++){
            output[k++] = arr[0][i];
        }
        return k;
    }
    int small_output_size = keypad_code(arr+1,output,n-1);
    int k = small_output_size;
     while(k<small_output_size*arr[0].size()){
		output[k++] = output[k - small_output_size];
         
     }  
    string s= "";
    int i = 0;
    while(i < arr[0].size()){
        int count = 0;
        while(count != small_output_size){
            s+= arr[0][i];
            count++;
        }
        i++;
    }
    for(int i=0; i<k; i++)
    {
        output[i]+=s[i];
    }
	return k;
} 
int keypad(int num, string output[]){
   	string* numbers = new string[10];
    numbers[0] = "";
	numbers[1] = "";
	numbers[2] = "abc";
	numbers[3] = "def";
	numbers[4] = "ghi";
	numbers[5] = "jkl";
	numbers[6] = "mno";
	numbers[7] = "pqrs";
	numbers[8] = "tuv";
	numbers[9] = "wxyz";
    int size = 0;
    int temp = num;
	while(temp!=0){
        size++;
        temp /= 10;
    }
    string *arr = new string[size];
    int k=0;
    while(num!=0){
        arr[k] = numbers[num%10];
        num/=10;
        k++;
    }
    return keypad_code(arr,output,size);
}

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}

	
