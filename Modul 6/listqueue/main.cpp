#include <iostream>
#include "listqueue.h"
#include "listqueue.cpp"

using namespace std;

void printantrian(listexplicit l)
{
  // tampilkan data buku di dalam stack
  cout << "Antrian saat ini: " << endl;
  listelement *currentelement = first(l);
  while (currentelement != NULL)
  {
    elementdata data = info(currentelement);
    cout << " [" << data.queueno << " : " << data.name
         << "]" << endl;
    currentelement = next(currentelement);
  }
  cout << endl;
}

void antrianbaru(listexplicit &l, int nomorantrian)
{
  cout << "Masukkan nama : ";
  string name;
  cin >> name;

  elementdata info;
  info.queueno = nomorantrian;
  info.name = name;

  insertlast(l, info);
}

int main()
{
  int queueno = 0;
  listexplicit l;
  createempty(l);

  bool stop = false;

  while (!stop)
  {
    system("cls");
    printantrian(l);

    cout << "Menu: " << endl;
    cout << "1. Antrian baru" << endl;
    cout << "2. Pelanggan selesai dilayani" << endl;
    cout << "3. Pelanggan tidak hadir" << endl;
    cout << "4. Pelanggan tidak jadi mengantri" << endl;
    cout << "Selain itu: Keluar" << endl;
    cout << "Pilihan anda: ";
    char jawaban;
    cin >> jawaban;

    switch (jawaban)
    {
    case '1':
      queueno++;
      antrianbaru(l, queueno);
      break;
    case '2':

      break;
    case '3':

      break;
    case '4':

      break;
    default:
      stop = true;
      break;
    }
  }

  return 0;
}
