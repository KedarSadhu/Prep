// BinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<queue>

using namespace std;

class Node
{
public:
  Node *left;
  int data;
  Node *right;

  Node(int no)
  {
    left = nullptr;
    data = no;
    right = nullptr;
  }
};

Node * InsertBstNode(Node* root, int iNo)
{
  if (root == nullptr)
  {
    root = new Node(iNo);
    return root; 
  }

  if (iNo > root->data)
  {
    root->right = InsertBstNode(root->right, iNo);
  }
  else
  {
    root->left = InsertBstNode(root->left, iNo);
  }

  return root;
}

void Display(Node * root)
{
  queue<Node *> q;
  q.push(root);
  q.push(nullptr);

  while (!q.empty())
  {
    Node * temp = q.front();
    q.pop();

    if (temp == nullptr)
    {
      cout << endl;
      if (!q.empty())
      {
        q.push(nullptr);
      }
    }
    else
    {
      cout << temp->data << " ";
      if (temp->left)
        q.push(temp->left);

      if (temp->right)
        q.push(temp->right); 
    }
  }

 }


bool SearchNodeRecursive(Node * root,int iNo)
{
  if (root == nullptr)
    return false;

  if (root->data == iNo)
    return true;

  if (iNo > root->data)
    return SearchNodeRecursive(root->right, iNo);

  else
    return SearchNodeRecursive(root->left, iNo);
}

bool SearchNode(Node * root, int iNo)
{
  Node * temp = root;

  while (temp != nullptr)
  {
    if (temp->data == iNo)
      return true;

    if (iNo > temp->data)
      temp = temp->right;

    else
      temp = temp->left;
  }

  return false;
}

int main()
{
  Node *root = nullptr;
  
  int data = 0;
  while (true)
  {
    cout << "Enter data to insert in BST :: ";
    cin >> data;
    if (data == -1)
      break;
    root = InsertBstNode(root, data);
  }

  cout << "Display :: \n";
  Display(root);

  cout << "\n\nEnter data for searching node ::";
  cin >> data;

  cout << "Element found :: " << SearchNodeRecursive(root,data) <<endl;
  cout << "Element found :: " << SearchNode(root, data) << endl;

  return 0;
}
