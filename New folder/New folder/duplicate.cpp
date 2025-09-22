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

void insert_tail(node*& head, int value) {
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

void remove_duplicates(node* head) {
  node* current = head;
  while (current != NULL && current->next != NULL) {
    if (current->data == current->next->data) {
      node* duplicate = current->next;
      current->next = current->next->next;
      delete duplicate; // মেমোরি clean
    } else {
      current = current->next;
    }
  }
}

void print_list(node* head) {
  while (head != NULL) {
    cout << head->data << " ->";
    head = head->next;
  }
  cout << "NULL" << endl;
}

int main() {
  node* head = NULL;
  insert_tail(head, 10);
  insert_tail(head, 10);
  insert_tail(head, 20);
  insert_tail(head, 30);
  insert_tail(head, 30);
  insert_tail(head, 40);

  cout << "Original list: ";
  print_list(head);

  remove_duplicates(head);

  cout << "Modified list: ";
  print_list(head);

  return 0;
}
