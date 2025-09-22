#include<iostream>
#include<stack>
using namespace std;

class Queue
{
 struct node
 {
  int data;
  node*next;

  node(int value)
  {
    data=value;
    next=nullptr;
  }
 };
node*front=nullptr;
node*rear=nullptr;

public:

bool isEmpty() {
    return front == nullptr;
}

void enqueue(int value)
{
    node* newItem = new node(value);

    if (isEmpty())
    {
        front = rear = newItem;
    }
    else
    {
        rear->next = newItem;
        rear = newItem;
    }
}


void dequeue()
{
  if (isEmpty())
  {
    cout<<"Queue is empty"<<endl;
  }
  else
  {
    node*temp=front;
    front=front->next;
    temp->next=NULL;
    if (front == nullptr) 
    {
     rear = nullptr;
    }
    delete temp;
  }
}

int peek()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    return front->data;
}


void printQueue()
{
    node* temp = front;
    while (temp != nullptr)
    {
        cout << temp->data;
        if (temp->next != nullptr) cout << " ";
        temp = temp->next;
    }
    cout << endl;
}


};

void reversed_order(Queue &q)
{
  stack<int> st;

  while (!q.isEmpty())
  {
    st.push(q.peek());
    q.dequeue();
  }
  while (!st.empty())
  {
    q.enqueue(st.top());
    st.pop();
  }
  
  
}


int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << "Main Queue: ";
    q.printQueue();

    reversed_order(q);

    cout << "Reversed Queue: ";
    q.printQueue();

    return 0;
}
