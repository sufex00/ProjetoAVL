#include "treemanipulation.h"

TreeManipulation::TreeManipulation()
{
}

void TreeManipulation::appEnd(cell *new_cell)
{
    sizeLevel.append(new_cell);
}

cell* TreeManipulation::at(int position)
{
    return sizeLevel.at(position);
}

int TreeManipulation::size()
{
    return sizeLevel.size();
}

void TreeManipulation::calculationLevel(cell *node, int level)
{
    if(node->leaf != true)
    {
        printTree(node->left, level +1);
        cout << qPrintable(QString("\t").repeated(level)) << node->getSize() <<endl;
        printTree(node->right,level +1);
    }
    if(node->leaf)
    {
        cout << qPrintable(QString("\t").repeated(level)) <<"element="<< node->getElement()<<"e="<<(int) node->getElement() + 128 <<endl;
    }
}
