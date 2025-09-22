#include<iostream>
using namespace std;

struct node
{
  int data;
  node*left;
  node*right;

  node(int value)
  {
    data=value;
    left=NULL;
    right=NULL;
  }
};


class BST
{
  public:
  node*root;

  BST()
  {
    root=NULL;
  }

  node*insert(node* current,int value)
  {
    if (current==NULL)
    {
      return new node(value);
    }
    if (value<current->data)
    {
     current->left=insert(current->left,value);
    }
    if (value>current->data)
    {
      current->right=insert(current->right,value);
    }
    return current;
  }

  void in_order(node*current)
  {
    if (current==NULL)
    {
      return;
    }

    in_order(current->left);
    cout<<current->data<<" ";
    in_order(current->right);
    
  }

  void pre_order(node*current)
  {
    if (current==NULL)
    {
      return;
    }

    cout<<current->data<<" ";
    pre_order(current->left);
    pre_order(current->right);
    
  }

  void post_order(node*current)
  {
    if (current==NULL)
    {
      return;
    }

    post_order(current->left);
    post_order(current->right);
    cout<<current->data<<" ";
    
  }
  
  bool search(node*current,int value)
  {
    if (current==NULL)
    {
      return false;
    }
    if (current->data==value)
    {
      return true;
    }
    if (current->data>value)
    {
      return search (current->left,value);
    }
    if (current->data<value)
    {
      return search(current->right,value);
    }
    
    
  }

  int min(node*current)
  {
    if (current==NULL)
    {
      cout<<"BST is empty"<<endl;
      return -1;
    }

    while (current->left!=NULL)
    {
      current=current->left;
    }
    
    return current->data;
  }

  int max(node*current)
  {
    if (current==NULL)
    {
      cout<<"BST is empty"<<endl;
      return -1;
    }

    while (current->right!=NULL)
    {
      current=current->right;
    }
    
    return current->data;
  }

  node*deleteNode(node*current,int value)
  {
    if (current==NULL)
    {
      return NULL;
    }
    if (current->data>value)
    {
      current->left=deleteNode(current->left,value);
    }
    if (current->data<value)
    {
      current->right=deleteNode(current->right,value);
    }
    else
    {
      if (current->left==NULL)
      {
        node*temp=current->right;
        delete current;
        return temp;
      }
      else if (current->right==NULL)
      {
        node*temp=current->left;
        delete current;
        return temp;
      }

      node*succuessor=current->right;
      while (succuessor->left!=NULL)
      {
        succuessor=succuessor->left;
      }
      current->data=succuessor->data;
      current->right=deleteNode(current->right,succuessor->data);
    }
    return current;
  }

};

int main()
{

  BST tree;
  tree.root=tree.insert(tree.root,50);
  tree.insert(tree.root,30);
  tree.insert(tree.root,70);
  tree.insert(tree.root,20);
  tree.insert(tree.root,40);
  tree.insert(tree.root,60);
  tree.insert(tree.root,80);

  cout<<"Inorder Traversal:";
  tree.in_order(tree.root);
  cout<<endl;

  cout<<"Preorder Traversal:";
  tree.pre_order(tree.root);
  cout<<endl;

  cout<<"Postorder Traversal:";
  tree.post_order(tree.root);
  cout<<endl;

  bool found1=tree.search(tree.root,40);
  bool found2=tree.search(tree.root,90);
  if (found1)
  {
    cout<<"Found."<<endl;
  }
  else
  {
    cout<<"Not Found."<<endl;
  }

  if (found2)
  {
    cout<<"Found."<<endl;
  }
  else
  {
    cout<<"Not Found."<<endl;
  }

  cout<<"Minimum Vlaue:"<<tree.min(tree.root);
  cout<<endl;
  cout<<"Maximum Vlaue:"<<tree.max(tree.root);
  cout<<endl;

  tree.root=tree.deleteNode(tree.root,70);
  cout<<"Inorder Traversal after Deletion:";
  tree.in_order(tree.root);
  cout<<endl;

  cout<<"Preorder Traversal after Deletion:";
  tree.pre_order(tree.root);
  cout<<endl;

  return 0;
}