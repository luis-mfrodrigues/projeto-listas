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
    Antena* antena1 = criarAntena(5, 2, 'A');
    lista = inserirOrdenado(lista, antena1);
    
    Antena* antena2 = criarAntena(3, 5, 'B');
    lista = inserirOrdenado(lista, antena2);
    
    Antena* antena3 = criarAntena(3, 10, 'C');
    lista = inserirOrdenado(lista, antena3);

    // Remover uma antena

    Antena* ra3 = removerAntena(lista, 3, 10, 'C');
    lista = ra3; // Atualiza a lista após a remoção

    // Verificar se uma antena existe

    

    if (existeAntena(lista, 3, 10)) {
        printf("Antena com coordenadas (3,10) existe!\n");
    } else {
        printf("Antena com coordenadas (3,10) não existe.\n");
    }

    


    // Mostrar lista
    mostrarLista(lista);


    // Remover antenas (free)
    destruirLista(lista);
    lista = NULL; // Prevenir acessos inválidos após a destruição da lista

    
}