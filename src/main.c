/**
 * @file main.c
 * @author Luís Rodrigues (a24849@alunos.ipca.pt)
 * @brief 
 * @version 0.1
 * @date 2025-03-25
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "../include/funcoes.h"

int main(){

    Antena* lista = NULL;

    // Criar e inserir antenas
    Antena* antena1 = criarAntena(10, 2, 'A');
    lista = inserirOrdenado(lista, antena1);
    
    Antena* antena2 = criarAntena(3, 15, 'B');
    lista = inserirOrdenado(lista, antena2);
    
    Antena* antena3 = criarAntena(3, 10, 'C');
    lista = inserirOrdenado(lista, antena3);

    // Remover uma antena

    Antena* ra2 = removerAntena(lista, 3, 15, 'B');
    lista = ra2; // Atualiza a lista após a remoção

        // Imprimir as antenas diretamente no main
    printf("Lista de Antenas:\n");
    Antena* atual = lista; // Começa do início da lista
    // Percorre a lista e imprime as antenas
    while (atual) { 
        printf("Antena -> X: %d, Y: %d, Freq: %c\n", atual->x, atual->y, atual->freq);
        atual = atual->next; // Avança para a próxima antena
    }


    
    // Remover antenas (free)
    destruirLista(lista);
    lista = NULL; // Prevenir acessos inválidos após a destruição da lista

    
}