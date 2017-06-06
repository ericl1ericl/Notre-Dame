#include <iostream>
using namespace std;

int main() {
  int i, j;
  int sum = 0;

  for (i = 1; i <= 3; i++) {
    for (j = 1; j <= 2; j++) {
      sum = sum + i*j;
    }
  }

  cout << "Sum is: " << sum << endl;

  return 0;
}

