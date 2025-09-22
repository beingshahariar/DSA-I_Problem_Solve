#include<iostream>
using namespace std;

void insertion_sort(int arr[],int n)
{
  for (int i = 1; i < n; i++)
  {
    int curr=arr[i];
    int prev =i-1;

    while (prev>=0 && arr[prev]>curr)
    {
      arr[prev+1]=arr[prev];
      prev--;
    }
    arr[prev+1]=curr;
  }
  
}

void print_arr(int arr[],int n)
{
  for (int i = 0; i < n; i++)
  {
    cout<<arr[i]<<" ";

  }
  cout<<endl;
}

int main()
{

  int arr[]={2,4,3,5,1};
  int n=sizeof(arr)/sizeof(int);
  insertion_sort(arr,n);
  print_arr(arr,n);

  return 0;
}