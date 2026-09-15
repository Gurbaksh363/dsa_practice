#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class Graph{
  int V;
  list<int>* l;
  bool isUndir;
  public:

  Graph(int V, bool isUndir=true){
    this->V = V;
    l = new list<int> [V];
    this->isUndir = isUndir;
  }
  void addEdge(int u, int v){
    l[u].push_back(v);
    if(isUndir)
      l[v].push_back(u);
  }
  void printAllPathsHelper(int src, int dest, vector<bool>& vis, string& path){
    if(src==dest){
      cout<<path<<dest<<endl;
      return;
    }
    vis[src] = true;
    path += to_string(src);

    for(int neigh: l[src]){
      if(!vis[neigh]){
        printAllPathsHelper(neigh, dest, vis, path);
      }
    }
    vis[src] = false;
    path.pop_back();
  }
  void printAllPaths(int src, int dest){
    vector<bool>vis(V, false);
    string str = "";
    printAllPathsHelper(src, dest, vis, str);

  }

};

int main(){
  Graph g(6, false);
  g.addEdge(0, 3);
  g.addEdge(2, 3);
  g.addEdge(3, 1);
  g.addEdge(4, 0);
  g.addEdge(4, 1);
  g.addEdge(5, 0);
  g.addEdge(5, 2);

  g.printAllPaths(5, 1);
 
  return 0;
}