

// you can use a struct or a class

// forward declaration in c++
template<typename T> class LinkedList;

template<typename T>
class Node {

friend class LinkedList<T>;

public:
   Node (const T&);
   T getDate() const;

private:
   T data;
   Node <T> * next;
   Node <T> * prev;

};

template <typename T>
Node<T>::Node(const T &info):next(NULL) {
   data = info; //data.operator=(...)
}

template <typename T>
Node<T>::getData (void) {return data;}

// types linked lists

// "normal" linked list - next neighboar
// "doubly" linked list - before and after me
// "circular" linked list - doubly first prev == last; last next == first
