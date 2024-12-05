#include<iostream>
 
using namespace std;
 
class node
{
public:
  int data;
  node *next;

  node()
  {
    data = 0;
    next = nullptr;
  }
 
};
 
 
class list
{
  node *head;
 
public:
 
  list() 
  {
    head = nullptr;
  }
  
  void insertfirst(int iData)
  {
    node *newNode = new node;
    newNode->data = iData;
 
    //if (!head)  //not optimized
    //{
    //  newNode->next = nullptr;
    //  head = newNode;
    //}
    //else
    //{
    //  newNode->next = head;
    //  head = newNode;
    //}
 
    newNode->next = head;
    head = newNode;
  }
  void insertlast(int iData)
  {
    node *newNode = new node;
    
    newNode->data = iData;
    newNode->next = nullptr;
    
    node* temp = nullptr;
 
    if (!head)//List is empty
    {
      head = newNode;
    }
    else
    {
      temp = head;
      while (temp->next)
        temp = temp->next;
 
      temp->next = newNode;
    }
  }
 
  void display()
  {
    node* temp = head;
    while (temp)
    {
      cout << "|" << temp->data << "|->";
      temp = temp->next;
    }
  }
 
  void deleteall()
  {
    cout << "\ndeleting nodes ::" << endl;
 
    node* temp = head;
    while (temp)
    {
      head = temp->next;
      temp->next = nullptr;
      cout << "|" << temp->data << "| deleted" << endl;
      delete (temp);
      temp = head;
    }
  }
 
  void reverselist()
  {
    node *prev = nullptr;
    node *current = head;
    node * next = nullptr;
 
    while (current)
    {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
 
    head = prev;
  }
};
 
int main()
{
  list lst;
  lst.insertfirst(111);
  lst.insertlast(10);
  lst.insertlast(20);
  lst.insertlast(30);
  lst.insertlast(40);
 
  lst.display();
  
  lst.insertfirst(8);
  lst.insertfirst(6);
  lst.insertfirst(4);
  lst.insertfirst(2);
  cout << "\n\n";
  lst.display();
 
  cout << "\nReverse list :: \n";
  lst.reverselist();
  lst.display();
 
  lst.deleteall();
 
  return 0;
}