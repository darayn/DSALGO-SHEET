/*
You are given N, and for a given N x N chessboard, find a way to place N queens such that no queen can attack any other queen on the chess board. A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
Input Format :
Line 1 : Integer N
Output Format :
One Line for every board configuration. 
Every line will have N*N board elements printed row wise and are separated by space
Note : Don't print anything if there isn't any valid configuration.
Constraints :
1<=N<=10
Sample Input 1:
4
Sample Output 1 :
0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 

*/

 #include<iostream>
using namespace std;

bool isSafe(int board[][10],int i,int j, int n){
	//You can check for column
	for(int row = 0;row<i;row ++){
		if(board[row][j] == 1){
			return false;
		}
	}
	//You can check for left diagonal
	int x = i;
	int y= j;
	
	while(x>=0&&y>=0){
		if(board[x][y]==1){
			return false;
		}
		x--;
		y--;
	}
	//You can check for left diagonal
	x = i;
	y= j;
	
	while(x>=0&& y<=n){
		if(board[x][y]==1){
			return false;
		}
		x--;
		y++;
	}
	
	// The Position is safe;
	
	return true;
	
}

bool solveNQueen(int board[][10], int i,int n){
	//	Base case
	if(i==n){
		//you have succesfully placed queens in a rows (0..,n-1)	
		//Print the board;
		for(int i=0; i<n;i++){
			for(int j = 0;j<n;j++){
				if(board[i][j] == 1){
					cout<<"1 ";
				}
				else{
					cout<<"0 ";
				}
			}
			
		}
		cout<<endl;
		return false;
		
	}
	//recursive case
	//try to place queen in curent row and call on the remaining part which will bw solved by recursuve call
	for(int j=0;j<n;j++){
		//I have to check i,j, is safe to place the queen or not
		 if(isSafe(board,i,j,n)){
		 	board[i][j] = 1;
		 	bool nextQueenRakhPaye = solveNQueen(board,i+1,n);
		 	if(nextQueenRakhPaye){
		 		return true;
			 }
			 //means i, j  is in right position
			 board[i][j] = 0;
		 }
	}
	//you have tries for all the positions int he current row but could find it
	return false;
}
void placeNQueens(int n){

	int board[10][10] = {0};
	
	solveNQueen(board,0,n);
}



int main(){

  int n; 
  cin >> n ;
  placeNQueens(n);

}



