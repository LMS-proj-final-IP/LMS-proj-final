#include <stdio.h>    // Para printf, scanf, FILE, fopen, fclose, fscanf, fprintf
#include <stdlib.h>   // Para malloc, free, exit
#include <string.h>   // Para strcmp, strcpy, strlen
#include "Livro.h"

void inicializarLivro(Livro *livro, const char *titulo, const char *autor, const char *ISBN, const char *genero) {
    strcpy(livro->titulo, titulo);
    strcpy(livro->autor, autor);
    strcpy(livro->ISBN, ISBN);
    strcpy(livro->genero, genero);
    livro->emprestado = 0;
}

void emprestarLivro(Livro *livro) {
    livro->emprestado = 1;
}

void devolverLivro(Livro *livro) {
    livro->emprestado = 0;
}

void exibirDetalhes(const Livro *livro) {
    printf("\nTítulo: %s\nAutor: %s\nISBN: %s\nGénero: %s\nStatus: %s\n", 
        livro->titulo, livro->autor, livro->ISBN, livro->genero, 
        livro->emprestado ? "Emprestado" : "Disponível");
}
