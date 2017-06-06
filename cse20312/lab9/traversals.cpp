// Eric Layne
// CSE20312
// Lab 9 Graph Traversals

#include <iostream>
#include <string>
#include <map>
#include <string>
#include <vector>
using namespace std;

struct path { // struct that holds data on each path
   char src;
   char dst;
};
path make_path(char&, char&); // make a new path

bool pathfinder(map<char, vector<char>>&, char&, char&, map<char, bool>&); // Depth first recursive search

int main() {
   int graph = 1; // keeps track of the graph
   int nedges;    // holds the number of edges
   int npaths;    // holds the number of paths to test
   char src;      // generic variable to hold a path/edge's source
   char dst;      // generic variable to hold a path/edge's destination

   // first input is the number of edges in the graph, so while loop runs as long as this input exists
   while (cin >> nedges) {
      if (graph != 1) { // formatting output
         cout << endl;
      }

      // serves as an adjacency list, maps a source char to a list of destination chars
      map <char, vector<char>> mapEdges;
      // a map that will keep track of wheteher or not a node is visited
      map <char, bool> visit;
      for (int i = 0; i < nedges; i++) {  // builds the adjacency list, visitation data
         cin >> src;                      // input the source node
         cin >> dst;                      // input the destination node
         mapEdges[src].push_back(dst);    // create the adjacency list mapping
         visit[src] = 0;                  // set the node to "not visited"
         visit[dst] = 0;                  // source and destination are 2 diff nodes, have to add both
      }

      cin >> npaths;          // input the number of paths to be tested
      vector<path> vecPaths;  // a vector to hold all the paths to be tested
      for (int i = 0; i < npaths; i++) {           // for all the paths to be tested...
         cin >> src;                               // ...take in its source...
         cin >> dst;                               // ...and destination...
         vecPaths.push_back(make_path(src, dst));  // ...and add both to the vector
      }

// VISUALIZATION TOOL: Print out an adjacency list
/*      for (auto k = mapEdges.begin(); k != mapEdges.end(); k++) {
         cout << k->first << " | ";
         for (auto v = k->second.begin(); v != k->second.end(); v++) {
            cout << " " << (*v); 
         }
         cout << endl;
      } */

      // because visitation map is passed by reference, need to create a second map to hold
      // the original "not visited" data for every node
      map<char, bool> visitOrig = visit;
      for (auto it = vecPaths.begin(); it != vecPaths.end(); it++) { // for every path to be tested
         visit = visitOrig; // default the visitation map to all zero ("not visited")
         if (pathfinder(mapEdges, (*it).src, (*it).dst, visit)) { // checks to see if a path exists in map
            cout << "In Graph " << graph << " there is a path from ";
            cout << (*it).src << " to " << (*it).dst << endl;
         }
         else {
            cout << "In Graph " << graph << " there is no path from ";
            cout << (*it).src << " to " << (*it).dst << endl;
         }
      }
      graph++; // move on to the next graph
   }
   
}

// a call to this function creates a path struct
path make_path(char& src, char& dst) {
   path x;
   x.src = src; // source
   x.dst = dst; // destination
   return x; // return the path struct
}

// recursive depth first search
bool pathfinder(map<char, vector<char>>& mapEdges, char& src, char& dst, map<char, bool>& visit) {
   visit[src] = 1;               // mark the current source as visited
   auto k = mapEdges.find(src);  // check to see if the current source is in the graph
   if (k != mapEdges.end()) {    // if the current source is in the graph...
      for (auto v = k->second.begin(); v != k->second.end(); v++) { // ...iterate through its destinations
         if ((*v) == dst) {   // if the destination matches the desired destination...
            return 1;         // ...return true
         }
         else { // if the destination does not match the desired destination...
            // ...move deeper into graph
            // note that the next node must not have been visited already, otherwise risk getting
            // caught in a cyclic graph
            if (visit[(*v)] == 0 && pathfinder(mapEdges, (*v), dst, visit)) {
               return 1;
            }
         }
      }
   }
   return 0;
}

/* vim: set sts=3 sw=3 ts=6 expandtab ft=c: */
