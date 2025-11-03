// Question 5: For a positive N, WAP that prints the first N Fibonacci numbers.
// (Assume N >= 2)
// Fibonacci series : 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 ....
// This is a series where each number is a sum of previous 2 numbers in the series.
// Eg:
// 1 = 0 + 1,
// 2 = 1 + 1,
// 3 = 1 + 2,
// 5 = 2 + 3,
// 8 = 3 +5 & so on.

#include <iostream>
using namespace std;

int main()
{
  int num;
  cout << "Enter the num (num>=2)\n";
  cin >> num;

  int curr = 0, prev = 1, sec_prev = 0;
  cout << sec_prev << " " << prev << " ";

  for (int i = 1; i <= num; i++)
  {
    curr = prev + sec_prev;
    cout << curr << " ";
    sec_prev = prev;
    prev = curr;
  }
  return 0;
}