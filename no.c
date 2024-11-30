#include "no.h"
#include <stdlib.h>
#include <stdio.h>

No *criar_no(Livro livro) //para fazer a função de inserir um livro precisamos criar um nó que irá armazenar o livro.
{   // e só então inserir o nó na árvore

    No* novo_no = (No*)malloc(sizeof(No)); //aloca memória para o novo nó

    if (novo_no == NULL) 
    {
        printf("Erro: falha na alocação de memória.\n");
        return NULL;
    }

    novo_no->livro = livro;
    novo_no->E = NULL; // inicialmente o nó não tem subárvores
    novo_no->D = NULL; // inicialmente o nó não tem subárvores
    return novo_no; //retorna o nó criado
}