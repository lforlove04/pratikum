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
    exit(1);
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
    exit(EXIT_FAILURE);
}

void pop()
{
  struct Node *temp;
  if (top == NULL)
  {
    cout << "Stack Underflow" << endl;
    exit(1);
  }
  else
  {
    temp = top;
    top = top->link;
    temp->link = NULL;
    free(temp);
  }
}

void display()
{
  struct Node *temp;
  if (top == NULL)
  {
    cout << "Stack Underflow" << endl;
    exit(1);
  }
  else
  {
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
    cout << "Menu untuk program stack dengan singlelinkedlist " << endl;
    cout << "1 untuk memasukkan data(push)" << endl;
    cout << "2 untuk mengeluarkan data(pop)" << endl;
    cout << "3 untuk menampilkan semua data(display)" << endl;
    cout << "4 untuk menampilkan data teratas(peek)" << endl;
    cout << "0 untuk keluar program" << endl;
    cin >> pilih;

    switch (pilih)
    {
    case 1:
      cout << "Masukkan data (int):";
      cin >> data;
      push(data);
      break;
    case 2:
      cout << "Data dikeluarkan" << endl;
      pop();
      break;
    case 3:
      cout << "Data:" << endl;
      display();
      break;
    case 4:
      cout << "Data teratas:" << peek() << endl;
      break;
    default:
      exit(0);
      break;
    }
    display();
  }

  return 0;
}