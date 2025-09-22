#include<iostream>
using namespace std;

int binary(int arr[],int n)
{
  int start=0;
  int end=n-1;
  

  while (start<end)
  {
    int mid=(start+end)/2;
    // if (arr[mid]==target)
    // {
    //   return mid;
    // }
    if (arr[mid]>arr[mid+1])
    {
      end=mid;
    }
    else
    {
      start=mid+1;
    }
  }
  return start;
}

int main()
{
  int arr[]={1,3,8,12,4,2};
  // int target;
  // cout<<"Enter target:";
  // cin>>target;

  int n=sizeof(arr)/sizeof(int);
  int result=binary(arr,n);
  cout<<result<<endl;
  return 0;
}