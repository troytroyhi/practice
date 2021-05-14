#include <iostream>
using namespace std;

class SoSimple
{
  private:
    int num;
  public:
    SoSimple(int n) : num(n)
    { }
    SoSimple(const SoSimple& copy) : num(copy.num) // 복사 생성자의 호출시기를 알기 위해서 복사 생성자를 별도로 정의하였다.
    { // 디폴트 복사 생성자와의 유일한 차이점은 13행의 문자열 출력에 있다.
      cout<<"Called SoSimple(const SoSimple& copy)"<<endl;
    }
    void ShowData()
    {
      cout<<"num: "<<num<<endl;
    }
};

void SimpleFuncObj(SoSimple ob)
{
  ob.ShowData();
}

int main(void)
{
  SoSimple obj(7);
  cout<<"함수호출 전"<<endl;
  SimpleFuncObj(obj); // 함수 SimpleFuncObj를 호출하면서 객체 obj를 인자로 전달하고 있다.
  // 따라서 21행에 선언된 매개변수 ob의 복사 생성자가 호출되면서, 인자로 obj가 전달된다.
  cout<<"함수호출 후"<<endl;
  return 0;
}