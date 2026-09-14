#include <iostream>
#include <vector>
#include <list>
using namespace std;

// undirected graph
class Graph{
  public:
  int V;
  list<int>* l; // int* arr.... list<int>* arr;
  public:
  Graph(int V){
    this->V = V;
    l = new list<int> [V];
  }
  void addEdge(int u, int v){
    l[u].push_back(v);
    l[v].push_back(u);
  }
  void print(){
    for(int u = 0; u<V; u++){
      list<int> neighbours = l[u];
      cout<<u<<" : ";
      for(int v: neighbours){
        cout<<v<<" ";
      }
      cout<<endl;
    }
  }
};
int main(){
  Graph graph(5);

  graph.addEdge(0, 1);
  graph.addEdge(1, 2);
  graph.addEdge(1, 3);
  graph.addEdge(2, 3);
  graph.addEdge(2, 4);

  graph.print();
  return 0;
}