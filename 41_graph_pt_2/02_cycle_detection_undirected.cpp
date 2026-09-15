#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

class Graph{
  int V;
  list<int>* l;
  public:

  Graph(int V){
    this->V = V;
    l = new list<int> [V];
  }
  void addEdge(int u, int v){
    l[u].push_back(v);
    l[v].push_back(u);
  }

  bool cycleDetHelper(int node, vector<bool>& vis, int par){  // using dfs
    vis[node] = true;

    for(int neigh: l[node]){
      if(!vis[neigh]){
        if(cycleDetHelper(neigh, vis, node)) return true;
      }else{
        if(neigh!=par) return true;
      }
    }
    return false;
  }
  bool cycleDet(){
    vector<bool> vis(V, false);
    return cycleDetHelper(0, vis, -1);
  }
};

int main(){
  Graph g(5);
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  // g.addEdge(0, 2);
  g.addEdge(0, 3);
  g.addEdge(3, 4);
 
  
  cout<<g.cycleDet();

  return 0;
}