#include <iostream>
#include <iomanip>
#include <math.h>
#include <bitset>
#include <string>
using namespace std;

int main() {
	int array[] = {3, 12, 0, 44, 6, 9, 128, 256, 255};
	int array_size = sizeof(array)/sizeof(int);
	for(int i = 0; i < array_size; i++) {
		cout << array[i] << ": ";
		string binary = bitset<32>(array[i]).to_string();
		binary.erase(0, min(binary.find_first_not_of('0'), binary.size()-1));
		cout << binary << endl;
		cout << " length: " << binary.size() << endl;
	}
	return 0;	
}
