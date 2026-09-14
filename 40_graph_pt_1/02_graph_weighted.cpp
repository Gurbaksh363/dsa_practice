#include <iostream>
#include <list>
using namespace std;
// undirected wt.ed graph
class Graph{
  int V;
  list<pair<int, int>>* l;  // vertex, wt
  public:
  Graph(int v){
    V = v;
    l = new list<pair<int, int>> [V]; // storing in pairs
  }
  void addEdge(int u, int v, int wt){
    l[u].push_back(make_pair(v, wt));
    l[v].push_back(make_pair(u, wt));
  }

  void print(){
    for(int u = 0; u<V; u++){
      cout<<u<<" : ";
      list<pair<int, int>> neighbours = l[u];
      for(pair<int, int> v : neighbours){
        cout<<"("<<v.first<<", "<<v.second<<") ";
      }
      cout<<endl;
    }
  }


};
int main(){
   Graph graph(5);

  graph.addEdge(0, 1, 50);
  graph.addEdge(1, 2, 20);
  graph.addEdge(1, 3, 30);
  graph.addEdge(2, 3, 10);
  graph.addEdge(2, 4, 40);

  graph.print();
  return 0;
}