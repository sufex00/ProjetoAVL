#include <QDebug>
#include"cell.h"
#include"treemanipulation.h"

int main()
{
    cell* root=new cell(30);
    TreeManipulation tree=TreeManipulation(root);
    tree.insection(tree.getRoot(),new cell(20));
    tree.insection(tree.getRoot(),new cell(9));
    tree.insection(tree.getRoot(),new cell(10));
    tree.insection(tree.getRoot(),new cell(5));
    tree.insection(tree.getRoot(),new cell(50));
    tree.insection(tree.getRoot(),new cell(60));
    tree.insection(tree.getRoot(),new cell(21));
    tree.buildTreeBalanceFator(tree.getRoot());
    tree.buildAVL(root);
    tree.printTree(tree.getRoot());
}
