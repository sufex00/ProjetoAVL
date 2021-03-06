#include "treemanipulation.h"

#include<QDebug>
#include <iostream>
using namespace std;
TreeManipulation::TreeManipulation(cell *root)
{
    this->root=root;
}



int TreeManipulation::calculationBalanceFator(cell *node, int level)
{
    int intReturn=0;
    int intReturnLeft=0;
    int intReturnRight=0;
    if(node->left!=NULL)
    {
        intReturnLeft=calculationBalanceFator(node->left, level +1);
    }
    else
    {
        intReturnLeft=level;
    }
    if(node->right!=NULL)
    {
        intReturnRight=calculationBalanceFator(node->right,level+1);
    }
    else
    {
        intReturnRight=level;
    }
    if(level==0)
    {
        intReturn=intReturnRight-intReturnLeft;
        node->setSize(intReturn);
    }
    else
    {
        intReturn=this->isMore(intReturnRight,intReturnLeft);
    }
    return intReturn;

}

void TreeManipulation::buildTreeBalanceFator(cell* node )
{
    if(node->left!= NULL)
    {
        this->calculationBalanceFator(node->left);
        this->buildTreeBalanceFator(node->left);
    }
    this->calculationBalanceFator(node);
    if(node->right!= NULL)
    {
        this->calculationBalanceFator(node->right);
        this->buildTreeBalanceFator(node->right);
    }
}

int TreeManipulation::isMore(int fist_num, int second_num)
{
    int more=fist_num;
    if(fist_num<second_num)
    {
        more=second_num;
    }
    return more;
}

void TreeManipulation::insection(cell* root, cell *new_cell)
{
      if(new_cell->getElement()>root->getElement())
      {
          if(root->right==NULL)
          {
              root->right=new_cell;
              this->buildAVL(this->root);
          }
          else
          {

              insection(root->right,new_cell);
          }
      }

      this->buildTreeBalanceFator(root);
      if(new_cell->getElement()<root->getElement())
      {
          if(root->left==NULL)
          {
              root->left=new_cell;
              this->buildAVL(this->root);
          }
          else
          {
              insection(root->left,new_cell);
          }
      }

}

void TreeManipulation::printTree(cell* node , int level )
{
    if(node->left!= NULL)
    {
        printTree(node->left, level +1);
    }
    cout << qPrintable(QString("\t").repeated(level)) <<"element="<< node->getElement()<< "(" <<node->getSize()<<")"<<endl;
    if(node->right!= NULL)
    {
        printTree(node->right,level +1);
    }
}

bool TreeManipulation::seachElement(cell* root,int number)
{
    bool boolReturn;
    if(root!=NULL)
    {
        if(number==root->getElement())
        {
            boolReturn=true;
        }
        else
        {
            if(number>root->getElement())
            {
                boolReturn=seachElement(root->right,number);
            }
            if(number<root->getElement())
            {
                boolReturn=seachElement(root->left,number);
            }
        }
    }
    else
    {
        boolReturn=false;
    }
    return boolReturn;
}

void TreeManipulation::rotationLeft(cell* & node)
{
    cell* aux;
    if(node->getSize()>=1 )
    {
        aux=node->right;
        node->right=aux->left;
        aux->left=node;
        if(node==root)
        {
            root=aux;
        }
        node=aux;
    }
    this->buildTreeBalanceFator(root);
}

void TreeManipulation::rotationRight(cell* & node)
{
    cell* aux;
    if(node->getSize()<=-1 )
    {
        aux=node->left;
        node->left=aux->right;
        aux->right=node;
        if(node==root)
        {
            root=aux;
        }
        node=aux;
    }
    this->buildTreeBalanceFator(root);
}

void TreeManipulation::balance(cell *&root)
{
    if(root->getSize()>=2||root->getSize()<=-2)
    {
        if(root->right!=NULL)
        {
            if(root->getSize()>=2 && root->right->getSize()==-1)
            {
                this->rotationRight(root->right);
                this->rotationLeft(root);
            }
            if(root->getSize()>=2 && root->right->getSize()>=0)
            {
                this->rotationLeft(root);
            }
        }
    }
    if(root->left!=NULL)
    {
        if(root->getSize()>=-2 && root->left->getSize()==1)
        {
            this->rotationLeft(root->left);
            this->rotationRight(root);
        }
        if(root->getSize()<=-2 && root->left->getSize()<=0)
        {
            this->rotationRight(root);
        }
    }

}

void TreeManipulation::buildAVL(cell *root)
{
    this->balance(root);
    if(root->left!= NULL)
    {
        this->balance(root->left);
        this->buildAVL(root->left);
    }
    if(root->right!= NULL)
    {
        this->balance(root->right);
        this->buildAVL(root->right);
    }
}

cell* TreeManipulation::getRoot()
{
    return this->root;
}

int TreeManipulation::isAVL(cell *node)
{
    int boolReturnLeft=0;
    int boolReturnRight=0;
    if(node->left!= NULL)
    {
        if(abs(node->left->getSize())>=2)
        {
            boolReturnLeft=1;
        }
        else
        {
            this->isAVL(node->left);
        }
    }
    else
    {
        boolReturnLeft=0;
    }
    if(node->right!= NULL)
    {
        if(abs(node->right->getSize())>=2)
        {
            boolReturnRight=1;
        }
        else
        {
            this->isAVL(node->right);
        }
    }
    else
    {
        boolReturnRight=0;
    }
    return boolReturnLeft+boolReturnRight;
}

void TreeManipulation::remove(cell *&root, cell *old_cell)
{
   if(root->getElement()<old_cell->getElement())
   {
       if(root->right!=NULL)
       {
           remove(root->right,old_cell);
       }
   }
   if(root->getElement()>old_cell->getElement())
   {
       if(root->left!=NULL)
       {
           remove(root->left,old_cell);
       }
   }
   if(root->getElement()==old_cell->getElement())
   {
       if(root->right==NULL && root->left==NULL)
       {
           root=NULL;
       }
       else
       {
           if(root->right==NULL)
           {
               root=root->left;
           }
           else
           {
               if(root->left==NULL)
               {
                   root=root->right;
               }
           }
           if(root->right!=NULL && root->left!=NULL)
           {
               cell *temp=root;
               while(temp->right->right!=NULL)
               {
                   temp=temp->right;
               }
               root->setElement(temp->right->getElement());
               temp->right=NULL;

           }
       }
       this->buildTreeBalanceFator(this->root);

   }

}
