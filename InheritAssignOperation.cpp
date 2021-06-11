#include <iostream>
using namespace std;

class First
{
  private:
    int num1, num2;
  public:
    First(int n1=0, int n2=0) : num1(n1), num2(n2)
    { }
    void ShowData() { cout<<num1<<", "<<num2<<endl; }

    First& operator=(const First& ref)  // 기초 클래스에는 멤버 대 멤버의 복사가 이뤄지도록 대입 연산자를 오버로딩 하였다.
    {
      cout<<"First& operator=()"<<endl;
      num1=ref.num1;
      num2=ref.num2;
      return *this;
    }
};

class Second : public First
{
  private:
    int num3, num4;
  public:
    Second(int n1, int n2, int n3, int n4)
      : First(n1, n2), num3(n3), num4(n4)
    { }
    void ShowData()
    {
      First::ShowData();
      cout<<num3<<", "<<num4<<endl;
    }

    /*
    Second& operator=(const Second& ref)  // 유도 클래스에도 멤버 대 멤버의 복사가 이뤄지도록 대입 연산자를 오버로딩 하였다.
    그러나 일단은 이 부분을 주석처리하고 실행해보고 결과를 통해서 디폹 대입 연산자의 특성을 발견해보자.
    {
      cout<<"Second& operator=()"<<endl;
      num3=ref.num3;
      num4=ref.num4;
      return *this;
    }
    */
};

int main(void)
{
  Second ssrc(111, 222, 333, 444);
  Second scpy(0, 0, 0, 0);
  scpy=ssrc;
  scpy.ShowData();
  return 0;
}