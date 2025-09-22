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

void insert_head(node*&head,int value)
{
  node*newItem=new node(value);
  newItem->next=head;
  head=newItem;
}

void insert_tail(node*&head,int value)
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
 // tail=newItem;
  //newItem=NULL;
  
}

node* merge_sorted_list(node*l1,node*l2)
{
  node*dummy=new node(-1);
  node*tail=dummy;

  while (l1&&l2)
  {
    if (l1->data < l2->data)
    {
      tail->next=l1;
      l1=l1->next;
    }
    else
    {
      tail->next=l2;
      l2=l2->next;
    }
    tail=tail->next;
  }
  if (l1!=NULL)
  {
    tail->next=l1;
  }
  else
  {
    tail->next=l2;
  }

  return dummy->next;
}

void print_forward(node*head)
{
  node*temp=head;
  while (temp!=NULL)
  {
    cout<<temp->data<<"-";
    temp=temp->next;
  }
  cout<<"NULL"<<endl;
}

void print_reverse(node*temp)
{
  if (temp==NULL)
  {
    return;
  }
  print_reverse(temp->next);
  cout<<temp->data<<"-";

}


int main()
{
  node*l1=NULL;
  node*l2=NULL;
  insert_tail(l1, 10);
  insert_tail(l1, 30);
  insert_tail(l1, 50);

  insert_tail(l2, 20);
  insert_tail(l2, 40);
  insert_tail(l2, 60);

  node*merge_head=merge_sorted_list(l1,l2);
  cout<<"Merged list:"<<endl;
  print_forward(merge_head);


  return 0;
}