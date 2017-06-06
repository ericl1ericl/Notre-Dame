// Eric Layne
// CSE 20312
// Lab5

#include <iostream>
using namespace std;

int leftsub(int[], int, int);
int rightsub(int[], int, int);

int main() {
   int length;
//   int extend = 0;
//   cin >> length;
   while(cin >> length) {
//   if (length%2 == 0) {
//      length = length + 1;
//      extend = 1;
//   }
   int numbers[length];
   int x;
//   int i = 0;
//   while (cin >> x) {
//      numbers[i] = x;
//      i++;
//   }
//   if (extend == 1) {
//      numbers[length-1] = -1;
//      length = length - 1;
//   }

//   if (extend == 1) {
//      for (int i = 0; i < length - 1; i++) {
//         cin >> x;
//         numbers[i] = x;
//      }
//      numbers[length-1] = -1;
//      length = length - 1;
//   }
//   else if (extend == 0) {
      for (int i = 0; i < length; i++) {
         cin >> x;
         numbers[i] = x;
//         cout << x << ' ';
      }
 //  }
//   cout << endl;

   int left = leftsub(numbers, 0, length);
   int right = rightsub(numbers, 0, length);
   
   if (left == 1 || right == 1) {
      cout << "Tree is not a BST" << endl;
   }
   else if (left == 0 && right == 0) {
      cout << "Tree is a BST" << endl;
   }
   left = 0;
   right = 0;
   }

}

int leftsub(int numbers[], int x, int length) {
   if (numbers[2*x+1] != -1 && numbers[2*x+1] <= numbers[x] && 2*x+1 <= length) {
      leftsub(numbers, 2*x+1, length);
      rightsub(numbers, 2*x+1, length);
      return 0;
   }
   else if (numbers[2*x+1] != -1 && numbers[2*x+1] > numbers[x] && 2*x+1 <= length) {
      return 1;
   }
   else if (numbers[2*x+1] == -1 || 2*x+1 > length) {
      return 0;
   }
}

int rightsub(int numbers[], int x, int length) {
   if (numbers[2*x+2] != -1 && numbers[2*x+2] > numbers[x] && 2*x+2 <= length) {
      rightsub(numbers, 2*x+2, length);
      leftsub(numbers, 2*x+2, length);
      return 0;
   }
   else if (numbers[2*x+2] != -1 && numbers[2*x+2] <= numbers[x] && 2*x+2 <= length) {
      return 1;
   }
   else if (numbers[2*x+2] == -1 || 2*x+2 > length) {
      return 0;
   }
}
