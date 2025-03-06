#include "Utilizador.h"
#include <stdio.h>
#include <string.h>

void inicializarUtilizador(Utilizador *utilizador, const char *nome, const char *id) {
    strcpy(utilizador->nome, nome);
    strcpy(utilizador->id, id);
    utilizador->numEmprestimos = 0;
}

void exibirUtilizador(const Utilizador *utilizador) {
    printf("\nNome: %s\nID: %s\nEmpréstimos Ativos: %d\n", 
        utilizador->nome, utilizador->id, utilizador->numEmprestimos);
}

int podeEmprestar(const Utilizador *utilizador) {
    return utilizador->numEmprestimos < MAX_EMPRESTIMOS;
}

void registrarEmprestimo(Utilizador *utilizador) {
    if (podeEmprestar(utilizador)) {
        utilizador->numEmprestimos++;
    } else {
        printf("Utilizador atingiu o limite de empréstimos.\n");
    }
}

void registrarDevolucao(Utilizador *utilizador) {
    if (utilizador->numEmprestimos > 0) {
        utilizador->numEmprestimos--;
    } else {
        printf("Erro: Nenhum livro para devolver.\n");
    }
}
