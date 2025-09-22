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
  
  node*insert(node*curr,int value)
  {
     if (curr==NULL)
     {
      return new node(value);
     }
     if (curr->data>value)
     {
      curr->left=insert(curr->left,value);
     }
     if (curr->data<value)
     {
      curr->right=insert(curr->right,value);
     }
     return curr;
  }

  void inorder(node*curr)
  {
    if (curr==NULL)
    {
      return;
    }
    inorder(curr->left);
    cout<<curr->data<<" ";
    inorder(curr->right);
    
  }

  void preorder(node*curr)
  {
    if (curr==NULL)
    {
      return;
    }
    cout<<curr->data<<" ";
    preorder(curr->left);
    preorder(curr->right);
    
  }

  void postorder(node*curr)
  {
    if (curr==NULL)
    {
      return;
    }
    postorder(curr->left);
    postorder(curr->right);
    cout<<curr->data<<" ";

  }

  bool search(node*curr,int value)
  {
    if (curr==NULL)
    {
      return false;
    }
    else if (curr->data==value)
    {
      return true;
    }

    if (curr->data>value)
    {
      return search(curr->left,value);
    }
    if (curr->data<value)
    {
      return search (curr->right,value);
    }
    
  }

  int min(node*curr)
  {
    if (curr==NULL)
    {
      cout<<"BST is empty";
      return -1;
    }
    while (curr->left!=NULL)
    {
      curr=curr->left;
    }
    return curr->data;
    
  }

  
  int max(node*curr)
  {
    if (curr==NULL)
    {
      cout<<"BST is empty";
      return -1;
    }
    while (curr->right!=NULL)
    {
      curr=curr->right;
    }
    return curr->data;
    
  }

  node*deleteNode(node*curr,int value)
  {
    if (curr==NULL)
    {
      return NULL;
    }
    if (curr->data>value)
    {
      curr->left=deleteNode(curr->left,value);
    }
    if (curr->data<value)
    {
      curr->right=deleteNode(curr->right,value);
    }
    
    else
    {
      if (curr->left==NULL)
      {
        node*temp=curr->right;
        delete curr;
        return temp;
      }
      else if (curr->right==NULL)
      {
        node*temp=curr->left;
        delete curr;
        return temp;
      }

      node*successor=curr->right;
      while (successor->left!=NULL)
      {
        successor=successor->left;
      }
      curr->data=successor->data;
      curr->right=deleteNode(curr->right,successor->data);  
    } 
    return curr;
    
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
  tree.inorder(tree.root);
  cout<<endl;

  cout<<"Preorder Traversal:";
  tree.preorder(tree.root);
  cout<<endl;

  cout<<"Postorder Traversal:";
  tree.postorder(tree.root);
  cout<<endl;


  bool found1=tree.search(tree.root,40);

  if (found1)
  {
    cout<<"40:Found"<<endl;
  }
  else
  {
    cout<<"Not Found."<<endl;
  }
  
  cout<<"Min value:"<<tree.min(tree.root)<<endl;
  cout<<"Max value:"<<tree.max(tree.root)<<endl;

  tree.root=tree.deleteNode(tree.root,70);
  
  cout<<"Inorder Traversal after Deletion:";
  tree.inorder(tree.root);
  cout<<endl;

  cout<<"Preorder Traversal after Deletion:";
  tree.preorder(tree.root);
  cout<<endl;


  return 0;
}