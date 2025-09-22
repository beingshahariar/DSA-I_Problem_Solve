#include<iostream>
using namespace std;

int linearsearch(int arr[],int size,int target)
{
  for (int i = 0; i < size; i++)
  {
    if (arr[i]==target)
    {
      return i;
    }
    
  }
  return -1;
}

int main()
{
  int arr [] = {5,3,8,1,9};
  int size = sizeof(arr)/sizeof(arr[0]);
  int target = 8;

  int result = linearsearch(arr,size,target);
    cout << result << endl;
  
}