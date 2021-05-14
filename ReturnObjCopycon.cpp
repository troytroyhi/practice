#include <iostream>
using namespace std;

class SoSimple
{
  private:
    int num;
  public:
    SoSimple(int n) : num(n)
    { }
    SoSimple(const SoSimple& copy) : num(copy.num)
    {
      cout<<"Called SoSimple(const SoSimple& copy)"<<endl;
    }
    SoSimple& AddNum(int n) // 이 예제의 이해를 위해서는 참조형을 반환하는 AddNum 함수를 잘 이해해야 한다.
    {
      num += n;
      return *this; // 이 문장을 실행하는 객체 자신을 반환하고 있다. 그런데 반환형이 참조형이니, 참조값이 반환된다.
    }
    void ShowData()
    {
      cout<<"num: "<<num<<endl;
    }
};

SoSimple SimpleFuncObj(SoSimple ob) // 매개변수 선언을 보면, 인자의 전달과정에서 복사 생성자가 호출됨을 알 수 있다.
{
  cout<<"return 이전"<<endl;
  return ob; // ob 객체를 반환하고 있다. 그런데 반환형이 참조형이 아니다.(참조형 *) 따라서 ob 객체의 복사본이 만들어지면서 반환이 진행된다.
}

int main(void)
{
  SoSimple obj(7);
  SimpleFuncObj(obj).AddNum(30).ShowData(); // SimpleFuncObj 함수가 반환한 객체를 대상으로 AddNum 함수를 호출하고,
  // 이어서 AddNum 함수가 반환하는 참조 값을 대상으로 ShowData 함수를 호출하고 있다.
  obj.ShowData(); // 35행의 출력결과와 비교하기 위해서, 34행에서 생성한 객체를 대상으로 ShowData 함수를 호출하고 있다.
  return 0;
}