#include<iostream>
using namespace std;

void display_array(int[], int);
void change_array(int[], int);

int main () {
   int arr[] = {1, 2, 5, 6, 8, 9, 11};
   int size = sizeof(arr)/sizeof(int);

   cout << "Before: ";
   display_array(arr, size);
   change_array(arr, size); // increment each value by 2
   cout << "After: ";
   display_array(arr, size);

   return 0;
}

void change_array(int a[], int size) {
   for (int i = 0; i < size; i++) {
      a[i] += 2;
   }
}

void display_array(int a[], int size) {
   for (int i = 0; i < size; i++) {
      cout << a[i] << " ";
   }
   cout << endl;
}
