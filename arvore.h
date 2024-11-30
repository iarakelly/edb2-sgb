#ifndef ARVORE_H
#define ARVORE_H
#include "no.h"


No *inicializar_arvore();
void inserir_livro(No** raiz, Livro livro);
void buscar_por_genero(No* raiz, char genero[]) ;
int e_vazia(No *a);
void liberar_arvore(No* raiz);
void carregar_livros(char* biblioteca, No** raiz);
void exibir_arvore(No* raiz);

#endif