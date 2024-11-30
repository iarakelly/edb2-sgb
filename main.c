#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "arvore.h"

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
        getchar(); // limpa o buffer de entrada
            
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