#include <iostream>
#include "listexplicit.h"

void createempty(listexplicit &l)
{
  l.first = NULL;
}

void insertfirst(listexplicit &l, listelement *inputelement)
{
  // kondisi awal: l bisa kosong (artinya l.first == NULL)
  // atau tidak kosong (artinya l.first
  // berisi sebuah pointer ke sebuah listelement

  // tahap 1: memindahkan seluruh isi list sebagai elemen sesudah input
  inputelement->next = l.first;

  // tahap 2: mengubah agar l.first menunjuk pada input
  l.first = inputelement;
}

void insertfirst(listexplicit &l, int ID, string name)
{
  // membuat elemen baru dengan parameter input sebagai isi field info
  listelement *le = new listelement;
  le->info.ID = ID;
  le->info.name = name;
  le->next = NULL;

  // memasukkan elemen yang telah dibuat ke dalam list
  insertfirst(l, le);
}

void findData(listexplicit &l, int ID)
{
  listelement *helper = l.first;
  bool found = false;
  string name = "";

  do
  {
    if (helper->info.ID == ID)
    {
      found = true;
      name = helper->info.name;
    }
    helper = helper->next;
  } while (!found && helper->next != NULL);

  if (found)
  {
    cout << "found " << name << endl;
  }
  else
  {
    cout << "not found" << endl;
  }
  system("pause");
}