#include<iostream>
using namespace std;

class Queue
{
  
  #define n 100

  int arr[100];
  int front=-1;
  int rear=-1;

  public:

  bool isEmpty()
  {
    return front ==-1 && rear==-1;
  }

  bool isFull()
  {
    return rear ==n-1;
  }

  void enqueue(int data)
  {
    if (isFull())
    {
      cout<<"Queue is overflow"<<endl;
    }
    else if(isEmpty())
    {
      front=rear=0;
      arr[rear]=data;
    }
    else
    {
      arr[++rear]=data;
    }
  }

  void dequeue()
  {
    if (isEmpty())
    {
      cout<<"Queue is underflowflow"<<endl;
    }
    else if(front==rear)
    {
      cout<<arr[front]<<endl;
      front=rear=-1;
    }
    else
    {
      cout<<arr[front++]<<endl;
    }

  }

  void display()
  {
    if (isEmpty())
    {
      cout<<"Queue is empty"<<endl;
    }
    for (int i = front; i <=rear; i++)
    {
      cout<<arr[i]<<" ";
    }
    cout<<endl;
  }

  void printFrontAndRear() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Front element: " << arr[front] << endl;
        cout << "Rear element: " << arr[rear] << endl;
    }
  }
};

int main()
{
  Queue q;
  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);
  q.display();
  q.printFrontAndRear();
  q.dequeue();
  q.display();

  return 0;
}