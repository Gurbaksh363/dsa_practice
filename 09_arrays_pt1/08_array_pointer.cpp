#include <iostream>
using namespace std;

int main(){
  int x = 10;
  int* ptr = &x;

  int y = 25;
  ptr = &y; // ptr can store any address of same type

  

  int arr[10];
  // arr = &10;  // ARRAY POINTER IS CONSTANT POINTER;
  return 0;
}