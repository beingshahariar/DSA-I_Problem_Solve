#include <iostream>
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

void insert(int value)
{
  node*newItem=new node(value);
  if (head==NULL)
  {
    head=newItem;
  }
  else
  {
    node*temp=head;
    while (temp->next!=NULL)
    {
      temp=temp->next;
    }
    temp->next=newItem;
  }
  
}

node* reverse_list(node* head) {
  node* prev = NULL;
  node* temp = head;
  node* next = NULL;

  while (temp != NULL) {
      next = temp->next;
      temp->next = prev;
      prev = temp;
      temp = next;
  }

  return prev;
}

void print_forward()
{
  node*temp=head;
  while (temp!=NULL)
  {
    cout<<temp->data<<"-";
    temp=temp->next;
  }
  cout<<"NULL"<<endl;

}

void print_backward(node*temp)
{
  if (temp==NULL)
  {
    return;
  }
  print_backward(temp->next);
  cout<<temp->data<<"-";
  
}


int main()
{
  insert(10);
  insert(20);
  insert(30);
  insert(40);
 head= reverse_list(head);
  print_forward();
  // print_backward(head);
  // cout<<"NULL"<<endl;
  return 0;
}