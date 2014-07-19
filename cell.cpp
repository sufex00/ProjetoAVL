#include"cell.h"

cell::cell()
{

}
cell::cell(int size, cell* left, cell* right)
{
    {
        this->size=size;
        leaf=false;
        this->left=left;
        this->right=right;
    }
}
cell::cell(char element, int size)
{
    this->size=size;
    this->element=element;
    leaf=true;
}

int cell::getSize()
{
    return this->size;
}
char cell::getElement()
{
    if(this->leaf)
    {
        return this->element;

    }
    else
    {
        return ' ';
    }
}

void cell::setSize(int size)
{
    this->size=size;
}


