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
#include <stdbool.h>

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

    Antena* inserirOrdenado(Antena* inicio, Antena* novo) {

        // validações
        if (novo == NULL) return inicio;
        // Se já existe, não insere
        if (existeAntena(inicio, novo->x, novo->y)) return inicio;
    
        // 1ª posição 
        if (inicio == NULL || 
            (novo->x < inicio->x || (novo->x == inicio->x && novo->y < inicio->y))) {
            novo->next = inicio;
            return novo;
        }
    
        Antena* aux = inicio;
        Antena* aux2 = aux;
    
        // Encontrar a posição correta com base em x e y
        while (aux != NULL && 
              (aux->x < novo->x || (aux->x == novo->x && aux->y < novo->y))) {
            aux2 = aux;
            aux = aux->next;
        }
    
        // Inserir no meio ou fim
        novo->next = aux;
        aux2->next = novo;
    
        return inicio;
    }

    /**
     * @brief Funcão para verificar se uma antena existe na lista
     * 
     * @param inicio 
     * @param x 
     * @param y 
     * @return true 
     * @return false 
     */
    

    bool existeAntena(Antena* inicio, int x, int y) {
        Antena* aux = inicio;
        while (aux) {
            if (aux->x == x && aux->y == y) {
                return true; // Encontrou uma antena com as coordenadas x e y
            }
            aux = aux->next;
        }
        return false; // Não encontrou
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
    
        // A antena a ser removida é a primeira da lista
        if (inicio->x == x && inicio->y == y && inicio->freq == freq) {
            Antena* temp = inicio;       // Guarda a antena a ser removida
            inicio = inicio->next;       // Atualiza o início da lista
            free(temp);                  // Liberta a memória da antena removida
            return inicio;               // Retorna o novo início da lista
        }
    
        // Percorre a lista para encontrar a antena a ser removida
        Antena* atual = inicio;
        while (atual->next) {
            if (atual->next->x == x && atual->next->y == y && atual->next->freq == freq) {
                Antena* temp = atual->next; // Guarda a antena a ser removida
                atual->next = temp->next;  // Remove a antena da lista
                free(temp);                // Liberta a memória da antena removida
                return inicio;             // Retorna o início da lista
            }
            atual = atual->next; // Avança para a próxima antena
        }
    
        // Se não encontrar a antena, retorna o início original
        return inicio;
    }


    int mostrarLista(Antena* inicio) {
        Antena* aux = inicio;
        if (!inicio) return 0;
    
        while (aux != NULL) {
            printf("X = %d | Y = %d | Freq = %c\n", aux->x, aux->y, aux->freq);
            aux = aux->next;
        }
        return 1;
    }
