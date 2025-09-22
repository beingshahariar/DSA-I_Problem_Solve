#include<iostream>
using namespace std;

int linearsearch(int arr[],int size,int target)
{
  for (int i = 0; i < size; i++)
  {
    if (arr[i]>target)
    {
      return arr[i];
    }
    
  }
  return -1;
}

int main()
{
  int arr [] = {3,5,7,2,8,10};
  int size = sizeof(arr)/sizeof(arr[0]);
  int target = 6;

  int result = linearsearch(arr,size,target);
    cout << result << endl;
  
}