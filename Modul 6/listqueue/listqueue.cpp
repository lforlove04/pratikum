#include <iostream>
#include "listqueue.h"

void createempty(listexplicit &l)
{
  first(l) = NULL;
}

bool isempty(listexplicit l)
{
  return (first(l) == NULL);
}

void insertlast(listexplicit &l, listelement *inputelement)
{
  // kondisi awal: l bisa kosong (artinya l.first == NULL)
  // atau tidak kosong (artinya l.first
  // berisi sebuah pointer ke sebuah listelement

  if (isempty(l))
  {
    first(l) = inputelement;
  }
  else
  {
    // tahap 1: menyusuri list hingga mencapai elemen akhir dimana next berisi NULL
    listelement *curr = first(l);
    while (next(curr) != NULL)
    {
      curr = next(curr);
    }

    // tahap 2: mengubah agar next(curr) menunjuk pada inputelement
    next(curr) = inputelement;
  }
}

void insertlast(listexplicit &l, elementdata info)
{
  // membuat elemen baru
  listelement *newelement = new listelement;
  info(newelement) = info;
  next(newelement) = NULL;

  // memasukkan elemen yang telah dibuat ke dalam list
  insertlast(l, newelement);
}
