/*
Given two strings S and T, write a function to find if T is present as a substring inside S or not. If yes, return the starting index otherwise return -1.
Input format :

Line 1 : String S

Line 2 : String T

Sample Input 1:
WelcomeBack
come 
Sample Output 1:
3
Sample Input 2:
WelcomeBack
code
Sample Output 2:
-1

*/

// S and T - input strings
// You need to check if string T is present in S or not
#include<bits/stdc++.h>
using namespace std;

int* getLPS(string pattern){
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


int findKMP(string text, string pattern){
    int *lps = getLPS(pattern);
    int patternLen = pattern.length();
    int textLen = text.length();
    int i=0,j=0;
    while(i<textLen && j< patternLen){
        if(text[i] == pattern[j]){
            i++;
            j++;
        }
        else{
            if(j!=0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    return j==patternLen?i-j : -1;
}
int findString(char s[], char T[]) {
    string text = "";
    string pattern = "";
    
    for(int i=0;s[i]!='\0';i++){
        text += s[i];
    }
    for(int i=0;T[i]!='\0';i++){
        pattern += T[i];
    }
    return findKMP(text, pattern);

}

int main() {
    char S[1000], T[1000];
    cin.getline(S, 1000);
    cin.getline(T, 1000);
    cout << findString(S, T) << endl;
}

