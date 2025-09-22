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

void remove_duplicate()
{
  node*temp=head;
  while (temp!=NULL && temp->next!=NULL)
  {
    if (temp->data==temp->next->data)
    {
      node*del_dup=temp->next;
      temp->next=temp->next->next;
      delete del_dup;
    }
    else
    {
    temp=temp->next;
    }
  }
  
}

void print_list()
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
  insert_last(10);
  insert_last(20);
  insert_last(30);
  insert_last(30);
  insert_last(40);

  cout<<"Print the list:";
  print_list();
  cout<<"Modified list:";
  remove_duplicate();
  print_list();
  return 0;
}