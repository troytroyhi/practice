#include <iostream>
#include <string>
using namespace std;

int main(void)
{
  string str1="I like ";
  string str2="string class";
  string str3=str1+str2;  // string 객체 간 덧셈연산이 가능함을 알 수 있다. 그리고 이는 operator + 연산자의 오버로딩으로 인해 가능하다.

  cout<<str1<<endl; // ~
  cout<<str2<<endl;
  cout<<str3<<endl; // ~. string 클래스가 << 연산자에 대해서도 오버로딩 되어있음을 확인할 수 있다.

  str1+=str2; // ~
  if(str1==str3)
    cout<<"동일 문자열!"<<endl;
  else 
    cout<<"동일하지 않은 문자열!"<<endl; // ~. 15행의 += 연산의 결과로 문자열 str1의 끝에 문자열 str2가 덧붙여졌음을 "동일 문자열!" 이라는 문자열의 출력을 통해서 알 수 있다.
  
  string str4;
  cout<<"문자열 입력: ";
  cin>>str4;  // string 클래스는 >> 연산자에 대해서도 오버로딩이 되어있다. 따라서 이러한 형태로 string 객체를 통해서 문자열을 입력 받는 것이 가능하다.
  cout<<"입력한 문자열: "<<str4<<endl;
  return 0;
}