#ifndef TREEMANIPULATION_H
#define TREEMANIPULATION_H
#include<QList>
#include"cell.h"

class TreeManipulation
{
    /* * * * * * * * * * * * * * * * *
    *
    * MEMBROS DA CLASSE
    *
    * * * * * * * * * * * * * * * * */
    QList<cell*> sizeLevel;


public:
    TreeManipulation();
    void appEnd(cell* new_cell);
    cell *at(int position);
    int size();
};

#endif // TREEMANIPULATION_H
