#include <iostream>
#include <cstring>
using namespace std;

class Employee // 고용인을 의미하는 Employee 클래스가 추가되었다. 모든 고용인은 이름이 있으므로, 이와 관련된 멤버들을 기반으로 정의하였다.
{
  private:
    char name[100];
  public:
    Employee(char * name)
    {
      strcpy(this->name, name);
    }
    void ShowYourName() const
    {
      cout<<"name: "<<name<<endl;
    }
    virtual int GetPay() const
    {
      return 0;
    }
    virtual void ShowSalaryInfo() const
    { }
};

class PermanentWorker : public Employee // 이전의 PermanentWorker 클래스와의 차이점은 Employee 클래스를 상속한다는 점이다. 때문에 이름과 관련된 멤버는 모두 제거하였다.
{
  private:
    int salary; //월 급여
  public:
    PermanentWorker(char* name, int money)
      : Employee(name), salary(money)
      { }
    int GetPay() const
    {
      return salary;
    }
    void ShowSalaryInfo() const
    {
      ShowYourName();
      cout<<"salary: "<<GetPay()<<endl<<endl;
    }
};

class TemporaryWorker : public Employee
{
  private:
    int workTime; // 이 달에 일한 시간의 합계
    int payPerHour; // 시간당 급여
  public:
    TemporaryWorker(char * name, int pay)
      : Employee(name), workTime(0), payPerHour(pay)
    { }
    void AddWorkTime(int time)  // 일한 시간의 추가
    {
      workTime+=time;
    }
    int GetPay() const  // 이 달의 급여
    {
      return workTime * payPerHour;
    }
    void ShowSalaryInfo() const
    {
      ShowYourName();
      cout<<"salary: "<<GetPay()<<endl<<endl;
    }
};

class SalesWorker : public PermanentWorker
{
  private:
    int salesResult;  // 월 판매실적
    double bonusRatio;  // 상여금 비율
  public:
    SalesWorker(char * name, int money, double ratio)
      : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
    { }
    void AddSalesResult(int value)
    {
      salesResult+=value;
    }
    int GetPay() const
    {
      return PermanentWorker::GetPay()  // PermanentWorker의 GetPay 함수 호출
        + (int)(salesResult*bonusRatio);
    }
    void ShowSalaryInfo() const
    {
      ShowYourName();
      cout<<"salary: "<<GetPay()<<endl<<endl; // SalesWorker의 GetPay 함수가 호출됨
    }
};

class EmployeeHandler // 이전의 EmployeeHandler 클래스와 비교해볼 필요가 있다. 저장의 대상이 PermanentWorker 객체에서 Employee 객체로 변경되었다.
// 그러나 PermanentWorker 객체 역시 Employee 객체의 일종이므로 저장이 가능하다.
{
  private:
    Employee* empList[50]; // Employee 객체의 주소 값을 저장하는 방식으로 객체를 저장한다. 따라서 Employee 클래스를 상속하는 클래스의 객체도 이 배열에 함께 저장이 가능하다.
    int empNum;
  public:
    EmployeeHandler() : empNum(0)
    { }
    void AddEmployee(Employee* emp) // AddEmployee 함수의 인자로 Employee 객체의 주소 값을 전달해야 한다. 따라서 Employee 클래스를 상속하는 PermanentWorker 객체의 주소 값도 전달이 가능하다.
    {
      empList[empNum++]=emp;
    }
    void ShowAllSalaryInfo() const
    {
      for(int i=0; i<empNum; i++) 
        empList[i]->ShowSalaryInfo();
    }
    void ShowTotalSalary() const
    {
      int sum=0;
      for(int i=0; i<empNum; i++) 
        sum+=empList[i]->GetPay();
      cout<<"salary sum: "<<sum<<endl;
    }
    ~EmployeeHandler()
    {
      for(int i=0; i<empNum; i++)
        delete empList[i];
    }
};

int main(void)
{
  // 직원관리를 목적으로 설계된 컨트롤 클래스의 객체 생성
  EmployeeHandler handler;

  // 정규직 등록
  handler.AddEmployee(new PermanentWorker("KIM", 1000));
  handler.AddEmployee(new PermanentWorker("LEE", 1500));

  // 임시직 등록
  TemporaryWorker * alba = new TemporaryWorker("Jung", 700);
  alba->AddWorkTime(5);
  handler.AddEmployee(alba);

  // 영업직 등록
  SalesWorker * seller = new SalesWorker("Hong", 1000, 0.1);
  seller->AddSalesResult(7000);
  handler.AddEmployee(seller);

  // 이번 달에 지불해야 할 급여의 정보
  handler.ShowAllSalaryInfo();

  // 이번 달에 지불해야 할 급여의 총합
  handler.ShowTotalSalary();
  return 0;
}