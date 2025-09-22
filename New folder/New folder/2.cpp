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

void insert_head(int value)
{
  node*newItem=new node(value);
  newItem->next=head;
  head=newItem;
}

void insert_last(int value)
{
  node*newItem=new node(value);
  if (head==NULL)
  {
    head=newItem;
    tail=newItem;
    return;
  }
  node*temp=head;
  while (temp->next!=tail)
  {
    temp=temp->next;
  }
  temp->next=newItem;
  tail=newItem;
  //newItem=NULL;
  
}

void insert_any(int value,int target)
{
  node*newItem=new node(value);
  if (target==0)
  {
    insert_head(value);
  } 
  else if (target<0)
  {
    return;
  }
  else
  {
  node*temp=head;
  for (int i = 0; i < target-1; i++)
  {
    temp=temp->next;
  }
  newItem->next=temp->next;
  temp->next=newItem;
  } 
  
  
}



void reverse_list()
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
  head=prev;
}

int search(int key)
{
  if (head==NULL)
  {
    return -1;
  }
  
  node*temp=head;
  int index=0;
  while (temp->data!=key)
  {
    index++;
    temp=temp->next;
  }
  return index;
}

int find_middle()
{
  if (head==NULL)
  {
    return-1;
  }
  node*temp=head;
  int count=0;
  while (temp!=NULL)
  {
    count++;
    temp=temp->next;
  }
  int middle=count/2;
  temp=head;
  for (int i = 0; i <= middle-1; i++)
  {
    temp=temp->next;
  }
  return temp->data;

}

//detect and remove a cycle

void detect_and_remove_cycle()
{
  node*temp1=head;
  node*temp2=head;
  //step1:cycle detect
  while (temp2!=NULL && temp2->next!=NULL)
  {
    temp1=temp1->next;
    temp2=temp2->next->next;
  
  if (temp1==temp2)
  {
    cout<<"Cycle detect"<<endl;
    break;
  }
}
  if (temp1!=temp2)
  {
    cout<<"No cycle detect"<<endl;
    return;
  }
  
  //step:2 find start of the cycle
  temp1=head;
  node*prev=temp2;

  while (temp1!=temp2)
  {
   // prev=temp2;
    temp1=temp1->next;
    temp2=temp2->next;
  }
  //step 3:break the cycle
  prev->next=NULL;
  cout<<"Cycle removed."<<endl;
  
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
 insert_head(40);
 insert_head(30);
 insert_head(20);
 insert_head(10);
//  cout<<"Output:";
//  print_forward();
//  cout<<"Reverse Output:";
//  print_reverse(head);
//  cout<<"NULL"<<endl;
//  insert_last(40);
//  print_forward();
//  print_reverse(head);
//  cout<<"NULL"<<endl;
//  insert_any(60,3);
//  print_forward();
//  int pos=search(30);
// cout<<"The position is:"<<pos<<endl;
//  print_forward();
//  reverse_list();
 print_forward();
//  cout<<find_middle()<<endl;
 //print_forward();
 head->next->next->next->next=head->next;
 detect_and_remove_cycle();
 print_forward();

  return 0;
}