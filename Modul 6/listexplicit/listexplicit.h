#ifndef LISTEXPLICIT_H_INCLUDED
#define LISTEXPLICIT_H_INCLUDED

struct listelement
{
  int info;
  listelement *next;
};

struct listexplicit
{
  listelement *first;
};

void createempty(listexplicit &l);
void insertfirst(listexplicit &l, listelement *inputelement);
void insertfirst(listexplicit &l, int inputinteger);

#endif // LISTEXPLICIT_H_INCLUDED