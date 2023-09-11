#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>

using namespace std;

int x, y;

typedef struct node
{
  int info;
  struct node *LEFT, *RIGHT;
};

typedef struct node simpul;
simpul *FIRST, *LAST, *P, *Q, *cetak;

void inisialisasi()
{
  FIRST = NULL;
}
void buatsimpul(int x)
{
  P = (simpul *)malloc(sizeof(simpul));
  if (P != NULL)
  {
    P->info = x;
  }
  else
  {
    cout << "Gagal";
  }
}

void simpulawal()
{
  if (FIRST == NULL)
  {
    FIRST = P;
    LAST = P;
    LAST->RIGHT = NULL;
    LAST->LEFT = NULL;
  }
}

void insertkanan()
{
  if (LAST != NULL)
  {
    LAST->RIGHT = P;
    P->LEFT = LAST;
    LAST = P;
    P->RIGHT = NULL;
  }
  else
  {
    cout << "Isinya Kosong";
  }
}

void insertkiri()
{
  if (FIRST != NULL)
  {
    P->RIGHT = FIRST;
    FIRST->LEFT = P;
    FIRST = P;
    P->LEFT = NULL;
  }
  else
  {
    cout << "Isinya Kosong";
  }
}

void inserttengah(int y)
{
  Q = FIRST;
  while (Q->info != y)
  {
    Q = Q->RIGHT;
  }
  if (Q == LAST)
  {
    LAST->RIGHT = P;
    P->LEFT = LAST;
    LAST = P;
    P->RIGHT = NULL;
  }
  else
  {
    P->RIGHT = Q->RIGHT;
    P->LEFT = Q->RIGHT;
    Q->RIGHT->LEFT = P;
    Q->RIGHT = P;
  }
}

void deletekanan()
{
  if (FIRST == LAST)
  {
    FIRST = NULL;
    LAST = NULL;
  }
  else
  {
    LAST = LAST->LEFT;
    free(LAST->RIGHT);
    LAST->RIGHT = NULL;
  }
}

void tampil()
{
  cetak = FIRST;
  while (cetak != NULL)
  {
    cout << cetak->info << " ";
    cetak = cetak->RIGHT;
  }
}

int main()
{
  int pil;
  inisialisasi();
  do
  {
    system("cls");
    cout << endl
         << endl
         << "1. Insert Kanan" << endl;
    cout << "2. Insert Kiri" << endl;
    cout << "3. Insert Tengah" << endl;
    cout << "4. delete kanan" << endl;
    cout << "5. Tampil" << endl;
    cout << "Pilih (1-3):";
    cin >> pil;
    switch (pil)
    {
    case 1:
      cout << "Masukkan Nilai :";
      cin >> x;
      buatsimpul(x);
      simpulawal();
      insertkanan();
      break;
    case 2:
      cout << "Masukkan Nilai :";
      cin >> x;
      buatsimpul(x);
      simpulawal();
      insertkiri();
      break;
    case 3:
      cout << "Masukkan Nilai :";
      cin >> x;
      buatsimpul(x);
      cout << "Masukkan Nilai dicari :";
      cin >> y;
      simpulawal();
      inserttengah(y);
      break;
    case 4:
      deletekanan();
      break;
    case 5:
      tampil();
      break;
    default:
      cout << "Salah";
    }
  } while (pil < 6);
}
