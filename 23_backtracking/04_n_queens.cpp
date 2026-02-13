#include <iostream>
#include <vector>
using namespace std;

void printBoard(vector<vector<char>> board){
  int n = board.size();
  for(int i = 0; i<n; i++){
    for (int j= 0; j<n; j++){
      cout<<board[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<"--------------"<<endl;

}

bool isSafe(vector<vector <char>> board, int row, int col){
  // vertically 
  int n = board.size();
  for (int j=0; j<n; j++){
    if (board[row][j]=='Q')
      return false;
  }
  // horizontally 
  for(int i = 0; i<row; i++){
    if (board[i][col]=='Q')
      return false;
  }

  // left diagonally 
  for(int i =row, j= col; i>=0 && j>=0; i--, j--){
    if (board[i][j]=='Q')
      return false;
  }

  // right diagonally
  for(int i = row, j=col; i>=0 &&j<n; i--, j++){
    if (board[i][j]=='Q')
      return false;
  }
  return true;
  
}
int nQueens(vector<vector<char>> board, int row){
  if (row== board.size()){
    printBoard(board);
    return 1;
  }
  int count = 0;
  for(int j = 0; j< board.size(); j++){
    if (isSafe(board, row, j)==true){
      board[row][j] = 'Q';
      count += nQueens(board, row+1);
      board[row][j] = '.';
    }
  }
  return count;
}
int main(){
  vector<vector<char>> board;
  int n = 4;
  // creating board
  for (int i = 0; i<n; i++){
    vector<char> newRow;
    for (int j = 0; j<n; j++){
      newRow.push_back('.');
    }
    board.push_back(newRow);
  }
  // printBoard(board);
  int count = nQueens(board, 0);
  cout<<"Count: "<<count;
  return 0;
}