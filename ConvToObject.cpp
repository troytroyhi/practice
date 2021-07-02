#include <iostream>
using namespace std;

class Number
{
  private:
    int num;
  public:
    Number(int n=0) : num(n)
    {
      cout<<"Number(int n=0)"<<endl;
    }
    Number& operator=(const Number& ref)  // 굳이 대입 연산자를 오버로딩 할 필요가 없는 상황이지만, 대입 연산자의
    // 호출을 확인하기 위해서 오버로딩 하였다. 문자열을 출력하는 것 말고는 디폴트 대입 연산자와 차이가 없다.
    {
      cout<<"operator=()"<<endl;
      num=ref.num;
      return *this;
    }
    void ShowNumber() { cout<<num<<endl; }
};

int main(void)
{
  Number num;
  num=30; // 서로 다른 두 자료형의 피연산자를 대상으로 대입연산을 진행하고 있다. 출력되는 문자열을 보면 이 연산이 어떻게 진행되는지 알 수 있을 것이다.
  num.ShowNumber();
  return 0;
}