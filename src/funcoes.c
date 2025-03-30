/**
 * @file funcoes.c
 * @author Luís Rodrigues (a24849@alunos.ipca.pt)
 * @brief 
 * @version 0.1
 * @date 2025-03-25
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "../include/funcoes.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Funcão para criar Antena
 * 
 * @param x Coordenada X da Antena
 * @param y Coordenada Y da Antena
 * @param freq Frequência da Antena
 * @return Antena* Apontador para a nova antena ou NULL se a alocação falhar
 */

Antena* criarAntena(int x, int y, char freq) {
	
    Antena* aux = malloc(sizeof(Antena));

	if (!aux) { //Se malloc falhar, retorna NULL
        return NULL;
    }

        aux->x = x;
        aux->y = y;
        aux->freq = freq;
        aux->next = NULL;

        return aux;
    }

    /**
     * @brief Função para inserir uma nova antena na lista de forma ordenada
     * 
     * @param inicio Apontador para o início da lista
     * @param nova Apontador para a nova antena a ser inserida
     * @return Antena* Apontador para o início da lista atualizada
     */

    Antena* inserirOrdenado(Antena* inicio, Antena* nova) {
        if (!nova) {
            return inicio; // Se a nova antena for NULL, retorna a lista original
        }
    
        // Caso a lista esteja vazia ou a nova antena deva ser inserida no início
        if (!inicio || (nova->x < inicio->x || (nova->x == inicio->x && nova->y < inicio->y))) {
            nova->next = inicio;
            return nova;
        }
    
        Antena* atual = inicio;
    
        // Percorre a lista até encontrar a posição correta para inserir
        while (atual->next && 
               (atual->next->x < nova->x || 
               (atual->next->x == nova->x && atual->next->y < nova->y))) {
            atual = atual->next;
        }
    
        // Insere a nova antena na posição correta
        nova->next = atual->next;
        atual->next = nova;
    
        return inicio;
    }

/**
 * @brief Funcão para remover antenas da lista (free)
 * 
 * @param inicio Apontador para o início da lista
 */

    void destruirLista(Antena* inicio) {
        if (inicio == NULL) return; // Verifica se a lista está vazia
        destruirLista(inicio->next); // Chama recursivamente para a próxima antena
        free(inicio);
    }

    /**
     * @brief Função para remover uma antena da lista
     * 
     * @param inicio Apontador para o início da lista
     * @param x Coordenada X da antena a ser removida
     * @param y Coordenada Y da antena a ser removida
     * @param freq Frequência da antena a ser removida
     * @return Antena* Apontador para o início da lista atualizada
     */
    

    Antena* removerAntena(Antena* inicio, int x, int y, char freq) {
        if (!inicio) {
            return NULL; // Lista vazia, nada a remover
        }
    
        // Caso especial: A antena a ser removida é a primeira da lista
        if (inicio->x == x && inicio->y == y && inicio->freq == freq) {
            Antena* temp = inicio;       // Guarda antena a ser removida
            inicio = inicio->next;       // Atualiza o início da lista
            free(temp);                  // Liberta a memória da antena removida
            return inicio;               // Retorna o novo início da lista
        }
    
        // Percorre a lista para encontrar a antena a ser removida
        Antena* atual = inicio;
        while (atual->next) {
            if (atual->next->x == x && atual->next->y == y && atual->next->freq == freq) {
                Antena* temp = atual->next; // Guardar a antena a ser removida
                atual->next = temp->next;  // Remover a antena da lista
                free(temp);                // Liberta a memória da antena removida
                return inicio;             // Retorna o início da lista
            }
            atual = atual->next; // Avançar para a próxima antena
        }
    
        // Se não encontrar a antena, retorna o início original
        return inicio;
    }
    