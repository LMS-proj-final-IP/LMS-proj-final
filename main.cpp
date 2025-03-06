#include <cstdio>   // Para printf, scanf
#include <cstdlib>  // Para exit
#include <cstring>  // Para strcmp, strcpy, strlen
#include "Biblioteca.h"

int main() {
    Biblioteca bib;
    inicializarBiblioteca(&bib);

    int opcao;
    do {
        printf("\n========================================");
        printf("\n    SISTEMA DE GESTÃO DE BIBLIOTECA   ");
        printf("\n========================================\n");
        printf("\n[1] Adicionar Livro");
        printf("\n[2] Adicionar Utilizador");
        printf("\n[3] Mostrar Livros");
        printf("\n[4] Mostrar Utilizadores");
        printf("\n[5] Emprestar Livro");
        printf("\n[6] Devolver Livro");
        printf("\n[0] Sair");
        printf("\n========================================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: adicionarLivro(&bib); break;
            case 2: adicionarUtilizador(&bib); break;
            case 3: listarLivros(&bib); break;
            case 4: listarUtilizadores(&bib); break;
            case 5: emprestarLivro(&bib); break;
            case 6: devolverLivroBiblioteca(&bib); break;
            case 0: printf("\nA sair do Sistema..\n"); break;
            default: printf("\nOpção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}
