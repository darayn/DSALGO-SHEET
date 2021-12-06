#include<bits/stdc++.h>
using namespace std;
void solve(string s1, string s2, string res){
	int l1 = s1.length();
	int l2 = s2.length();
	int lr = res.length();
	
	if((l1+l2 != lr)){
		cout<<"No";
	}
	else{
		int i=0,j=0,k=0;
		while(k<lr){
			if(i<l1 && s1[i] == res[k]){
				i++;
			}
			else if(j<l2 && s2[j] == res[k]){
				j++;
			}
			else{
				break;
			}
			k++;
		}
		if(i<l2 || j< l2){
			cout<<"No";
		}
		else{
			cout<<"Yes";
		}
	}
}

int main(){
	string s1, s2, res;
	cin>>s1>>s2>>res;
	solve(s1, s2, res);
}
