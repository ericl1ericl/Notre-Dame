
class Student {
   public:
      Student(); // constructor

      ~Student(); // destructor

      // access methods
      int getage();
      double getgpa();
      ...
      void setage(int);
      void setgpa(double);

      // utility methods
      void go_crazy_on_weekends();

   private:
      string last;
      string first;
      int age;
      double gpa;
};
