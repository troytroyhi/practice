// 클래스의 선언을 담는다.
// 4,5,9행은 헤더파일의 중복포함 문제를 해결하기 위한 매크로 선언이다.
// 7~13행은 클래스 Car에서 제한적으로 사용되는 상수의 선언이므로 클래스 Car와 같은 파일에 선언하였다.
#ifndef __CARH_H__
#define __CAR_H__

namespace CAR_CONST
{
  enum{
    ID_LEN=20, MAX_SPD=200, FUEL_STEP=2,
    ACC_STEP=10, BRK_STEP=10
  };
}

class Car
{
  private:
  char gamerID[CAR_CONST::ID_LEN];
  int fuelGauge;
  int curSpeed;
  public:
    void InitMembers(char *ID, int fuel);
    void ShowCarState();
    void Accel();
    void Break();
};

#endif