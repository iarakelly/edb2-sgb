#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "no.c"


No *inicializar_arvore() 
{
    return NULL; // árvore vazia
}

void inserir_livro(No** raiz, Livro livro) 
{
    if (*raiz == NULL) //se a árvore está vazia cria o nó e define como raiz
    {
        *raiz = criar_no(livro);
    } 
    else if (livro.codigo < (*raiz)->livro.codigo) //verifica se o código é menor que a raiz
    {
        inserir_livro(&(*raiz)->E, livro); //se for irá inserir na subárvore esquerda (recursivamente)
    } 
    else if (livro.codigo > (*raiz)->livro.codigo) //verifica se o código é maior que a raiz
    {
        inserir_livro(&(*raiz)->D, livro); //se for irá inserir na subárvore direita (recursivamente)
    } 
    else 
    {
        printf("Código já existente! Livro não inserido.\n");
    }
}

void buscar_por_genero(No* raiz, char genero[]) 
{
    if (raiz != NULL)  //verifica se não é uma árvore é vazia, não podemos tentar acessar um NULL rsrs
    {
        buscar_por_genero(raiz->E, genero); //busca primeiro na subárvore esqueda

        if (strcmp(raiz->livro.genero, genero) == 0)  //strcmp é usada para comparar duas strings, se as strings forem iguais ela vai retornar 0
        {
            printf("Código: %d, Título: %s, Autor: %s, Gênero: %s, Ano: %d, Editora: %s, Páginas: %d\n",
                   raiz->livro.codigo, raiz->livro.titulo, raiz->livro.autor, raiz->livro.genero,
                   raiz->livro.ano, raiz->livro.editora, raiz->livro.num_paginas);
        }

        buscar_por_genero(raiz->D, genero);

        //estamos realizando a busca em ordem que é: busca na SAE, trata a raiz, busca na SAD. é indicada para bsb
    }
}

int e_vazia(No *a)
{
    return a == NULL; //Se a for vazia retorna 1, se não retorna 0;
}

void liberar_arvore(No* raiz) 
{
    if (!e_vazia(raiz)) {
        liberar_arvore(raiz->E);
        liberar_arvore(raiz->D);
        free(raiz);
    }
}
void carregar_livros(char* biblioteca, No** raiz) 
{
    FILE* arquivo = fopen(biblioteca, "r"); //abre o arquivo no modo leitura (r)

    if (!arquivo) // caso não consiga abrir o arquivo
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    char linha[256]; //buffer para armazenar as linhas

    while (fgets(linha, sizeof(linha), arquivo))// a função fgets lê cada linha do arquivo ate encontrar um \n ou atingir o tamanho da linha
    {
        Livro livro; //cria uma instância de livro
        sscanf(linha, "%d,%99[^,],%99[^,],%49[^,],%d,%99[^,],%d", // atribui os dados a instância dele
               &livro.codigo, livro.titulo, livro.autor, livro.genero, /*para os inteiros (tipos primitivos) só conseguimos mudar com o scanf com o endereço as strings também mas como estamos declarando um vetor de char já estamos tratando de endereços de memória, por isso não usamos &*/
               &livro.ano, livro.editora, &livro.num_paginas);
        inserir_livro(raiz, livro); //insere o livro na árvore
    }//esse while fica executando enquanto tiver linha para ler

    fclose(arquivo); // fecha o arquivo
}

void exibir_arvore(No* raiz) 
{
    if (!e_vazia(raiz)) 
    {
        exibir_arvore(raiz->E);
        printf("Código: %d, Título: %s, Autor: %s, Gênero: %s, Ano: %d, Editora: %s, Páginas: %d\n",
               raiz->livro.codigo, raiz->livro.titulo, raiz->livro.autor, raiz->livro.genero,
               raiz->livro.ano, raiz->livro.editora, raiz->livro.num_paginas);
        exibir_arvore(raiz->D);
    }
}