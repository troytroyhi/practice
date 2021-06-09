#include <iostream>
using namespace std;

class Point
{
  private:
    int xpos, ypos;
  public:
    Point(int x=0, int y=0) : xpos(x), ypos(y)
    { }
    void ShowPosition() const
    {
      cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
    }
    Point& operator++() // ++ 연산자가 멤버함수의 형태로 오버로딩 되었다.
    {
      xpos+=1;
      ypos+=1;
      return *this;
    }
    friend Point& operator--(Point &ref); // 24행에 정의된 전역함수에 대해 friend 선언을 하고 있다.
};

Point& operator--(Point &ref) // -- 연산자가 전역함수의 형태로 오버로딩 되었다.
{
  ref.xpos-=1;
  ref.ypos-=1;
  return ref;
}

int main(void)
{
  Point pos(1, 2);
  ++pos;  // ++ 연산자는 멤버함수의 형태로 오버로딩 되었으므로, 이 문장은 pos.operator++(); 으로 해석된다.
  pos.ShowPosition();
  --pos;  // -- 연산자는 전역함수의 형태로 오버로딩 되었으므로, 이 문장은 operator--(pos); 으로 해석된다.
  pos.ShowPosition();

  ++(++pos); 
  pos.ShowPosition();
  --(--pos);
  pos.ShowPosition();
  return 0;
}