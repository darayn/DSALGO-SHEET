#include<bits/stdc++.h>
using namespace std;

void print_Duplicate(string str){
	map<char, int> counts;
	for(int i=0;i<str.length(); i++){
		counts[str[i]]++;
	}
	for(auto it: counts){
		if(it.second>1){
			cout<<it.first<<": count = "<<it.second<<'\n';
		}
		
	}
}
int main(){
	string str;
	cin>>str;
	print_Duplicate(str);
}
