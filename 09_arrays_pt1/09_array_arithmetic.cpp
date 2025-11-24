#include <iostream>
using namespace std;

int main(){
  // 1. Inc or dec of Pointers
  int x = 12;
  int* ptr = &x;

  cout<<ptr<<endl; // ...196c + int(4Bytes) = 6c, 6d, 6e, 6f = 4Bytes skip
  ptr++;
  cout<<ptr<<endl;        // ...1970

  ptr--;
  cout<<ptr<<endl; // ...196c


  // 2. Addition and Subtraction of Constants
  // ptr + 3 or ptr - 3
  cout<< ptr + 3<<endl; // 3 * int(4Bytes) = 12Bytes skip  ..1977


  // 3. Comparison
  int arr[10];
  int* ptr2 = arr;
  cout<<(arr== ptr2)<<endl;
  cout<<(&arr[4]> &arr[3])<<endl; //yes
  return 0;
}