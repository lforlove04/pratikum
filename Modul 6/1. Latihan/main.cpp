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

void masukkandatasebagaielemenpertamalist(listexplicit &l)
{
  cout << "Masukkan angka : ";
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
    cout << "Selain itu: Keluar" << endl;
    cout << "Pilihan anda: ";
    char jawaban;
    cin >> jawaban;

    if (jawaban == '1')
    {
      masukkandatasebagaielemenpertamalist(l);
    }

    stop = (jawaban != '1');
  }

  return 0;
}
