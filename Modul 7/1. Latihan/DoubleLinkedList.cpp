#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>

using namespace std;

int ID, y, umur;
string nama, kota;

struct Info
{
  int ID;
  int umur;
  string nama;
  string kota;
};

struct node
{
  Info info;
  struct node *LEFT, *RIGHT;
};

typedef struct node simpul;
simpul *FIRST, *LAST, *P, *Q, *cetak;

void inisialisasi()
{
  FIRST = NULL;
}

void buatsimpul(int ID, string nama, int umur, string kota)
{
  P = (simpul *)malloc(sizeof(simpul));
  if (P != NULL)
  {
    P->info.ID = ID;
    P->info.nama = nama;
    P->info.umur = umur;
    P->info.kota = kota;
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
  while (Q->info.ID != y)
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

void caridata(int y)
{
  Q = FIRST;
  bool found = false;
  while (!found)
  {
    if (Q->info.ID == y)
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
    cout << Q->info.ID << ", ";
    cout << Q->info.nama << ", ";
    cout << Q->info.umur << ", ";
    cout << Q->info.kota << "]";
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
  while (cetak != NULL)
  {
    cout << "[";
    cout << cetak->info.ID << ", ";
    cout << cetak->info.nama << ", ";
    cout << cetak->info.umur << ", ";
    cout << cetak->info.kota;
    cout << "]" << endl;

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
    cout << "3. Insert Tengah" << endl;
    cout << "4. Delete Kanan" << endl;
    cout << "5. Cari Data" << endl;
    cout << "Pilih (1-5):";
    cin >> pil;
    switch (pil)
    {
    case 1:
      cout << "Masukkan ID : ";
      cin >> ID;
      cout << "Masukkan Nama : ";
      cin >> nama;
      cout << "Masukkan Umur : ";
      cin >> umur;
      cout << "Masukkan Kota Asal : ";
      cin >> kota;

      buatsimpul(ID, nama, umur, kota);
      simpulawal();
      insertkanan();
      break;

    case 2:
      cout << "Masukkan ID : ";
      cin >> ID;
      cout << "Masukkan Nama : ";
      cin >> nama;
      cout << "Masukkan Umur : ";
      cin >> umur;
      cout << "Masukkan Kota Asal : ";
      cin >> kota;

      buatsimpul(ID, nama, umur, kota);
      simpulawal();
      insertkiri();
      break;

    case 3:
      cout << "Masukkan ID : ";
      cin >> ID;
      cout << "Masukkan Nama : ";
      cin >> nama;
      cout << "Masukkan Umur : ";
      cin >> umur;
      cout << "Masukkan Kota Asal : ";
      cin >> kota;

      buatsimpul(ID, nama, umur, kota);

      cout << "Masukkan Nilai dicari :";
      cin >> y;
      simpulawal();
      inserttengah(y);
      break;

    case 4:
      deletekanan();
      break;

    case 5:
      cout << "Masukkan Nilai dicari :";
      cin >> y;

      caridata(y);
      break;

    default:
      cout << "Salah";
    }
  } while (pil < 6);
}
