#include<iostream>
using namespace std;

class Stack
{
  struct node
  {
    char data;
    node*next;

    node(char value)
    {
      data=value;
      next=nullptr;
    }
  };
  node*top=nullptr;

public:

  void push(char value)
  {
    node*newItem= new node(value);
    newItem->next=top;
    top=newItem;

  }

  void pop()
  {
    if (top==NULL)
    {
      cout<<"Stack is empty"<<endl;
    }
    node*temp=top;
    top=top->next;
    temp->next=NULL;
    delete temp;
    
  }

  char peek()
  {
    if (top==NULL)
    {
      cout<<"Stack is empty"<<endl;
      return -1;
    }

    return top->data;
  }

  bool isEmpty()
  {
    return top==nullptr;
  }

  
};

void reversed_order(string str)
  {
    Stack st;
    for(char c:str)
    { 
      st.push(c);
    }
    cout<<"Reversed String:";
    while (!st.isEmpty())
    {
      cout<<st.peek();
      st.pop();
    }
    cout<<endl;
  }


int main()
{
  string s="HEllo";
  cout<<"Orginal Input:"<<s<<endl;
  reversed_order(s);

  return 0;
}