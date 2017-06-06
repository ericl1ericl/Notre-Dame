// class interface for a Rectangle
class Rectangle
{
  public:
    Rectangle(); 
    Rectangle(float wd, float ln); 
    ~Rectangle();
    float getLength();
    float getWidth();
    void setLength(float ln); 
    void setWidth(float wd); 
    float perimeter(); 
    float area(); 
  private:
    float length;
    float width;
};

