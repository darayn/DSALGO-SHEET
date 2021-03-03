/*
CodingNinjas has provided a crossword of 10*10 grid. The grid contains '+' or '-' as its cell values. Now, you are also provided with a word list that needs to placed accurately in the grid. Cells marked with '-' are to be filled with word list.
For example, The following is an example for the input crossword grid and the word list.
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Output for the given input should be:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
Note: We have provided such test cases that there is only one solution for the given input.
Input format:
The first 10 lines of input contain crossword. Each of 10 lines has a character array of size 10. Input characters are either '+' or '-'.
The next line of input contains the word list, in which each word is separated by ';'. 
Output format:
Print the crossword grid, after placing the words of word list in '-' cells.  
Sample Test Cases:
Sample Input 1:
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Sample Output 1:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA

*/

#include<bits/stdc++.h>
using namespace std;
#define n 10
void printCrossboard(char cross[n][n]){
	for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<cross[i][j];
        }
        cout<<endl;
    }
     cout<<endl;
}
bool isValidVertical(char cross[n][n], int r, int c,string words){
    int j=r;
    for(int i=0;i<words.length();i++){
        if(j>9){
            return false;
        }
        if(cross[j][c]=='+' || (cross[j][c]!= '-' && cross[j][c]!= words[i])){
            return false;
        }
        if(cross[j][c]== '-' || cross[j][c]== words[i]){
            j++;
        }
    }
    return true;
}
bool isValidHorzontal(char cross[n][n], int r, int c,string words){
    int j=c;
    for(int i=0;i<words.length();i++){
        if(j>9){
            return false;
        }
        if(cross[r][j]=='+' || (cross[r][j]!= '-' && cross[r][j]!= words[i])){
            return false;
        }
        if(cross[r][j]== '-' || cross[r][j]== words[i]){
            j++;
        }
    }
    return true;
}

void setVertical(char cross[n][n], int r, int c,vector<bool>& t ,string words){
    int row =r;
    for(int i=0;i<words.length();i++){
        if(cross[row+i][c]=='-'){
            cross[row+i][c] = words[i];
            t.push_back(true);
            
        }
        else{
            t.push_back(false);
        }
    }
}
void resetVertical(char cross[n][n], int r, int c,vector<bool>& t){
    int row =r;
    for(int i=0;i<t.size();i++){
        if(t[i]){
            cross[row+i][c] = '-';
        }
    }
}

void setHorizontal(char cross[n][n], int r, int c,vector<bool>& t ,string words){
    int col =c;
    for(int i=0;i<words.length();i++){
        if(cross[r][col+i]=='-'){
            cross[r][col+i] = words[i];
            t.push_back(true);
            
        }
        else{
            t.push_back(false);
        }
    }
}
void resetHorizontal(char cross[n][n], int r, int c,vector<bool>& t){
    int col =c;
    for(int i=0;i<t.size();i++){
        if(t[i]){
            cross[r][col+i]  = '-';
        }
    }
}

bool crossword(char cross[n][n] ,vector<string> words,int index){
    if(index>=words.size()){
        printCrossboard(cross);
        return true;
    }
    for(int r=0;r<n;r++){
        for(int c=0;c<n;c++){
            if(cross[r][c] == '-' ||cross[r][c] == words[index][0] ){
                if(isValidVertical(cross,r,c,words[index])){
                    vector<bool> helper;
                    setVertical(cross, r,c, helper,words[index]);
                    if(crossword(cross,words,index + 1)){
                        return true;
                    }
                    resetVertical(cross, r,c, helper);
                }
                if(isValidHorzontal(cross,r,c,words[index])){
                    vector<bool> helper;
                    setHorizontal(cross,r,c,helper, words[index]);
                    if(crossword(cross,words,index + 1)){
                        return true;
                    }
                    resetHorizontal(cross,r,c,helper);
                    
                }
            }
        }
    }
    return false;
}


int main() {
	char arr[n][n];
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<n;j++){
            arr[i][j] = s[j];
        }
    }
    string s;
    cin>>s;
    vector<string> words;
    for(int i=0;i<s.length();i++){
        int j=i;
        while(s[j]!=';'&&j<s.length()){
            j++;
        }
        words.push_back(s.substr(i,j-i));
        i=j;
        j++;
    }
    bool x = crossword(arr,words,0);
}

