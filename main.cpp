#include <QDebug>
#include"cell.h"
#include"treemanipulation.h"

int main()
{
    cell* root=new cell(4);
    TreeManipulation tree=TreeManipulation(root);
    tree.insection(tree.getRoot(),new cell(2));
    tree.insection(tree.getRoot(),new cell(6));
    tree.insection(tree.getRoot(),new cell(1));
    tree.insection(tree.getRoot(),new cell(3));
    tree.insection(tree.getRoot(),new cell(5));
    tree.insection(tree.getRoot(),new cell(7));
    tree.insection(tree.getRoot(),new cell(15));
    tree.insection(tree.getRoot(),new cell(14));
    tree.insection(tree.getRoot(),new cell(13));

    while(tree.isAVL(tree.getRoot())!=0)
    {
        tree.buildAVL(tree.getRoot());
    }

    tree.insection(tree.getRoot(),new cell(80));
    tree.insection(tree.getRoot(),new cell(8));
    root=tree.getRoot();
    tree.remove(root,new cell(4));
    while(tree.isAVL(tree.getRoot())!=0)
    {
        tree.buildAVL(tree.getRoot());
    }
    tree.printTree(tree.getRoot());
}
