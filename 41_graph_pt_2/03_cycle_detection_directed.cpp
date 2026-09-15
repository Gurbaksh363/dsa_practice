#include <iostream>
#include <list>
#include <vector>
#include <queue>
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

  bool cycleDetHelper(int node, vector<bool>& vis, vector<bool>& recPath){
    vis[node] = true;
    recPath[node] = true;

    for(int neigh: l[node]){
      if(!vis[neigh]){  // univisted -> vist
        if(cycleDetHelper(neigh, vis, recPath)) 
          return true;
      }
      else {
        if(recPath[neigh]) // curr path ch already visited -> true... parent is also observed.. because path to parent back is loop
          return true;
      }
    
    }
    recPath[node] = false;
    return false;
  }
  bool cycleDet(){
    vector<bool> vis(V, false);
    vector<bool> recPath(V, false);
    for(int i = 0; i<V; i++){
      if(!vis[i]){
        if(cycleDetHelper(i, vis, recPath)){
          return true;
        }
      }
    }
    return false;
  }
};

int main(){
  Graph g(5, false);
  g.addEdge(1, 0);
  g.addEdge(0, 2);
  g.addEdge(2, 3);
  g.addEdge(3, 0);
 
  
  cout<<g.cycleDet();

  return 0;
}