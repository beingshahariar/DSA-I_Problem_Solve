#include<iostream>
using namespace std;

void linearsearch(int arr[], int size, int target) {
  bool found = false; // চেক করার জন্য যে টার্গেট পাওয়া গেছে কিনা

  cout << "[";
  for (int i = 0; i < size; i++) {
      if (arr[i] == target) {
          if (found) cout << ", "; 
          cout << i;
          found = true; // একবার টার্গেট পাওয়া গেলে true করে দিচ্ছি
      }
  }
  cout << "]" << endl;

  if (!found) cout << "Target not found!" << endl;
}

int main()
{
  int arr [] = {4,2,3,2,4,2};
  int size = sizeof(arr)/sizeof(arr[0]);
  int target = 2;

linearsearch(arr,size,target);
  return 0;
}