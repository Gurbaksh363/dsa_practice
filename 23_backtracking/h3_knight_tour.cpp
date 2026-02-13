// Question 3:
// Knight's Tour
// Given a N*N board with the Knight placed on the first block of an empty board. Moving
// according to the rules of chess, knights must visit each square exactly once. Print the order of
// each cell in which they are visited.

// Sample Input 1 : N = 8
// Sample Output 1:
// 0 59 38 33 30 17 8 63
// 37 34 31 60 9 62 29 16
// 58 1 36 39 32 27 18 7
// 35 48 41 26 61 10 15 28
// 42 57 2 49 40 23 6 19
// 47 50 45 54 25 20 11 14
// 56 43 52 3 22 13 24 5
// 51 46 55 44 53 4 21 12
// APNA
// COLLEGE
// (Hint : Similar to N Queens)

#include <iostream>
#include <vector>
using namespace std;

void printBoard(vector<vector<int>> board){
  int n=board.size();
  for(int i= 0; i<n; i++){
    for (int j= 0; j<n; j++){
      cout<<board[i][j]<<" ";
    }
    cout<<endl;
  }
}

bool isSafe(vector<vector<int>>& board, int x, int y){
  int n=board.size();
  return (x>=0 && x<n && y>=0 && y<n && board[x][y]==-1);
}

bool knightTourUtil(vector<vector<int>>& board, int x, int y, vector<int>& validX, vector<int>& validY,  int count){
  int n=board.size();
  board[x][y] = count++;
  if (count == (n*n)){
    printBoard(board);
    return true;
  }
  for(int i =0; i<validX.size(); i++){
      if (isSafe(board, x+validX[i], y+validY[i])){
        if(knightTourUtil(board, x+validX[i], y+validY[i], validX, validY, count)){
          return true;
        }
      }
  }
  board[x][y]=-1;
  return false;
}

void knightTour(int n){ 
  vector<vector<int>> board(n, vector<int> (n, -1));
  int count = 0;
  vector<int> validX = {2, 2, -2, -2, 1, 1, -1, -1};
  vector<int> validY = {1, -1, 1, -1, 2, -2, 2, -2};
  if (!knightTourUtil(board, 0, 0, validX, validY, count)){
    cout<<"No solution"<<endl;
  }
}
int main(){
  int n=5;
  knightTour(n);
  return 0;
}