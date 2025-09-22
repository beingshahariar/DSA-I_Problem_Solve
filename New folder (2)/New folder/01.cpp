#include<iostream>
using namespace std;

struct node
{
  int data;
  node*next;

  node(int value,node*nxt)
  {
    data=value;
    next=nxt;

  }
};

class Graph
{
  private:
  bool directed;
  int n;
  int adj[100][100];
  node*adj_list[100];

  public:
  Graph(int v,bool dir)
  {
    n=v;
    directed=dir;

    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        adj[i][j]=0;
      }
      adj_list[i]=NULL;
    }
    
  }

  void add_edge(int u,int v)
  {
    adj[u][v]=1;
    if (!directed)
    {
      adj[v][u]=1;
    }

    node*newNode=new node(v,adj_list[u]);
    adj_list[u]=newNode;

    if (!directed)
    {
      node*newNode=new node(u,adj_list[v]);
    adj_list[v]=newNode;
    }
    
  }

  void print_matrix()
  {
    cout<<"Adjacency Matrix:\n";
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        cout<<adj[i][j]<<" ";
      }
      cout<<endl;
    }
  }

  void print_list()
  {
    cout<<"Adjacency List:\n";
    for (int i = 1; i <= n; i++)
    {
      cout<<i<<":";
      node*temp=adj_list[i];
      while (temp!=NULL)
      {
        cout<<temp->data<<" ";
        temp=temp->next;
      }
      cout<<endl;
    }
    
  }

};


int main()
{
 Graph g(4,false);
 g.add_edge(1,2);
 g.add_edge(1,3);
 g.add_edge(2,4);

 g.print_matrix();
 cout<<endl;
 g.print_list();

  return 0;
}