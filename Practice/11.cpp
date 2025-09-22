#include<iostream>
using namespace std;

struct node {
  int data;
  node* next;
  node(int value) {
      data = value;
      next = NULL;
  }
};

node*head=NULL;

void insert_last(node*& head, int value) 
{
  node* newItem = new node(value);
  if (head == NULL) {
      head = newItem;
      return;
  }
  node* temp = head;
  while (temp->next != NULL) {
      temp = temp->next;
  }
  temp->next = newItem;
}

node*reverse(node*head)
{
  node*prev=NULL;
  node*temp=head;
  node*next=NULL;

  while (temp!=NULL)
  {
    next=temp->next;
    temp->next=prev;
    prev=temp;
    temp=next;
  }
  return prev;
}

bool is_palindrome(node*head)
{
  if (head==NULL)
  {
   return true;
  }
  
  node*slow=head;
  node*fast=head;

  while (fast!=NULL && fast->next!=NULL)
  {
    slow=slow->next;
    fast=fast->next->next;
  }
  
  node*second_fast=reverse(slow->next);

  node*fast_half=head;
  node*second_half=second_fast;
  while (second_half!=NULL)
  {
    if (fast_half->data!=second_half->data)
    {
      return false;
    }
    fast_half=fast_half->next;
      second_half=second_half->next; 
  }
  slow->next=reverse(second_fast);
  return true;
}

int main()
{
    insert_last(head, 1);
    insert_last(head, 2);
    insert_last(head, 3);
    insert_last(head, 2);
    insert_last(head, 1);

    if (is_palindrome(head))
    {
      cout<<"Yes"<<endl;
    }
    else
    {
      cout<<"No"<<endl;
    }
    
  return 0;
}