#include<iostream>
#include<vector>
using namespace std;

// int linear(int arr[],int n,int target)
// {
//   for (int i = 0; i < n; i++)
//   {
//     if (arr[i]==target)
//     {
//       return i;
//     }
//   }
//   return -1;
// }

vector<int> linear(int arr[],int n,int target)
{
  vector<int>result;
  for (int i = 0; i < n; i++)
  {
    if (arr[i]==target)
    result.push_back(i);
    }
    return result;
  
}

int main()
{
  int arr[]={4, 2, 3, 2, 4, 2};
  int target;
  cout<<"Enter target:";
  cin>>target;
  int n =sizeof(arr)/sizeof(int);
  vector<int> result=linear(arr,n,target);

  for (int i = 0; i < result.size(); i++)
  {
    cout<<result[i]<<" ";
  }
  cout<<endl;
  
  return 0;
}