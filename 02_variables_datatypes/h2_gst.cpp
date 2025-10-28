// Question 2: Enter cost of 3 items from the user (using float data type) - a pencil, a
// pen and an eraser. You have to output the total cost of the items back to the user as
// their bill.
// (Add on: You can also try adding 18% GST tax to the items in the bill as an advanced
// problem)
#include <iostream>
using namespace std;

int main(){
  float pencilCost, penCost, eraserCost;
  cout<<"Enter the cost of pencil, eraser and pen: ";

  cin>> pencilCost>>penCost>>eraserCost;

  float totalCost = pencilCost+penCost+pencilCost;
  cout<<"Total cost is: "<< totalCost;
  float totalCostWithGST = (18/100)*totalCost + totalCost;
  cout<<"Total cost with 18% GST is: "<< totalCostWithGST;
  return 0;
}