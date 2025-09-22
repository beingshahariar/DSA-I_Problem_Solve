#include<iostream>
using namespace std;

int linear(int arr[],int n,int target)
{
  for (int i = 0; i < n; i++)
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
  int arr[]={3,5,7,2,8,10};
  int target;
  cout<<"Enter target:";
  cin>>target;

  int n=sizeof(arr)/sizeof(int);
  int result=linear(arr,n,target);
  cout<<result<<endl;
  return 0;
}