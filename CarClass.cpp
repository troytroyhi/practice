#include <iostream>
#include <cstring>
using namespace std;

namespace CAR_GO
{
  enum
  {
    NAME_LEN=20,
    MAX_SPD=200,
    ACC_STEP=10
  };
}

class Car
{
  private:
    char name[124];
    int speed;

  public:
    void InitMembers(char * id);
    void go();
    void Accel();
    int GetCurrentSpeed();
};

void Car::InitMembers(char * id)
{
  strcpy(name, id);
  speed=0;
}

void Car::go()
{
  cout<<"이름: "<<name<<endl;
  cout<<"현재속도: "<<speed<<endl<<endl;
}

void Car::Accel()
{
  if((speed+CAR_GO::ACC_STEP)>=CAR_GO::MAX_SPD)
  {
    speed=CAR_GO::MAX_SPD;
    return;
  }
  speed+=CAR_GO::ACC_STEP;
}

int Car::GetCurrentSpeed()
{
  return speed;
}

int main(void)
{
  Car *myCar = new Car();
  myCar->InitMembers("myCar");
  myCar->Accel();
  myCar->Accel();
  myCar->Accel();
  myCar->Accel();
  myCar->Accel();
  myCar->Accel();

  cout<<myCar->GetCurrentSpeed()<<endl;
  delete myCar;
  return 0;
}


