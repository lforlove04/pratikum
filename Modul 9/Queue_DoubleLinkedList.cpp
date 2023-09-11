#include <bits/stdc++.h>
using namespace std;

class QNode
{
public:
  int key;
  QNode *next;
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

  q->rear->next = temp;
  q->rear = temp;
}

QNode *deQueue(Queue *q)
{
  if (q->front == NULL)
    return NULL;

  QNode *temp = q->front;
  q->front = q->front->next;

  if (q->front == NULL)
    q->rear = NULL;
  return temp;
}

void display(Queue *q)
{
  QNode *temp;
  if (q->front == NULL)
  {
    cout << "Stack Underflow" << endl;
    exit(1);
  }
  else
  {
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
    cout << "Menu untuk program queue dengan doublelinkedlist " << endl;
    cout << "1 untuk memasukkan data(enQueue)" << endl;
    cout << "2 untuk mengeluarkan data(deQueue)" << endl;
    cout << "3 untuk menampilkan semua data(display)" << endl;
    cout << "0 untuk keluar program" << endl;
    cin >> pilih;

    switch (pilih)
    {
    case 1:
      cout << "Masukkan data (int):";
      cin >> data;
      enQueue(q, data);
      break;
    case 2:
      cout << "Data dikeluarkan" << endl;
      deQueue(q);
      break;
    case 3:
      cout << "Data:" << endl;
      display(q);
      break;
    default:
      exit(0);
      break;
    }
    display(q);
  }
  return 0;
}
