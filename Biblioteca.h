#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "Livro.h"
#include "Utilizador.h"

#define MAX_LIVROS 100
#define MAX_UTILIZADORES 100

typedef struct {
    Livro livros[MAX_LIVROS];
    Utilizador utilizadores[MAX_UTILIZADORES];
    int totalLivros;
    int totalUtilizadores;
} Biblioteca;

void inicializarBiblioteca(Biblioteca *bib);
void adicionarLivro(Biblioteca *bib);
void adicionarUtilizador(Biblioteca *bib);
void listarLivros(const Biblioteca *bib);
void listarUtilizadores(const Biblioteca *bib);
void emprestarLivro(Biblioteca *bib);
void devolverLivroBiblioteca(Biblioteca *bib);
void salvarDados(const Biblioteca *bib);
void carregarDados(Biblioteca *bib);

#endif
