#include <iostream>
using namespace std;

class SortRule
{
  public:
    virtual bool operator()(int num1, int num2) const =0;
};

class AscendingSort : public SortRule // 오름차순
{
  public:
    bool operator()(int num1, int num2) const
    {
      if(num1>num2)
        return true;
      else
        return false;
    }
};

class DescendingSort : public SortRule // 내림차순
{
  public:
    bool operator()(int num1, int num2) const
    {
      if(num1<num2)
        return true;
      else
        return false;
    }
};

class DataStorage // int형 정수의 저장소, 단순히 정수 데이터를 저장할 수 있도록 설계된 클래스이다.
{
  private:
    int * arr;
    int idx;
    const int MAX_LEN;
  public:
    DataStorage(int arrlen) : idx(0), MAX_LEN(arrlen) // 생성자의 인자를 통해서, 저장할 정수의 최대 개수를 결정할 수 있도록 정의
    {
      arr=new int[MAX_LEN]; // 생성자의 인자를 통해서, 저장할 정수의 최대 개수를 결정할 수 있도록 정의
    }
    void AddData(int num) // 정수형 데이터의 저장을 목적으로 정의된 함수이다.
    {
      if(MAX_LEN<=idx)
      {
        cout<<"더 이상 저장이 불가능합니다."<<endl;
        return;
      }
      arr[idx++]=num;
    }
    void ShowAllData()  // 데이터를 배열에 저장된 순서대로 출력하는 함수이다.
    {
      for(int i=0; i<idx; i++)
        cout<<arr[i]<<' ';
        cout<<endl;
    }
    void SortData(const SortRule& functor)
    {
      for(int i=0; i<(idx-1); i++)
      {
        for(int j=0; j<(idx-1)-i; j++)
        {
          if(functor(arr[j], arr[j+1]))
          {
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
          }
        }
      }
    }
};

int main(void)
{
  DataStorage storage(5);
  storage.AddData(40);
  storage.AddData(30);
  storage.AddData(50);
  storage.AddData(20);
  storage.AddData(10);

  storage.SortData(AscendingSort());  // 데이터를 저장한 후에 정렬을 진행하고 있다.
  // 그런데 이때 AscendingSort 객체를 임시객체의 형태로 생성해서 전달하고 있다.
  storage.ShowAllData();

  storage.SortData(DescendingSort()); // 이번에는 DexcendingSort 객체를 임시객체의 형태로 생성해서 인자로 전달하고 있다.
  // 따라서 72행의 정렬결과와는 다른 방식으로 정렬이 이뤄질 것이다.
  storage.ShowAllData();
  return 0;
}