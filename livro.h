#ifndef LIVRO_H
#define LIVRO_H

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


#endif