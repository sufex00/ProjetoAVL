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
    cell* root;


public:
    TreeManipulation(cell* root);
    cell* getRoot();
    void calculationLevel(cell* node, int level=0);
    int calculationBalanceFator(cell* node, int level=0);
    void buildTreeBalanceFator(cell* node);
    void insection(cell *root, cell* new_cell);
    void printTree(cell* root, int level=0);
    bool seachElement(cell *root, int number);
    void rotationLeft(cell *&node);
    void rotationRight(cell *&node);
    void balance(cell* &root);
    int isMore(int fist_num, int second_num);
    void buildAVL(cell* root);
    int isAVL(cell* node);
};

#endif // TREEMANIPULATION_H
