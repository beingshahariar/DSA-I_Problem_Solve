#include<iostream>
using namespace std;

struct node
{
 int data;
 node*next;

 node(int value)
 {
  data=value;
  next=NULL;
 }
};

node*head=NULL;
node*tail=NULL;

void insert_last(int value)
{
  node*newItem=new node(value);
  if (head==NULL)
  {
    head=tail=newItem;
    return;
  }
  node*temp=head;
  while (temp->next!=NULL)
  {
    temp=temp->next;
  }
  temp->next=newItem;
  
}

void detect_and_remove()
{
  node*slow=head;
  node*fast=head;

  while (fast!=NULL && fast->next!=NULL)
  {
    slow=slow->next;
    fast=fast->next->next;
    if (slow==fast)
    {
      cout<<"Cycle detect"<<endl;
      break;;
    }
    
  }

  if(slow!=fast)
    {
     cout<<"No cycle detect"<<endl;
     return;
    }

  slow=head;
  node*temp=fast;

  while (slow!=fast)
  {
   // temp=fast;
    slow=slow->next;
    fast=fast->next;
  }
  temp->next=NULL;
  cout<<"Cycle removed"<<endl;

}

void print()
{
  if (head==NULL)
  {
    cout<<"Nothing found.";
    return;
  }
  node*temp=head;
  while (temp!=NULL)
  {
    cout<<temp->data<<"-";
    temp=temp->next;
  }
  cout<<endl;
}

int main()
{
  insert_last(10);
  insert_last(20);
  insert_last(30);
  insert_last(40);
  print();

  head->next->next->next->next=head->next;
  detect_and_remove();
  print();
  return 0;
}