#include <iostream>
#include <cstring>
#include "Car.h" // 멤버함수의 정의부분을 컴파일 하는데도 클래스의 선언 정보가 필요하다. 멤버함수에서 접근하는 변수의 존재유무를
// 확인해야하기 때문이다. 그리고 이름공간 CAR_CONST에 선언된 상수의 사용을 위해서도 이 헤더파일은 포함되어야 한다.
using namespace std;

void Car::InitMembers(char * ID, int fuel)
{
  strcpy(gamerID, ID);
  fuelGauge=fuel;
  curSpeed=0;
}

void Car::ShowCarState()
{
  cout<<"소유자ID: "<<gamerID<<endl;
  cout<<"연료량: "<<fuelGauge<<"%"<<endl;
  cout<<"현재속도: "<<curSpeed<<"km/s"<<endl<<endl;
}

void Car::Accel()
{
  if(fuelGauge<=0)
    return;
  else
    fuelGauge-=CAR_CONST::FUEL_STEP;

  if((curSpeed+CAR_CONST::ACC_STEP)>=CAR_CONST::MAX_SPD)
  {
    curSpeed=CAR_CONST::MAX_SPD;
    return;
  }
  curSpeed+=CAR_CONST::ACC_STEP;
}

void Car::Break()
{
  if(curSpeed<CAR_CONST::BRK_STEP)
  {
    curSpeed=0;
    return;
  }
  curSpeed-=CAR_CONST::BRK_STEP;
}