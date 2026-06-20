#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

// without set and using nested loop O(n*n)
void printItenary(unordered_map<string,string>& tickets){  // O(n)
  // 1. finding start: from (✅), to (❎)
  unordered_set<string> to;
  for(pair<string,string> ticket: tickets){ // <from, to> // O(n)
    to.insert(ticket.second);
  }
  string start = "";
  for(pair<string, string> ticket: tickets){  // O(n)
    if(!to.count(ticket.first)){    // checking if to exists for each from
      start = ticket.first;
    }
  }

  // printing itenary
  cout<<start<<" -> ";        // O(n)
  while(tickets.count(start)) {
    cout<<tickets[start]<<" -> ";
    start = tickets[start];
  }
  cout<<"Destination";
}
int main(){
  unordered_map<string, string> tickets;
  tickets["Chennai"] = "Bengaluru";
  tickets["Mumbai"] = "Delhi";
  tickets["Goa"] = "Chennai";
  tickets["Delhi"] = "Goa";
  printItenary(tickets);
  return 0;
}