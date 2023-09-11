#ifndef LISTANTRIAN_H
#define LISTANTRIAN_H

#include <string.h>

#define first(A) A.first
#define info(A) A->info
#define next(A) A->next

using namespace std;

struct elementdata
{
  int queueno;
  string name;
};

struct listelement
{
  elementdata info;
  listelement *next;
};

struct listexplicit
{
  listelement *first;
};

void createempty(listexplicit &l);
bool isempty(listexplicit l);

void insertlast(listexplicit &l, listelement *inputelement);
void insertlast(listexplicit &l, elementdata info);

void deletefirst(listexplicit &l, listelement *outputelement);

listelement *findelementbefore(listexplicit &l, int queueno);
// fungsi findelementbefore mengembalikan elemen terakhirsebelum
// elemen dengan nomor antrian queueno. apabila tidakditemukan,
// maka fungsi mengembalikan NULL
void deleteafter(listelement *prec, listelement *p);

#endif // LISTANTRIAN_H