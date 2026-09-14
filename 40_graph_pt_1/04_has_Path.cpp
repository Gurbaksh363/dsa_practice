#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

class Graph{
  public:
  int V;
  list<int> * l;
  Graph(int V){
    this->V = V;
    l = new list<int> [V];
  }
  void addEdge(int u, int v){
    l[u].push_back(v);
    l[v].push_back(u);
  }
  bool hasPathHelper(int src, int dest, vector<bool>& vis){
    if(src==dest) return true;

    vis[src] = true;

    for(int v: l[src]){
      if(!vis[v]){
        if(hasPathHelper(v, dest, vis)) return true;
      }
    }
    return false;
  }
  bool hasPath(int src, int dest){
    vector<bool> vis(V, false);
    return hasPathHelper(src, dest, vis);
  }
};
int main(){
  
  Graph graph(7);

  graph.addEdge(0, 1);
  graph.addEdge(0, 2);
  graph.addEdge(1, 3);
  graph.addEdge(2, 4);
  graph.addEdge(3, 4);
  graph.addEdge(3, 5);
  graph.addEdge(4, 5);
  graph.addEdge(5, 6);

  cout<<graph.hasPath(4, 1)<<endl;
  cout<<graph.hasPath(1, 10);
  return 0;
}