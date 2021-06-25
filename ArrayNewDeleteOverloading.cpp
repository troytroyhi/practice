#include <iostream>
using namespace std;

class Point
{
  private:
    int xpos, ypos;
  public:
    Point(int x=0, int y=0) : xpos(x), ypos(y) { }
    friend ostream& operator<<(ostream& os, const Point& pos);

    void * operator new (size_t size)
    {
      cout<<"operator new : "<<size<<endl;
      void * adr = new char[size];
      return adr;
    }
    void * operator new[] (size_t size)
    {
      cout<<"operator new [] : "<<size<<endl;
      void * adr = new char[size];
      return adr;
    }

    void operator delete (void * adr)
    {
      cout<<"operator delete ()"<<endl;
      delete []adr;
    }
    void operator delete[] (void * adr)
    {
      cout<<"operator delete[] ()"<<endl;
      delete []adr;
    }
};

ostream& operator<<(ostream& os, const Point& pos)
{
  os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
  return os;
}

int main(void)
{
  Point * ptr = new Point(3, 4);
  Point * arr = new Point[3]; // 배열의 생성과정에서 총 세 개의 Point 객체가 생성된다.
  // 이 세 Point 객체의 할당에 필요한 메모리 공간은 18행에 정의된 멤버함수(사실은 static 함수)의 호출에 의해서 완성된다.
  delete ptr;
  delete []arr; // 46행에서 할당한 배열의 소멸을 명령하고 있다. 객체로 구성된 배열이기 때문에 모든 객체의 소멸자가 호출된 다음에
  // 30행에 정의된 멤버함수(static 함수)가 호출된다.
  return 0;
}