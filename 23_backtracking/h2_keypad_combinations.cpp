// Question 2:
// Keypad Combinations
// Given a string containing digits from 2-9 inclusive, print all possible letter combinations that
// the number could represent. You can print the answer in any order.
// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1
// does not map to any letters.
// Sample Input 1 : digits = "23"
// Sample Output 1 : "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"
// Sample Input 2 : digits = "2"
// Sample Output 2 : "a", "b", "c"
// Sample Input 3: digits = ""
// Sample Output 3: ""

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void letterCombinations(string digits, vector<string>& letters, int i, string ans){
  if (ans.length()== digits.length()){
    cout<<ans<<" ";
    return;
  }
  string currLetters = letters[(digits[i]-'0')];
  for(int j= 0; j<currLetters.length(); j++){
    ans += currLetters[j];
    letterCombinations(digits, letters, i+1, ans);
    ans.pop_back();
  }
}
int main(){
  vector<string> letters = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
  string digits = "23";
  if (digits.length() == 0) {
    cout << "";
  }else{
    letterCombinations(digits, letters, 0, "");
  }  
  return 0;
}