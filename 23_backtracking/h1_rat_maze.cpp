// Question 1:
// Rat in a Maze
// You are given a starting position for a rat which is stuck in a maze at an initial point (0, 0) (the
// maze can be thought of as a 2-dimensional plane). The maze would be given in the form of a
// square matrix of order N * N where the cells with value 0 represent the maze's blocked
// locations while value 1 is the open/available path that the rat can take to reach its destination.
// The rat's destination is at (N - 1, N - 1).

// Your task is to find all the possible paths that the rat can take to reach from source to
// destination in the maze.
// The possible directions that it can take to move in the maze are 'U'(up) i.e. (x, y - 1), 'D'(down)
// i.e. (x, y + 1), 'L' (left) i.e. (x - 1, y), 'R' (right) i.e. (x + 1, y).
// (This problem is similar to Grid ways.)

// Sample Input: int maze[ ][ ] = { { 1, 0, 0, 0 },
// {1, 1, 0, 1},
// {1, 1, 0, 0 },
// { 0, 1, 1, 1 } };

// Sample Output :
// DDRDRR
// DRDDRR

// Hint : To track which cell has or not been visited, create a NxN vector called visited.
// This vector will be initialized with false values for all cells & make the value for a particular
// cell to true when you have visited it.

#include <iostream>
using namespace std;

void printMaze(int maze[][4]){
  for(int i=0; i<4; i++){
    for(int j=0; j<4; j++){
      cout<<maze[i][j]<<" ";
    }
    cout<<endl;
  }
}

bool isSafe(int maze[][4], int x, int y, int n, bool visited[][4]){
  return (x>=0 && x<n &&
          y>=0 && y<n &&
          maze[x][y]==1 &&
        !visited[x][y]);
}

void solveMazeUtil(int maze[][4], int x, int y, int n, string ans,  bool visited[][4]){
  if (x==n-1 && y==n-1 && maze[x][y]==1){
    cout<<ans<<endl;
    return;
  }

  visited[x][y] = true;
  // left
  if (isSafe(maze, x, y-1, n, visited)){
    solveMazeUtil(maze, x, y-1, n, ans+"L", visited);
  }
  // down
  if(isSafe(maze, x+1, y, n, visited)){
    solveMazeUtil(maze, x+1, y, n, ans+"D", visited);
  }
  // right
  if(isSafe(maze, x, y+1, n, visited)){
    solveMazeUtil(maze, x, y+1, n, ans+"R", visited);
  }
  // up
  if(isSafe(maze, x-1, y, n, visited)){
    solveMazeUtil(maze, x-1, y, n, ans+"U", visited);
  }
  visited[x][y] = false;
}

void solveMaze(int maze[][4], int n){
  string ans ="";
  bool visited[4][4] = {false};

  if (maze[0][0]==1){
    solveMazeUtil(maze, 0, 0, n, ans, visited);
  }

}

int main(){
  int n = 4;
  int maze[4][4] = { { 1, 0, 0, 0 },
                    {1, 1, 0, 1},
                    {1, 1, 0, 0 },
                    { 0, 1, 1, 1 } };


  printMaze(maze);
  solveMaze(maze, n);
  return 0;
}