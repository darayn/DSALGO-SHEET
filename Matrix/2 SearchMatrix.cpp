#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(int **m, int r, int c, int target){
	if(r==0|| c==0){
		return false;
	}
	int low = 0;
	int high = r-1;
	int mid;
	while(low<high){
		mid = (low+high) / 2;
		if(m[mid][c-1] < target){
			low = mid + 1;
		}
		else if(m[mid][0]> target){
			high = mid - 1;
		}
		else{
			low = mid;
			break;
		}
	}
	int probable_row = low;
	low = 0;
//	high = m[probable_row][c-1];
	high = c-1;
	
	while(low<=high){
		mid = (low + high) / 2;
		if(m[probable_row][mid] < target){
			low = mid + 1;
		}
		else if(m[probable_row][mid] > target){
			high = mid - 1;
		}
		else{
			return true;
		}
		return false;
	}
}
int main(){
	int r,c, target;
	cin>>r>>c>>target;
	int** M = new int* [r];
	for(int i=0;i<r;i++){
		M[i] = new int[c];
		for(int j=0;j<c;j++){
			cin>>M[i][j];
		}
	}
	cout<<searchMatrix(M, r, c, target);
}
