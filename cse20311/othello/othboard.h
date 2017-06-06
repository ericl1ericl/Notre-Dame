// Eric Layne
// CSE20311
// lifeboard.h

class Othboard {
   public:
      Othboard();
      ~Othboard();
      void display();
      int addC(int, int);
      int changeC(int, int);
      int isState(int, int);
   private:
      char board[42][42];      
};
