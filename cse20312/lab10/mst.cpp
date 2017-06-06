// Eric Layne
// CSE20312
// Lab 10 Minimum Spanning Tree

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct path {
   char src; // source node
   char dst; // destination node
   int wt; // path weight
};
path make_path(char, char, int);

char num2char(int); // converts int to corresponding char
void prim(map <char, vector<path>>); // implements Prim's algorithm
bool edgeSort(path, path); // sorts paths based on weight 

int main() {
   int nvertices = 0; // holds the number of nodes
   int gNum = 1; // current graph being tested
   while (cin >> nvertices) {
      if (gNum != 1) {
         cout << endl;
      }
      map <char, vector<path>> graph; // adjacency list
      int dst[nvertices][nvertices]; // adjacency matrix
      // converts adjacency matrix into adjacency list
      for (int i = 0; i < nvertices; i++) {
         for (int j = 0; j < nvertices; j++) {
            cin >> dst[i][j];
            if (dst[i][j] != -1) { // if path exists, add to graph
               graph[num2char(i)].push_back(make_path(num2char(i), num2char(j), dst[i][j]));
            }
         }
      }

// Graph visualization tool
/*      for (auto it = graph.begin(); it != graph.end(); it++) {
         cout << it->first << " | ";
         for (auto v = it->second.begin(); v != it->second.end(); v++) {
            cout << "(" << (*v).src << "," << (*v).dst << "," << (*v).wt << ") ";
         }
         cout << endl;
      } */

      prim(graph);
      gNum++;
   } 
}

path make_path(char src, char dst, int wt) {
   path x;
   x.src = src;
   x.dst = dst;
   x.wt = wt;
   return x;
}

char num2char(int x) {
   char c = 'A' + x;
   return c;
}

void prim(map<char, vector<path>> graph) {
   vector<path> frontier;
   map <char, path> marked;
   frontier.push_back(make_path('A', 'A', -1)); // manually insert starting node
   while(!frontier.empty()) {
      sort(frontier.begin(), frontier.end(), edgeSort); // sort based on path weight with edgeSort
      path v = frontier.back(); // get path to be added to marked
      frontier.pop_back(); // remove marked path from frontier

      if (marked.find(v.dst) != marked.end()) { // do nothing if path exists
      }
      else { // if path needs to be added to marked
         marked[v.dst] = v; // for the destination, add the path used to get there
         // update frontier
         for (auto it = graph[v.dst].begin(); it != graph[v.dst].end(); it++) {
            frontier.push_back(make_path(v.dst, (*it).dst, (*it).wt));
         }
      }
   }
   // find the total weight
   int sum = 0;
   for (auto it = marked.begin(); it != marked.end(); it++) {
      if ((it->second).wt != -1) { // excludes path from A to A
         sum = sum + (it->second).wt;
      }
   }
   cout << sum << endl;
   // display paths in lexicographical order
   string set; // string to hold source/destination pair
   vector<string> vSet; // vector of string sets
   for (auto it = marked.begin(); it != marked.end(); it++) {
      // store source/destination pairs based on alphabetical order
      if ((it->second).src < (it->second).dst) {
         set = (it->second).src;
         set = set + (it->second).dst;
      }
      else {
         set = (it->second).dst;
         set = set + (it->second).src;
      }
      vSet.push_back(set); // add string set to vector
   }
   sort(vSet.begin(), vSet.end()); // sort vector alphabetically
   // for every set besides the first (exludes A to A)
   for (auto it = vSet.begin()+1; it != vSet.end(); it++) {
      cout << (*it) << endl;
   }
   
}

// sorts paths from largest to smallest
bool edgeSort(path i, path j) {
   return (i.wt > j.wt);
}

/* vim: set sts=3 sw=3 ts=6 expandtab ft=c: */
