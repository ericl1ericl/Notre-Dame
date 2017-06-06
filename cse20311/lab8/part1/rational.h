// Eric Layne
// CSE20311
// rational.h
class Rational {
  friend ostream& operator<< (ostream &, Rational &);
  friend istream& operator>> (istream &, Rational &);

  public:
    Rational();
    Rational(int, int);
    ~Rational();
    int getNumer();
    int getDenom();
    void setNumer(int);
    void setDenom(int);
    void setRational(int, int);
    void print();
    Rational operator+(Rational);
    Rational operator-(Rational);
    Rational operator*(Rational);
    Rational operator/(Rational);
  private:
    int numer;
    int denom;
};

