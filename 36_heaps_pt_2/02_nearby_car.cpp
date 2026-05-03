// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).
// The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Car{
  public:
  int idx;
  int distSq;
  Car(int idx, int distSq){
    this->idx = idx;
    this->distSq = distSq;
  }
  bool operator < (const Car& obj) const{
    return this->distSq > obj.distSq;
  }
};
void nearByCar(vector<pair<int,int>> pos, int K){    // O(k logn + n)
  vector<Car> cars;
  for(int i=0; i<pos.size(); i++){  // O(n)
    int distSq = pos[i].first * pos[i].first + pos[i].second * pos[i].second;
    cars.push_back(Car(i, distSq));
  }
  priority_queue<Car> pq(cars.begin(), cars.end()); // O(n)     // special shortcut
  // if we don't use above method it will take O(n log n) to build a heap... so what is the benefit???
 
  for(int i = 0; i<K; i++){              // O(K * logn)
    cout<< "car: "<<pq.top().idx<<endl;
    pq.pop();     // O(log n)
  }
}
int main(){
  vector<pair<int, int>> pos;
  pos.push_back(make_pair(3, 3));
  pos.push_back(make_pair(5, 1));
  pos.push_back(make_pair(-2, 4));

  int k = 2;
  nearByCar(pos, k);
  return 0;
}