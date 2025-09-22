#include<iostream>
using namespace std;

void selection_Sort (int arr[],int n){  //o(n^2)
  for (int i = 0; i < n-1; i++)
  {
    int smallestIndex = i;

    for (int j = i+1; j < n; j++)
    {
      if (arr[j]<arr[smallestIndex])
      {
        smallestIndex =j;
      }
        
    }
    swap(arr[i],arr[smallestIndex]);
    }
  }
  
int printArray (int arr[],int n){
  for (int i = 0; i < n; i++)
  {
      cout<<arr[i]<<" ";
  }
  cout<<endl;
  return 1;
}


int main(){
  
int n =5;
int arr[] = {4,1,5,2,3};

selection_Sort(arr,n);
printArray(arr,n);
  return 0;
}