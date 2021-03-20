#include<bits/stdc++.h>
using namespace std;
void buildZ(int* z, string str){
	int l = 0, r= 0;
	int n = str.length();
	for(int i=1;i<n;i++){
		
		if(i>r){
			//i does not lie between l  anr r
			// z for this doesnt exist
			l = i;
			r= i;
			while(r<n && str[r-l] == str[r]){
				r++;
			}
			z[i] = r-l;
			r--;
		}
		else{
			int k = i-l;
			if(z[k] <= r-i){
				// it lies between l and r
				// z will exist previusly
				z[i] = z[k];
			}
			else{
				// some part of z already included
				// you have to start matching further
				l=i;
				while(r<n&& str[r-l] == str[r]){
					r++;
				}
				z[i] = r-l;
				r--;
			}
		}
	}
}
void searchString(string text, string pattern){
	string str = pattern + "$"  + text;
	int n = str.length();
	int * Z =new int[n];
	buildZ(Z,str);
	for(int i=0;i<n;i++){
		if(Z[i] == pattern.length()){
			cout<<i-pattern.length()-1<<" ";
		}
	}
}
int main(){
	string text, pattern;
	cin>>text>>pattern;
	searchString(text, pattern);
}
