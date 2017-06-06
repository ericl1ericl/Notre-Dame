// Eric Layne
// CSE20311
// state.h interface

#include <string>
using namespace std;

class State {
   public:
      State();
      State(string, string, string, int, int, int);
      ~State();
      void setAbbr(string);
      void setName(string);
      void setCap(string);
      void setPop(int);
      void setYear(int);
      void setReps(int);
      string getAbbr();
      string getName();
      string getCap();
      int getPop();
      int getYear();
      int getReps();
   private:
      string abbr;
      string name;
      string cap;
      int pop;
      int year;
      int reps;
};
