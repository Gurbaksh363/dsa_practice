#include <iostream>
#include <queue>
using namespace std;

class Student{
  public:
  string name;
  int marks;
  Student(string name, int marks){
    this->name = name;
    this->marks = marks;
  }
  bool operator < (const Student& obj)const{
    return this->marks < obj.marks;            // > ===> min heap
  }
};
int main(){
  priority_queue<Student> pq;
  pq.push(Student("raman", 55));
  pq.push(Student("gurbaksh", 75));
  pq.push(Student("alia", 35));

  while(!pq.empty()){
    cout<<"Top: "<<pq.top().name<<", "<< pq.top().marks<<endl;
    pq.pop();
  }
  return 0;
}