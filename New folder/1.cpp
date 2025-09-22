#include<iostream>
using namespace std;

void bubble_sort(int arr[],int n)
{
  for (int i = 0; i < n-1; i++)
  {
    bool isSwap=false;
    for (int j = 0; j < n-i-1; j++)
    {
      if (arr[j]>arr[j+1])
      {
        swap(arr[j],arr[j+1]);
        isSwap=true;
      }
      
    }
    if (!isSwap)
    {
      return;
    }
    
    
  }
  
}

void selection_sort(int arr[],int n)
{
  for (int i = 0; i < n-1; i++)
  {
    int small_index=i;
    for (int j = i+1; j < n; j++)
    {
      if (arr[j]<arr[small_index])
      {
        small_index=j;
      }
      
    }
    swap(arr[i],arr[small_index]);
  }
  
}

void insertion_sort(int arr[],int n)
{
  for (int i = 1; i < n; i++)
  {
    int curr=arr[i];
    int prev=i-1;

    while (prev>=0 && arr[prev]>curr)
    {
      arr[prev+1]=arr[prev];
      prev--;
    }
    arr[prev+1]=curr;
  }
  
}

void print(int arr[],int n)
{
  for (int i = 0; i < n; i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

int main()
{
  int arr[]={2,3,5,4,1};
  int n=sizeof(arr)/sizeof(int);

  bubble_sort(arr,n);
  print(arr,n);

  selection_sort(arr,n);
  print(arr,n);

  insertion_sort(arr,n);
  print(arr,n);
  return 0;
}