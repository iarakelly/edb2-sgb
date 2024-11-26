#ifndef NO_H
#define NO_H
#include "livro.h"

typedef struct No //estrutura dos nós da árvore 
{
    Livro livro; // armazena um livro
    struct No *E; // ponteiro para um Nó que é a subárvore esquerda
    struct No *D; // ponteiro para um Nó que é a subárvore direita
}No;

No *criar_no(Livro livro); //para fazer a função de inserir um livro precisamos criar um nó que irá armazenar o livro.


#endif