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

void insert_last(node*&head,int value)
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

node* find_middle(node*head)
{
  node*slow=head;
  node*fast=head;

  while (fast!=NULL && fast->next!=NULL)
  {
    slow=slow->next;
    fast=fast->next->next;
  }
  return slow;
  
}

void print(node*head)
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
  insert_last(head,10);
  insert_last(head,20);
  insert_last(head,30);
  insert_last(head,40);
 // insert_last(head,50);
  print(head);
 node* middle= find_middle(head);
 cout<<"Middle Node:"<<middle->data<<endl;

  return 0;
}