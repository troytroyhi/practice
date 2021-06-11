#include <iostream>
#include <cstring>
using namespace std;

class Person  // Chapter 05의 예제 ShallowCpoyError.cpp의 Person 클래스를 그대로 사용하였다.
{
  private:
  char * name;
  int age;
  public:
  Person(char * myname, int myage)
  {
    int len=strlen(myname)+1;
    name=new char[len];
    strcpy(name, myname);
    age=myage;
  }
  void ShowPersonInfo() const
  {
    cout<<"이름: "<<name<<endl;
    cout<<"나이: "<<age<<endl;
  }
  ~Person()
  {
    delete []name;
    cout<<"called destructor!"<<endl;
  }
};

int main(void)
{
  Person man1("Lee dong woo", 29);
  Person man2("Yoon ji yul", 22);
  man2 = man1;  // 대입 연산자가 호출된다. 그런데 Person 클래스에는 대입 연산자가 정의되어 있지 않으니, 디폴트 대입 연산자가 호출된다.
  man1.ShowPersonInfo();
  man2.ShowPersonInfo();
  return 0;
}