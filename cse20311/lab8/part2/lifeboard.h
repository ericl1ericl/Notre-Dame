// Eric Layne
// CSE20311
// lifeboard.h

class Lifeboard {
   public:
      Lifeboard();
      ~Lifeboard();
      void display();
      int remC(int, int);
      int addC(int, int);
      int isState(int, int);
   private:
      char board[42][42];      
};
