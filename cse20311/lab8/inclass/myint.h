// myint.h
class MyInt {
  public:
    MyInt();
    MyInt(int);
    ~MyInt();
    int getValue();
    void setValue(int);
    void display();
    MyInt operator+(MyInt);
    
  private:
    int value;
};

