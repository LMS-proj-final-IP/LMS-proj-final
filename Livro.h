#ifndef LIVRO_H
#define LIVRO_H

#define MAX_TITULO 100
#define MAX_AUTOR 100
#define MAX_ISBN 20
#define MAX_GENERO 50

typedef struct {
    char titulo[MAX_TITULO];
    char autor[MAX_AUTOR];
    char ISBN[MAX_ISBN];
    char genero[MAX_GENERO];
    int emprestado;
} Livro;

void inicializarLivro(Livro *livro, const char *titulo, const char *autor, const char *ISBN, const char *genero);
void emprestarLivro(Livro *livro);
void devolverLivro(Livro *livro);
void exibirDetalhes(const Livro *livro);

#endif
