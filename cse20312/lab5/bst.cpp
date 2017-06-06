// Eric Layne
// CSE 20312
// Lab5

#include <iostream>
using namespace std;

int leftsub(int[], int, int);
int rightsub(int[], int, int);

int main() {
   int length; // stores number of nodes in tree
   int treenum = 1;
   while(cin >> length) { // first number specifies length
      int numbers[length]; // initialize tree array
      int x;
      for (int i = 0; i < length; i++) { // read in the rest of values
         cin >> x;
         numbers[i] = x;
      }

      int left = leftsub(numbers, 0, length); // gets left subtree
      int right = rightsub(numbers, 0, length); // checks right subtree
   
      if (left == 1 || right == 1) { // if left/right subtree fails
         cout << "Tree " << treenum << " is not a BST" << endl;
      }
      else if (left == 0 && right == 0) { // if subtrees pass
         cout << "Tree " << treenum << " is a BST" << endl;
      }
      left = 0;
      right = 0;
      treenum++;
   }
}

// checks left subtree for validity
// uses array, the current node is x, and length
int leftsub(int numbers[], int x, int length) {
   int left, right;
   if (numbers[2*x+1] != -1 && numbers[2*x+1] <= numbers[x] && 2*x+1 <= length) { // if left subtree is good
      left = leftsub(numbers, 2*x+1, length); // check left tree
      right = rightsub(numbers, 2*x+1, length); // check right tree
      if (left == 1 || right == 1) {
         return 1;
      }
      else if (left == 0 && right == 0) {
         return 0;
      }
   }
   else if (numbers[2*x+1] != -1 && numbers[2*x+1] > numbers[x] && 2*x+1 <= length) { // if left subtree fails
      return 1;
   }
   else if (numbers[2*x+1] == -1 || 2*x+1 > length) { // if at bottom
      return 0;
   }
}

int rightsub(int numbers[], int x, int length) {
   int left, right;
   if (numbers[2*x+2] != -1 && numbers[2*x+2] > numbers[x] && 2*x+2 <= length) {
      right = rightsub(numbers, 2*x+2, length);
      left = leftsub(numbers, 2*x+2, length);
      if (left == 1 || right == 1) {
         return 1;
      }
      else if (left == 0 && right == 0) {
         return 0;
      }
   }
   else if (numbers[2*x+2] != -1 && numbers[2*x+2] <= numbers[x] && 2*x+2 <= length) {
      return 1;
   }
   else if (numbers[2*x+2] == -1 || 2*x+2 > length) {
      return 0;
   }
}
