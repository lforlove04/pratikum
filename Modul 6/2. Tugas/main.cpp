#include <iostream>
#include "listexplicit.h"
#include "listexplicit.cpp"

using namespace std;

void printseluruhisilist(listexplicit l)
{
  // tampilkan data buku di dalam stack
  cout << "Isi list: " << endl;
  listelement *currentelement = l.first;
  while (currentelement != NULL)
  {
    cout << " [" << currentelement->info.ID << " " << currentelement->info.name << "]" << endl;
    currentelement = currentelement->next;
  }
  cout << endl;
}

void cariData(listexplicit &l)
{
  cout << "Masukkan ID : ";
  int n;
  cin >> n;

  findData(l, n);
}

void masukkandatasebagaielemenpertamalist(listexplicit &l)
{
  cout << "Masukkan ID : ";
  int n;
  cin >> n;

  string name;
  cout << "Masukkan nama : ";
  fflush(stdin);
  getline(cin, name);

  insertfirst(l, n, name);
}

int main()
{
  listexplicit l;
  createempty(l);

  bool stop = false;

  while (!stop)
  {
    system("cls");
    printseluruhisilist(l);

    cout << "Menu: " << endl;
    cout << "1. Masukkan data sebagai elemen pertama" << endl;
    cout << "2. Cari data dengan ID" << endl;
    cout << "Selain itu: Keluar" << endl;
    cout << "Pilihan anda: ";
    char jawaban;
    cin >> jawaban;

    if (jawaban == '1')
    {
      masukkandatasebagaielemenpertamalist(l);
    }
    else if (jawaban == '2')
    {
      cariData(l);
    }

    stop = (jawaban != '1' && jawaban != '2');
  }

  return 0;
}
