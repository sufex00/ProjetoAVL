#include"cell.h"

cell::cell()
{

}
cell::cell(int element,cell* left, cell* right)
{
    {
        this->element=element;
        this->left=left;
        this->right=right;
    }
}
cell::cell(int element)
{
    this->element=element;
    this->left=NULL;
    this->right=NULL;
}

int cell::getSize()
{
    return this->size;
}
int cell::getElement()
{
    return this->element;
}

void cell::setSize(int size)
{
    this->size=size;
}

void cell::setElement(int element)
{
    this->element=element;
}
