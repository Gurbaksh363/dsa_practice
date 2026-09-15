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
  bool isBipartite(){
    // vector<bool> vis(V, false);
    vector<int> color(V, -1);

    queue<int> q;
    q.push(0);
    // vis[0] = true;
    color[0] = 0;
    while(!q.empty()){
      int curr = q.front();
      q.pop();

      for(int neigh: l[curr]){
        // if(!vis[neigh]){
        if(color[neigh]==-1){
          // vis[neigh] = true;
          color[neigh] = !color[curr];
          q.push(neigh);
        }
        else{
          if(color[neigh]== color[curr]){
            return false;
          }
        }
      }
    }
    return true;

  }

};

int main(){
  // undirected and connected 
  Graph g(5);
  // non bipartite
  // g.addEdge(0, 1);
  // g.addEdge(0, 2);
  // g.addEdge(0, 3);
  // g.addEdge(1, 2);
  // g.addEdge(3, 4);

  // bipartite
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 3);
  g.addEdge(2, 3);

 
  
  cout<<g.isBipartite();

  return 0;
}