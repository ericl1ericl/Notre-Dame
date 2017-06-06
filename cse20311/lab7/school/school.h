// interface for a School class

#include <string>
using namespace std;

class School {
  public:
   School();
   School(string, string, int);
   ~School();
   void setSchoolname(string);
   void setNickname(string);
   void setYear(int);
   string getSchoolname();
   string getNickname();
   int getYear();
  private:
   string schoolname;
   string nickname;
   int year;
};

