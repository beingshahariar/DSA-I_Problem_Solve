#include<iostream>
using namespace std;

class Stack
{
  #define n 100

  int arr[100];
  int top=-1;

  public:

  bool isEmpty()
  {
    return top==-1;
  }
  bool isFull()
  {
    return top==n-1;
  }

  void push(int data)
  {
    if (isFull())
    {
      cout<<"Stack is overflow"<<endl;
    }

    arr[++top]=data;
    
  }

  int pop()
  {
    if (isEmpty())
    {
      cout<<"Stack is underflow"<<endl;
      return -1;
    }
    return arr[top--];
  }

  int peek()
  {
    if (isEmpty())
    {
      cout<<"Stack is underflow"<<endl;
      return -1;
    }
    return arr[top];
  }

  void display()
  {
    if (isEmpty())
    {
      cout<<"Stack is empty"<<endl;
    }
    for (int i = top; i>=0; i--)
    {
      cout<<arr[i]<<" ";
    }
    cout<<endl;
    
  }
};


int main()
{

  Stack st;
  st.push(10);
  st.push(20);
  st.push(30);
  st.pop();
  st.display();
  return 0;
}