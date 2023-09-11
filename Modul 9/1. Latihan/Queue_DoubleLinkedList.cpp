#include <bits/stdc++.h>
using namespace std;

class QNode
{
public:
  int key;
  QNode *next;
  QNode *prev;
};

class Queue
{
public:
  QNode *front, *rear;
};

QNode *newNode(int k)
{
  QNode *temp = new QNode();
  temp->key = k;
  temp->next = NULL;
  temp->prev = NULL;
  return temp;
}

Queue *createQueue()
{
  Queue *q = new Queue();
  q->front = q->rear = NULL;
  return q;
}

void enQueue(Queue *q, int k)
{
  QNode *temp = newNode(k);

  if (q->rear == NULL)
  {
    q->front = q->rear = temp;
    return;
  }

  temp->prev = q->rear;
  q->rear->next = temp;
  q->rear = temp;
}

void deQueue(Queue *q)
{
  if (q->front == NULL)
    return;

  QNode *temp = q->front;
  q->front = q->front->next;

  if (q->front == NULL)
    q->rear = NULL;
}

void upQueue(Queue *q, int x)
{
  QNode *temp = q->front;
  bool found = false;

  while (!found)
  {
    if (temp->key == x)
    {
      found = true;
      break;
    }
    temp = temp->next;
  }

  if (found)
  {
    cout << "Change data to: ";
    int y;
    cin >> y;
    temp->key = y;
    cout << "Data updated." << endl;
  }
  else
  {
    cout << "Data not found." << endl;
  }
}

void seQueue(Queue *q, int x)
{
  QNode *temp = q->front;
  bool found = false;

  while (!found)
  {
    if (temp->key == x)
    {
      found = true;
      break;
    }
    temp = temp->next;
  }

  if (found)
  {
    cout << "Found data : " << temp->key << endl;
  }
  else
  {
    cout << "Data not found." << endl;
  }
}

void display(Queue *q)
{
  QNode *temp;
  if (q->front == NULL)
  {
    cout << "Stack Underflow" << endl;
    // exit(1);
  }
  else
  {
    cout << "Data : ";
    temp = q->front;
    while (temp != NULL)
    {
      cout << "[" << temp->key << "]";
      temp = temp->next;
    }
    cout << endl;
  }
}

int main()
{
  Queue *q = createQueue();
  int data, pilih;
  while (true)
  {
    system("cls");
    display(q);

    cout << endl;
    cout << "Queue DoubleLinkedList " << endl;
    cout << "1. Enter data (enQueue)" << endl;
    cout << "2. Delete data(deQueue)" << endl;
    cout << "3. Update data" << endl;
    cout << "4. Search data" << endl;
    cout << "0. Exit program" << endl;
    cout << "Menu : ";
    cin >> pilih;

    switch (pilih)
    {
    case 1:
      cout << "Input data (int):";
      cin >> data;
      enQueue(q, data);
      break;
    case 2:
      cout << "Data deleted" << endl;
      deQueue(q);
      system("pause");
      break;
    case 3:
      cout << "Enter data key for update : ";
      cin >> data;
      upQueue(q, data);
      system("pause");
      break;
    case 4:
    cout << "Find data : ";
      cin >> data;
      seQueue(q, data);
      system("pause");
      break;
    default:
      exit(0);
      break;
    }
  }
  return 0;
}
