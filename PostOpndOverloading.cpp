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
    Point operator++()  // 전위증가
    {
      xpos+=1;
      ypos+=1;
      return *this;
    }
    const Point operator++(int) // 후위증가, ++를 후위증가의 형태로 연산자 오버로딩하고 있다.
    {
      const Point retobj(xpos, ypos); // const Point retobj(*this);, 값의 증가에 앞서 반환에 사용할 복사본을 만들어 놓고 있다.
      xpos+=1; // 그리고 이 복사본은 값이 변경되면 안되기 때문에 const로 선언하였다.
      ypos+=1; // 또한 주석에서 보이듯이, 23행의 문장은 복사 생성자를 호출하는 형태로도 구현이 가능하다.
      return retobj; // 멤버의 값이 증가하기 이전에 만들어둔 복사본을 반환하고 있다. 이것이 후위증가의 효과를 내는 방법이다.
    }
    friend Point& operator--(Point &ref);
    friend const Point operator--(Point &ref, int);
};

Point& operator--(Point &ref) // 전위감소
{
  ref.xpos-=1;
  ref.ypos-=1;
  return ref;
}

const Point operator--(Point &ref, int) // 후위감소, --를 후위감소의 형태로 연산자를 오버로딩 하되, 전역함수의 형태로 오버로딩 하는 방법을 보이고 있다.
{ // 이 경우에도 멤버함수의 경우와 마찬가지로, 매개변수의 선언에 int를 추가함으로써 후위감소임을 명시하게 된다.
  const Point retobj(ref);  // const 객체라 한다.
  ref.xpos-=1;
  ref.ypos-=1;
  return retobj;
}

int main(void)
{
  Point pos(3,5);
  Point cpy;
  cpy=pos--;
  cpy.ShowPosition();
  pos.ShowPosition();

  cpy=pos++;
  cpy.ShowPosition();
  pos.ShowPosition();
  return 0;
  
}