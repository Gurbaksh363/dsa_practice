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
  void bfs(){  // O(V + E)
    queue<int> q;
    vector<bool> vis(V, false);
    q.push(0);
    vis[0] = true;

    while(!q.empty()){
      int curr = q.front();
      q.pop();

      cout<<curr<<" ";
      // neighbours push, vis
      for(int child: l[curr]){
        if(!vis[child]){
          vis[child] = true;
          q.push(child);
        }
      }
    }
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

  graph.bfs();
  return 0;
}