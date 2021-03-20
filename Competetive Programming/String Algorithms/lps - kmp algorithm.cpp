#include<bits/stdc++.h>
using namespace std;

int* getLps(string pattern){
	int len = pattern.length();
	int *lps = new int[len];
	lps[0] = 0;
	int i=1,j=0;
	while(i<len){
		if(pattern[i] == pattern[j]){
			lps[i] = j+1;
			j++;
			i++;
		}
		else{
			if(j!=0){
				j= lps[j-1];
			}
			else{
				lps[i] = 0;
				i++;
			}
		}
	}
	return lps;
}
bool kmpSearch(string text, string pattern){
	int lenText = text.length();
	int lenPat = pattern.length();
	int i=0,j=0;
	int *lps = getLps(pattern);
	while(i<lenText&& j<lenPat){
		if(text[i] == pattern[j]){
			i++;
			j++;
		}
		else{
			if(j!=0){
				j=lps[j-1];
			}
			else{
				i++;
			}
		}
	}
	if(j==lenPat){
		return true;
	}
	else{
		return false;
	}
}
int main()
{
	string s, sub;
	cin>>s>>sub;
	cout<<kmpSearch(s,sub)<<endl;
	return 0;
}

/* coding ninjas solution
// S and T - input strings
// You need to check if string T is present in S or not

#include <iostream>
using namespace std;
int *getLPS(string pattern)
{
    int n = pattern.length();
    int *lps = new int[n];
    lps[0] = 0;
    int i = 1;
    int j = 0;
    while (i < n)
    {
        if (pattern[i] == pattern[j])
        {
            lps[i] = j + 1;
            i++;
            j++;
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
int findKMP(string text, string pattern)
{
    int *lps = getLPS(pattern);
    int patternLen = pattern.length();
    int textLen = text.length();
    int i = 0, j = 0;
    while (i < textLen && j < patternLen)
    {
        if(text[i]==pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
            {
                i++;
            }
        }
    }
    return j==patternLen?i-j:-1;
}
int findString(char S[], char T[])
{
    //making string from the character arrays.
    string text="";
    string pattern="";
    for(int i=0; S[i]!='\0'; i++)
    {
        text+=S[i];
    }
    for(int i=0; T[i]!='\0'; i++)
    {
        pattern+=T[i];
    }
    return findKMP(text, pattern);
}

*/
