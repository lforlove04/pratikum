#ifndef LISTEXPLICIT_H_INCLUDED
#define LISTEXPLICIT_H_INCLUDED

using namespace std;

struct infoType
{
  int ID;
  string name;
};

struct listelement
{
  infoType info;
  listelement *next;
};

struct listexplicit
{
  listelement *first;
};

void createempty(listexplicit &l);
void insertfirst(listexplicit &l, listelement *inputelement);
void insertfirst(listexplicit &l, int ID, string name);

#endif // LISTEXPLICIT_H_INCLUDED