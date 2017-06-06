// Eric Layne
// CSE20312
// cards.cpp

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct player { // holds data relevant to each player
   string name;
   int rank;
   int suit;
};

bool Greater(const player&, const player&); // function to sort players
player make_player(string&, int&, int&); // function to create player struct

int main() {
   int numplayers; // holds number of players
   // exit loop if input is -1
   while (cin >> numplayers && numplayers != -1) {
      vector<player> vecP; // vector of players
      for (int i = 0; i < numplayers; i++) { // create player structs
         string name; // input name
         string sRank; // input rank
         int rank; // holds final rank value
         char cSuit; // input suit
         int suit; // holds final suit value
         cin >> name;
         cin >> sRank;
         cin >> cSuit;
         if (sRank == "J") { // use of if/else if due to string
            rank = 11;
         }
         else if (sRank == "Q") {
            rank = 12;
         }
         else if (sRank == "K") {
            rank = 13;
         }
         else if (sRank == "A") {
            rank = 14;
         }
         else {
            rank = stoi(sRank); // convert number string to int
         }
         switch(cSuit) {
            case 'S': suit = 4; break;
            case 'H': suit = 3; break;
            case 'D': suit = 2; break;
            case 'C': suit = 1; break;
         } 
         // add struct to vector
         vecP.push_back(make_player(name, rank, suit));
      }
      sort(vecP.begin(), vecP.end(), Greater); // sorts according to Greater
      auto it = vecP.begin(); // iterator for the vector
      for(; it != vecP.end() - 1; it++) { // goes through whole vector
         cout << (*it).name << ", ";
      }
      cout << (*it).name << endl;
   }
}

// make player struct
player make_player(string& name, int& rank, int& suit) {
   player x;
   x.name = name;
   x.rank = rank;
   x.suit = suit;
   return x;
}

// function to sort vector
bool Greater(const player& a, const player& b) {
   if(a.rank == b.rank) { // if rank is the same...
      return a.suit > b.suit; // ...sort by suit
   }
   return a.rank > b.rank; // otherwise sort by rank
}

/* vim: set sts=3 sw=3 ts=6 expandtab ft=c: */ 
