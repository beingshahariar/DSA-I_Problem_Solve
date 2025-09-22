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
    head=newItem;
    return;
  }
  node*temp=head;
  while (temp->next!=NULL)
  {
    temp=temp->next;
  }
  temp->next=newItem;
  
}

node* merge_sort(node*l1,node*l2)
{
  node*dummy=new node(-1);
  node*temp=dummy;

  while (l1 && l2)
  {
    if (l1->data<l2->data)
    {
      temp->next=l1;
      l1=l1->next;
    }
    else if (l1->data>l2->data)
    {
      temp->next=l2;
      l2=l2->next;
    } 
    temp=temp->next;
  }

  if (l1!=NULL)
  {
    temp->next=l1;
  }
  else
  {
    temp->next=l2;
  }
  return dummy->next;
}

void print_list(node*head)
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
  node*l1=NULL;
  node*l2=NULL;

  insert_last(l1,10);
  insert_last(l1,30);
  insert_last(l1,50);
  print_list(l1);

  insert_last(l2,20);
  insert_last(l2,40);
  insert_last(l2,60);
  print_list(l2);

  node*merge=merge_sort(l1,l2);
  print_list(merge);

  
  return 0;
}