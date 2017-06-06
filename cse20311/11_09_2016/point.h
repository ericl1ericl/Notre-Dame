class Point {
 friend ostream& operator<< (ostream &, Point &);
 friend istream& operator>> (istream &, Point &);
  public:
    Point();
    Point(double, double);
    ~Point();
    double getx();
    double gety();
    void setx(double);
    void sety(double);
    void setpoint(double, double);
    double radius();
    double angle();
    double distance(Point);
  private:
    double x;
    double y;
};

