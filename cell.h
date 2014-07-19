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
    char element;//elemento

public:

    cell* left;  //Aponta para o filho a esquerda
    cell* right; //Aponta para o filho a direita
    bool leaf;   //Verifica se a celula e folha

    /* * * * * * * * * * * * * * * * *
    *
    * CONSTRUTOR
    *
    * * * * * * * * * * * * * * * * */
    cell();
    cell(int size, cell* left, cell* right);//construtor de nós que não e folha
    cell(char element, int size); //construtor das folhas

    /* * * * * * * * * * * * * * * * *
    *
    * MÉTODOS DA CELL
    *
    * * * * * * * * * * * * * * * * */


    //Retorna tamanho da Arvore
    int getSize();

    //Retorna elemento que pertence a folha
    char getElement();

};

#endif // CELLL_H
