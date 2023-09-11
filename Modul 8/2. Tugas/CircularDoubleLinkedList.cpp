#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>

using namespace std;

struct Buku
{
  int NO;
  string judul;
  string penulis;
  float harga;
};

int x, y;
float h;
string p, jud;
int j = 0;

struct node
{
  Buku info;
  struct node *LEFT, *RIGHT;
};

typedef struct node simpul;
simpul *FIRST, *LAST, *P, *Q, *cetak;

void inisialisasi()
{
  FIRST = NULL;
}

void buatsimpul(int x, string jud, string p, float h)
{
  P = (simpul *)malloc(sizeof(simpul));
  if (P != NULL)
  {
    P->info.NO = x;
    P->info.judul = jud;
    P->info.penulis = p;
    P->info.harga = h;
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
    P->RIGHT = P;
    P->LEFT = P;
    j++;
  }
}

void insertkanan()
{
  if (LAST != NULL)
  {
    LAST->RIGHT = P;
    LAST = P;
    LAST->RIGHT = FIRST;
    FIRST->LEFT = LAST;
    j++;
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
    FIRST = P;
    FIRST->LEFT = LAST;
    LAST->RIGHT = FIRST;
    j++;
  }
  else
  {
    cout << "Isinya Kosong";
  }
}

void insertAfter(int y)
{
  Q = FIRST;
  while (Q->info.NO != y)
  {
    Q = Q->RIGHT;
  }
  if (Q == LAST)
  {
    LAST->RIGHT = P;
    P->LEFT = LAST;
    LAST = P;
    P->RIGHT = NULL;
    j++;
  }
  else
  {
    P->RIGHT = Q->RIGHT;
    P->LEFT = Q->RIGHT;
    Q->RIGHT->LEFT = P;
    Q->RIGHT = P;
    j++;
  }
}

void insertBefore(int y)
{
  Q = FIRST;
  while (Q->info.NO != y)
  {
    Q = Q->RIGHT;
  }

  if (Q == FIRST)
  {
    P->LEFT = LAST;
    P->RIGHT = Q;
    FIRST = P;
  }
  else
  {
    P->RIGHT = Q;
    P->LEFT = Q->LEFT;
    Q->LEFT = P;
  }
  j++;
}

void deletekanan()
{
  LAST = LAST->LEFT;
  free(LAST->RIGHT);
  LAST->RIGHT = FIRST;
  FIRST->LEFT = LAST;
  j--;
}

void deletekiri()
{
  FIRST = FIRST->RIGHT;
  free(FIRST->LEFT);
  FIRST->LEFT = LAST;
  LAST->RIGHT = FIRST;
  j--;
}

void deletetengah(int y)
{
  Q = FIRST;
  while (Q->info.NO != y)
  {
    Q = Q->RIGHT;
  }
  Q->RIGHT = Q->RIGHT->RIGHT;
  free(Q->RIGHT->LEFT);
  Q->RIGHT->LEFT = Q;
  j--;
}

void updatedata(int y)
{
  Q = FIRST;
  bool found = false;
  while (!found)
  {
    if (Q->info.NO == y)
    {
      found = true;
    }
    else
    {
      Q = Q->RIGHT;
    }
  }

  if (found)
  {
    cout << "Found : [";
    cout << Q->info.NO << ", ";
    cout << Q->info.judul << ", ";
    cout << Q->info.penulis << ", ";
    cout << Q->info.harga << "]";
    cout << endl;

    cout << "Update data : " << endl;
    cout << "Judul : ";
    cin >> Q->info.judul;

    cout << "Penulis : ";
    cin >> Q->info.penulis;

    cout << "Harga : ";
    cin >> Q->info.harga;

    cout << endl
         << "Data Updated" << endl;
  }
  else
  {
    cout << "Not found.";
  }

  system("pause");
}

void searchdata(int y)
{
  Q = FIRST;
  bool found = false;
  while (!found)
  {
    if (Q->info.NO == y)
    {
      found = true;
    }
    else
    {
      Q = Q->RIGHT;
    }
  }

  if (found)
  {
    cout << "Found : [";
    cout << Q->info.NO << ", ";
    cout << Q->info.judul << ", ";
    cout << Q->info.penulis << ", ";
    cout << Q->info.harga << "]";
    cout << endl;
  }
  else
  {
    cout << "Not found.";
  }

  system("pause");
}

void tampil()
{
  cetak = FIRST;
  for (int k = 0; k < j - 1; k++)
  {
    cout << "[";
    cout << cetak->info.NO << ", ";
    cout << cetak->info.judul << ", ";
    cout << cetak->info.penulis << ", ";
    cout << cetak->info.harga << "]";
    cout << endl;
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
    tampil();
    cout << endl
         << endl
         << "1. Insert Kanan" << endl;
    cout << "2. Insert Kiri" << endl;
    cout << "3. Insert After" << endl;
    cout << "4. Insert Before" << endl;
    cout << "5. Delete Kanan" << endl;
    cout << "6. Delete Kiri" << endl;
    cout << "7. Delete Tengah" << endl;
    cout << "8. Update Data" << endl;
    cout << "9. Search Data" << endl;

    cout << "Pilih (1-7): ";
    cin >> pil;
    switch (pil)
    {
    case 1:
      cout << "Masukkan NO : ";
      cin >> x;

      cout << "Masukkan Judul : ";
      cin >> jud;

      cout << "Masukkan Penulis : ";
      cin >> p;

      cout << "Masukkan Harga : ";
      cin >> h;
      buatsimpul(x, jud, p, h);

      simpulawal();
      insertkanan();
      break;

    case 2:
      cout << "Masukkan NO : ";
      cin >> x;

      cout << "Masukkan Judul : ";
      cin >> jud;

      cout << "Masukkan Penulis : ";
      cin >> p;

      cout << "Masukkan Harga : ";
      cin >> h;
      buatsimpul(x, jud, p, h);
      
      simpulawal();
      insertkiri();
      break;

    case 3:
      cout << "Masukkan NO : ";
      cin >> x;

      cout << "Masukkan Judul : ";
      cin >> jud;

      cout << "Masukkan Penulis : ";
      cin >> p;

      cout << "Masukkan Harga : ";
      cin >> h;
      buatsimpul(x, jud, p, h);
      
      cout << "Masukkan Nilai dicari :";
      cin >> y;
      simpulawal();
      insertAfter(y);
      break;

    case 4:
      cout << "Masukkan NO : ";
      cin >> x;

      cout << "Masukkan Judul : ";
      cin >> jud;

      cout << "Masukkan Penulis : ";
      cin >> p;

      cout << "Masukkan Harga : ";
      cin >> h;
      buatsimpul(x, jud, p, h);
      
      cout << "Masukkan Nilai dicari :";
      cin >> y;
      simpulawal();
      insertBefore(y);
      break;

    case 5:
      deletekanan();
      break;

    case 6:
      deletekiri();
      break;

    case 7:
      cout << "Cari Nilai Tertentu : ";
      cin >> y;
      deletetengah(y);
      break;

    case 8:
      cout << "Cari Nilai Tertentu : ";
      cin >> y;
      updatedata(y);
      break;

    case 9:
      cout << "Cari Nilai Tertentu : ";
      cin >> y;
      searchdata(y);
      break;

    default:
      cout << "Salah";
    }
  } while (pil < 10);
}
