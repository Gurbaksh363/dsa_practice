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
  void dfsHelper(int node, vector<bool>& vis){
    vis[node] = true;
    cout<<node<<" ";

    for(int neigh: l[node]){
      if(!vis[neigh]){
        dfsHelper(neigh, vis);
      }
    }
  }
  void dfs(){ 
    vector<bool> vis(V, false);
    for(int i = 0; i<vis.size(); i++){
      if(!vis[i]){
        dfsHelper(i, vis);
        cout<<endl;
      }
    }
  }
  void bfsHelper(int node, vector<bool>& vis){
    queue<int> q;
    q.push(node);
    vis[node] = true;
    while(!q.empty()){
      int curr = q.front();
      q.pop();
      cout<<curr<<" ";

      for(int neigh: l[curr]){
        if(!vis[neigh]){
          vis[neigh] = true;
          q.push(neigh);
        }
      }
    }
  }
  void bfs(){
    vector<bool> vis(V, false);
    for(int i = 0; i<vis.size(); i++){
      if(!vis[i]){
        bfsHelper(i, vis);
        cout<<endl;
      }
    }
  }

};

int main(){
  Graph g(10);
  g.addEdge(0, 2);
  g.addEdge(2, 5);
  g.addEdge(1, 6);
  g.addEdge(6, 4);
  g.addEdge(4, 3);
  g.addEdge(4, 9);
  g.addEdge(3, 7);
  g.addEdge(3, 8);
  
  g.dfs();
  cout<<endl;
  g.bfs();
  return 0;
}