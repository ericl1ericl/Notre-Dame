// Eric Layne
// CSE20312
// LinkedList.cpp

#include <iostream>
#include <string>

using namespace std;

template <typename T> struct Node {
	T value;
	Node<T>* next;
};

template <typename T> class List {
	public:
		List();
		~List();
		bool empty();
		void print();
		void pushFront(T &);
		Node<T>* head;
};

template <typename T>
List<T>::List() { // constructor
	head = NULL;	
}

template <typename T>
List<T>::~List() { // destructor
	if (!empty()) {
		Node<T> *p = head;
		while (p != NULL) {
			Node<T> *next = p->next;
			delete p;
			p = next;
		}
	}
}

template <typename T>
bool List<T>::empty() { // checks if list is empty
	return (head==NULL);
}

template <typename T>
void List<T>::print() { // prints list values
	Node<T> *p = head;
	for (; p != NULL; p = p->next) {
		cout << p->value;
	}
}

template <typename T>
void List<T>::pushFront(T &value) { // add node to front of list
	Node<T> *x = new Node<T>;
	x->value = value;
	x->next = head;
	head = x;
}

// add up two linked lists representing numbers
template <typename T>
List<T> addNumberLists(List<T> &L1, List<T> &L2) {
	List<T> sum;
	T place1;
	T place2;
	T addplace;
	T finalplace;
	T carry = 0;
	// add up the same places while values are same length
	while (L1.head != NULL && L2.head != NULL) {
		place1 = L1.head->value; // digit to add
		place2 = L2.head->value; // digit to add
		addplace = place1 + place2 + carry; // add up relevant data
		if (addplace >= 10) { // if a carry is needed
			finalplace = addplace % 10; // remainder
			carry = (addplace - finalplace)/10; // carryover
		}
		else { // if carry not needed
			finalplace = addplace; // remainder
			carry = 0; // reset carry variable
		}
		sum.pushFront(finalplace); // add remainder to end of value
		L1.head = L1.head->next; // advance to next digit
		L2.head = L2.head->next;
	}
	// if one value is longer / still exists
	while (L1.head != NULL || L2.head != NULL) {
		T place; // hold digit
		if (L1.head != NULL) { // if L1 is remaining value
			place = L1.head->value; // digit to add
			addplace = place + carry; // add relevant data
			finalplace = addplace % 10; // remainder
		}
		else if (L2.head != NULL) { // if L2 is remaining value
			place = L2.head->value;
			addplace = place + carry;
			finalplace = addplace % 10;
		}
		sum.pushFront(finalplace); // add remainder to end of value
		// if one value still exists
		if (L1.head != NULL || L2.head != NULL) {
			carry = addplace / 10; // carryover
		}
		else {
			carry = 0; // reset carry value
		}
		if (L1.head != NULL) { // if L1 exists, advance it
			L1.head = L1.head->next;
		}
		else if (L2.head != NULL) { // if L2 exists, advance it
			L2.head = L2.head->next;
		} 
	}
	if (carry != 0) { // add last carry to end of value
		sum.pushFront(carry);
	}
	return sum;
}

int main(int argc, char *argv[]) {
	string numString1, numString2 = "";
	while (cin >> numString1 >> numString2) {
		List<int> num1; // first number
		List<int> num2; // second number
		for (unsigned int i = 0; i < numString1.size(); i++) {
			int z = numString1[i] - '0';
			num1.pushFront(z); // create number
		}
		for (unsigned int i = 0; i < numString2.size(); i++) {
			int z = numString2[i] - '0';
			num2.pushFront(z);
		}
		List<int> sum = addNumberLists(num1, num2); // add numbers
		sum.print(); // print sum
		cout << endl;
	}
	return 0;
}
