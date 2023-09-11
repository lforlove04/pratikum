#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int isEmpty();

struct Node
{
  int data;
  struct Node *link;
};
struct Node *top;

void push(int data)
{
  struct Node *temp;
  temp = (struct Node *)malloc(sizeof(struct Node));
  if (!temp)
  {
    cout << "Heap Underflow" << endl;
  }
  temp->data = data;
  temp->link = top;
  top = temp;
}

int isEmpty(Node *top)
{
  return top == NULL;
}

int peek()
{
  if (!isEmpty(top))
    return top->data;
  else
    return 0;
}

void pop()
{
  struct Node *temp;
  if (top == NULL)
  {
    return;
  }
  else
  {
    temp = top;
    top = top->link;
    temp->link = NULL;
    free(temp);
  }
}

void updateData(int x)
{
  struct Node *temp;
  if (top == NULL)
  {
    return;
  }
  else
  {
    temp = top;
    bool found = false;
    while (!found)
    {
      if (temp->data == x)
      {
        found = true;
      }
      temp = temp->link;
    }

    if (found)
    {
      cout << "Change data to: ";
      int y;
      cin >> y;
      temp->data = y;
      cout << "Data updated." << endl;
    }
    else
    {
      cout << "Data not found." << endl;
    }
  }
}

void searchData(int x)
{
  struct Node *temp;
  if (top == NULL)
  {
    return;
  }
  else
  {
    temp = top;
    bool found = false;
    while (!found)
    {
      if (temp->data == x)
      {
        found = true;
      }
      temp = temp->link;
    }

    if (found)
    {
      cout << "Found data : " << temp->data;
    }
    else
    {
      cout << "Data not found." << endl;
    }
  }
}

void display()
{
  struct Node *temp;
  if (top == NULL)
  {
    cout << "Stack Underflow" << endl;
  }
  else
  {
    cout << "Data : ";
    temp = top;
    while (temp != NULL)
    {
      cout << "[" << temp->data << "]";
      temp = temp->link;
    }
    cout << endl;
  }
}

int main(void)
{
  int data, pilih;
  while (true)
  {
    system("cls");
    display();

    cout << endl;
    cout << "Stack Single Linked List" << endl;
    cout << "1. Enter data(push)" << endl;
    cout << "2. Delete data(pop)" << endl;
    cout << "3. Top data(peek)" << endl;
    cout << "4. Update data" << endl;
    cout << "5. Search data" << endl;
    cout << "0. Exit" << endl;
    cin >> pilih;

    switch (pilih)
    {
    case 1:
      cout << "Input data (int):";
      cin >> data;
      push(data);
      break;

    case 2:
      cout << "Data deleted" << endl;
      pop();
      system("pause");
      break;

    case 3:
      cout << "Data teratas:" << peek() << endl;
      system("pause");
      break;

    case 4:
      cout << "Enter data key for update : ";
      cin >> data;
      updateData(data);
      system("pause");
      break;

    case 5:
      cout << "Finda data : ";
      cin >> data;
      searchData(data);
      system("pause");
      break;

    default:
      exit(0);
      break;
    }
    display();
  }
  return 0;
}