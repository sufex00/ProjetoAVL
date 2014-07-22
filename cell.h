#ifndef CELLL_H
#define CELLL_H
#include<QString>

class cell
{
    /* * * * * * * * * * * * * * * * *
    *
    * MEMBROS DA CLASSE
    *
    * * * * * * * * * * * * * * * * */

    int size;    //tamanho da cell
    int element;//elemento da cell
    int balanceFator;//fator de balanceamento

public:

    cell* left;  //Aponta para o filho a esquerda
    cell* right; //Aponta para o filho a direita
    /* * * * * * * * * * * * * * * * *
    *
    * CONSTRUTOR
    *
    * * * * * * * * * * * * * * * * */
    cell();
    cell(int element, cell* left, cell* right);//construtor de nós que não e folha
    cell(int element); //construtor das folhas

    /* * * * * * * * * * * * * * * * *
    *
    * MÉTODOS DA CELL
    *
    * * * * * * * * * * * * * * * * */

    //modefica o conteudo da celula
    void setElement(int element);

    //Retorna tamanho da Arvore
    int getSize();

    //Retorna elemento que pertence a folha
    int getElement();

    void setSize(int size);

};

#endif // CELLL_H
