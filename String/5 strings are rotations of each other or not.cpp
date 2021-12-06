#include<bits/stdc++.h>
using namespace std;

bool areRotations(string str1, string str2){
	if(str1.length() != str2.length()){
		return false;
	}
	string temp = str1 + str1;
	return (temp.find(str2) != string::npos);
}

bool check_Rotations(string str1, string str2){
	
	if(str1.size() != str2.size()){
		return false;
	}
	queue<char> q1,q2;
	
	for(int i=0;i<str1.size();i++){
		q1.push(str1[i]);
	}
	
	for(int i=0;i<str2.size();i++){
		q2.push(str2[i]);
	}
	int k = str2.size();
	while(k--){
		char ch = q2.front();
		q2.pop();
		q2.push(ch);
		if(q2 == q1){
			return true;
		}
	}
	return false;
}


int main(){
	string s1,s2;
	cin>>s1>>s2;
	bool ans = areRotations(s1,s2);
	if(ans){
		cout<<"Strings are rotations of each other"<<endl;
	}
	else{
		cout<<"Strings are not rotations of each other"<<endl;
	}
	return 0;
}
