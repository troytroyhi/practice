#include <iostream>
using namespace std;

class SoSimple
{
  private:
    int num;
  public:
    SoSimple(int n) : num(n)
    {
      cout<<"New Object: "<<this<<endl;
    }
    SoSimple(const SoSimple& copy) : num(copy.num)
    {
      cout<<"New Copy obj: "<<this<<endl;
    }
    ~SoSimple()
    {
      cout<<"Destroy obj: "<<this<<endl;
    }
};

SoSimple SimpleFuncObj(SoSimple ob)
{
  cout<<"Parm ADR: "<<&ob<<endl;
  return ob;
}

int main(void)
{
  SoSimple obj(7);
  SimpleFuncObj(obj);

  cout<<endl;
  SoSimple tempRef=SimpleFuncObj(obj);
  cout<<"Return Obj "<<&tempRef<<endl;
  return 0;
}

/*
[출력 결과]
New Object: 0x7fffffffdf1c    // 31행의 obj 생성
New Copy obj: 0x7fffffffdf20  // 32행의 함수호출로 인한 23행의 매개변수 ob의 생성
Parm ADR: 0x7fffffffdf20      // 25행의 실행을 통해서
New Copy obj: 0x7fffffffdf24  // 26행의 반환으로 인한 임시객체 생성
Destroy obj: 0x7fffffffdf24   // 매개변수 ob의 소멸
Destroy obj: 0x7fffffffdf20   // 26행의 반환으로 생성된 임시객체의 소멸

New Copy obj: 0x7fffffffdf24  // 35행의 함수호출로 인한 23행의 매개변수 ob의 생성
Parm ADR: 0x7fffffffdf24      // 25행의 실행을 통해서
New Copy obj: 0x7fffffffdf20  // 26행의 반환으로 인한 임시객체 생성
Destroy obj: 0x7fffffffdf24   // 매개변수 ob의 소멸
Return Obj 0x7fffffffdf20     // 36행의 실행결과 임시객체의 주소 값과 동일함에 주목!
Destroy obj: 0x7fffffffdf20   // tempRef가 참조하는 임시객체 소멸
Destroy obj: 0x7fffffffdf1c   // 31행의 obj 소멸
*/