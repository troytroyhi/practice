#include <iostream>
using namespace std;

class SoSimple
{
  private:
    int num1;
    int num2;

  public:
    SoSimple(int n1, int n2)
      : num1(n1), num2(n2)
    {
        // empty
    }
    SoSimple(SoSimple &copy) // SoSimple(const SoSimple &copy) -> 멤버 대 멤버의 복사에 사용되는 원본을 변경시키는 것은 복사의 개념을 무너뜨리는 행위가 되니(실수로 발생함), 키워드 const를 삽입해서 막는 것이 좋다.
      : num1(copy.num1), num2(copy.num2)
    {
      cout<<"Called SoSimple(SoSimple &copy)"<<endl;
    }
    void ShowSimpleData()
    {
      cout<<num1<<endl;
      cout<<num2<<endl;
    }
};

int main(void)
{
  SoSimple sim1(15, 30);
  cout<<"생성 및 초기화 직전"<<endl;
  SoSimple sim2=sim1; // SoSimple sim2(sim1); 으로 변환!
  cout<<"생성 및 초기화 직후"<<endl;
  sim2.ShowSimpleData();
  return 0;
}