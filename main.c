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
                printf("Digite os dados do livro :\n");
                printf("Digite o código:");                
                scanf("%d", &novo_livro.codigo);
                printf("Digite o título:");                
                scanf(" %99s", &novo_livro.titulo);
                printf("Digite o autor:");                
                scanf("%99s", &novo_livro.autor);
                printf("Digite o gênero:");    
                scanf("%49s", &novo_livro.genero);
                printf("Digite o ano:");  
                scanf("%d", &novo_livro.ano);
                printf("Digite a editora:");                
                scanf("%99s", &novo_livro.editora);
                printf("Digite o número de páginas:");                
                scanf("%d", &novo_livro.num_paginas);

                inserir_livro(&raiz, novo_livro);
                break;

            case 3:
                printf("Digite o gênero: ");
                fgets(genero, sizeof(genero), stdin);
                genero[strcspn(genero, "\n")] = '\0'; // Remover '\n'
                buscar_por_genero(raiz, genero);
                break;

            case 4:
                if(raiz == NULL)
                {
                    printf("No momento não há livros armazenados na biblioteca!");
                }
                else
                {
                exibir_arvore(raiz);
                }
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