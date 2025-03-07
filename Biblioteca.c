#include "Biblioteca.h"
#include <stdlib.h>

void inicializarBiblioteca(Biblioteca *bib) {
    bib->totalLivros = 0;
    bib->totalUtilizadores = 0;
    carregarDados(bib);
}

void adicionarLivro(Biblioteca *bib) {
    if (bib->totalLivros >= MAX_LIVROS) {
        printf("\nA biblioteca está cheia!\n");
        return;
    }

    char titulo[MAX_TITULO], autor[MAX_AUTOR], ISBN[MAX_ISBN], genero[MAX_GENERO];
    printf("\nEscreva o título: ");
    scanf(" %[^\n]", titulo);
    printf("Escreva o autor: ");
    scanf(" %[^\n]", autor);
    printf("Escreva o ISBN: ");
    scanf(" %[^\n]", ISBN);
    printf("Escreva o género: ");
    scanf(" %[^\n]", genero);

    inicializarLivro(&bib->livros[bib->totalLivros], titulo, autor, ISBN, genero);
    bib->totalLivros++;

    printf("\nLivro adicionado com sucesso!\n");
    salvarDados(bib);
}

void adicionarUtilizador(Biblioteca *bib) {
    if (bib->totalUtilizadores >= MAX_UTILIZADORES) {
        printf("\nO limite de utilizadores foi atingido!\n");
        return;
    }

    char nome[MAX_NOME], id[MAX_ID];
    printf("\nEscreva o nome do utilizador: ");
    scanf(" %[^\n]", nome);
    printf("Escreva o ID do utilizador: ");
    scanf(" %[^\n]", id);

    inicializarUtilizador(&bib->utilizadores[bib->totalUtilizadores], nome, id);
    bib->totalUtilizadores++;

    printf("\nUtilizador cadastrado com sucesso!\n");
    salvarDados(bib);
}

void listarLivros(const Biblioteca *bib) {
    printf("\nLista de Livros:\n");
    for (int i = 0; i < bib->totalLivros; i++) {
        exibirDetalhes(&bib->livros[i]);
    }
}

void listarUtilizadores(const Biblioteca *bib) {
    printf("\nLista de Usuários:\n");
    for (int i = 0; i < bib->totalUtilizadores; i++) {
        exibirUtilizador(&bib->utilizadores[i]);
    }
}

void emprestarLivro(Biblioteca *bib) {
    char id[MAX_ID], ISBN[MAX_ISBN];

    printf("\nEscreva o ID do utilizador: ");
    scanf(" %[^\n]", id);
    printf("Escreva o ISBN do livro: ");
    scanf(" %[^\n]", ISBN);

    for (int i = 0; i < bib->totalUtilizadores; i++) {
        if (strcmp(bib->utilizadores[i].id, id) == 0) {
            for (int j = 0; j < bib->totalLivros; j++) {
                if (strcmp(bib->livros[j].ISBN, ISBN) == 0 && !bib->livros[j].emprestado) {
                    if (podeEmprestar(&bib->utilizadores[i])) {
                        emprestarLivro(&bib->livros[j]);
                        registrarEmprestimo(&bib->utilizadores[i]);
                        printf("\nEmpréstimo realizado!\n");
                        salvarDados(bib);
                        return;
                    }
                }
            }
        }
    }

    printf("\nErro: Livro indisponível ou utilizador não encontrado!\n");
}

void devolverLivroBiblioteca(Biblioteca *bib) {
    char id[MAX_ID], ISBN[MAX_ISBN];

    printf("\nEscreva o ID do utilizador: ");
    scanf(" %[^\n]", id);
    printf("Escreva o ISBN do livro: ");
    scanf(" %[^\n]", ISBN);

    for (int i = 0; i < bib->totalUtilizadores; i++) {
        if (strcmp(bib->utilizadores[i].id, id) == 0) {
            for (int j = 0; j < bib->totalLivros; j++) {
                if (strcmp(bib->livros[j].ISBN, ISBN) == 0 && bib->livros[j].emprestado) {
                    devolverLivro(&bib->livros[j]);
                    registrarDevolucao(&bib->utilizadores[i]);
                    printf("\nDevolução realizada!\n");
                    salvarDados(bib);
                    return;
                }
            }
        }
    }

    printf("\nErro: Livro não encontrado ou não emprestado!\n");
}

void salvarDados(const Biblioteca *bib) {
    FILE *arquivo = fopen("dados.txt", "w");
    if (!arquivo) return;

    fprintf(arquivo, "%d %d\n", bib->totalLivros, bib->totalUtilizadores);

    for (int i = 0; i < bib->totalLivros; i++) {
        fprintf(arquivo, "%s %s %s %s %d\n", bib->livros[i].titulo, bib->livros[i].autor,
                bib->livros[i].ISBN, bib->livros[i].genero, bib->livros[i].emprestado);
    }

    for (int i = 0; i < bib->totalUtilizadores; i++) {
        fprintf(arquivo, "%s %s %d\n", bib->utilizadores[i].nome, bib->utilizadores[i].id, bib->utilizadores[i].numEmprestimos);
    }

    fclose(arquivo);
}

void carregarDados(Biblioteca *bib) {
    FILE *arquivo = fopen("dados.txt", "r");
    if (!arquivo) return;

    fscanf(arquivo, "%d %d", &bib->totalLivros, &bib->totalUtilizadores);

    for (int i = 0; i < bib->totalLivros; i++) {
        fscanf(arquivo, "%s %s %s %s %d", bib->livros[i].titulo, bib->livros[i].autor,
               bib->livros[i].ISBN, bib->livros[i].genero, &bib->livros[i].emprestado);
    }

    for (int i = 0; i < bib->totalUtilizadores; i++) {
        fscanf(arquivo, "%s %s %d", bib->utilizadores[i].nome, bib->utilizadores[i].id, &bib->utilizadores[i].numEmprestimos);
    }

    fclose(arquivo);
}
