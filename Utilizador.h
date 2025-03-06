#include <stdio.h>    // Para printf, scanf, FILE, fopen, fclose, fscanf, fprintf
#include <stdlib.h>   // Para malloc, free, exit
#include <string.h>   // Para strcmp, strcpy, strlen

#ifndef UTILIZADOR_H
#define UTILIZADOR_H

#define MAX_NOME 100
#define MAX_ID 20
#define MAX_EMPRESTIMOS 5

typedef struct {
    char nome[MAX_NOME];
    char id[MAX_ID];
    int numEmprestimos;
} Utilizador;

void inicializarUtilizador(Utilizador *utilizador, const char *nome, const char *id);
void exibirUtilizador(const Utilizador *utilizador);
int podeEmprestar(const Utilizador *utilizador);
void registrarEmprestimo(Utilizador *utilizador);
void registrarDevolucao(Utilizador *utilizador);

#endif
