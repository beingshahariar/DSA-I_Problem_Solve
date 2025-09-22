#include<iostream>
#include<queue>
using namespace std;

class StackusingQueue
{
  queue<int>q1,q2;

  public:

  void push(int value)
  {
    q2.push(value);

    while (!q1.empty())
    {
      q2.push(q1.front());
      q1.pop();
    }
    swap(q1,q2);
  }

  void pop()
  {
    if (q1.empty())
    {
      cout<<"Stack is empty";
    }
    q1.pop();
  }

  int top()
  {
    if (q1.empty())
    {
      cout<<"Stack is empty";
      return -1;
    }
    return q1.front();
  }

  bool isEmpty() {
        return q1.empty();
    }
};






int main()
{
  StackusingQueue s;
  s.push(10); // ঢুকাও
  s.push(20);
  s.push(30);
  s.pop(); // 30 যাবে
  cout << "Top: " << s.top() << endl; // 20 হবে
  return 0;
}