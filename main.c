#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "arvore.h"

/*----------------------------------Início do comentário--------------------------------------------
typedef struct Livro //estrutura para armazenar as informações dos livros
{
    int codigo;
    int ano;
    int num_paginas;
    char titulo[100];
    char autor[100];
    char genero[50];
    char editora[100];
}Livro;



typedef struct No //estrutura dos nós da árvore 
{
    Livro livro; // armazena um livro
    struct No *E; // ponteiro para um Nó que é a subárvore esquerda
    struct No *D; // ponteiro para um Nó que é a subárvore direita
}No;



No *inicializar_arvore() 
{
    return NULL; // árvore vazia
}

No* criar_no(Livro livro) //para fazer a função de inserir um livro precisamos criar um nó que irá armazenar o livro.
{   // e só então inserir o nó na árvore
    No* novo_no = (No*)malloc(sizeof(No)); //aloca memória para o novo nó
    novo_no->livro = livro;
    novo_no->E = NULL; // inicialmente o nó não tem subárvores
    novo_no->D = NULL; // inicialmente o nó não tem subárvores
    return novo_no; //retorna o nó criado
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
*/

/*
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
               &livro.codigo, livro.titulo, livro.autor, livro.genero, //para os inteiros (tipos primitivos) só conseguimos mudar com o scanf com o endereço as strings também mas como estamos declarando um vetor de char já estamos tratando de endereços de memória, por isso não usamos &
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
*/
void menu()
{
    printf("\n--- Sistema de Gerenciamento de Biblioteca ---\n");
    printf("1. Carregar livros de arquivo CSV\n");
    printf("2. Inserir novo livro\n");
    printf("3. Buscar livros por gênero\n");
    printf("4. Exibir todos os livros\n");
    printf("5. Sair\n");
    printf("Escolha uma opção: ");   
}
int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8"); 

    No* raiz = inicializar_arvore(); //inicializa a árvore 
    int opc = 0;
    char genero[50], nome_arquivo[100];
    Livro novo_livro; //instância um livro a ser adicionado

    while(opc != 6)
    {
        menu();
        scanf("%d", &opc);
        getchar(); // limpa buffer de entrada
            
         switch (opc) 
         {
            case 1:
                printf("Digite o nome do arquivo CSV: ");
                fgets(nome_arquivo, sizeof(nome_arquivo), stdin);
                nome_arquivo[strcspn(nome_arquivo, "\n")] = '\0'; // Remover '\n'
                carregar_livros(nome_arquivo, &raiz);
                break;

            case 2:
                printf("Digite os dados do livro (código, título, autor, gênero, ano, editora, páginas):\n");
                scanf("%d%99s%99s%49s%d%99s%d",
                      &novo_livro.codigo, novo_livro.titulo, novo_livro.autor,
                      novo_livro.genero, &novo_livro.ano, novo_livro.editora,
                      &novo_livro.num_paginas);
                inserir_livro(&raiz, novo_livro);
                break;

            case 3:
                printf("Digite o gênero: ");
                fgets(genero, sizeof(genero), stdin);
                genero[strcspn(genero, "\n")] = '\0'; // Remover '\n'
                buscar_por_genero(raiz, genero);
                break;

            case 4:
                exibir_arvore(raiz);
                break;
            case 5:
                opc = 6;
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    }

    printf("Saindo...\n");
    liberar_arvore(raiz);
    return 0;
}