/**
 * @file funcoes.h
 * @author Luís Rodrigues (a24849@alunos.ipca.pt)
 * @brief 
 * @version 0.1
 * @date 2025-03-25
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once
#include "dados.h"
#include <stdbool.h>

Antena* criarAntena(int x, int y, char freq);

Antena* inserirOrdenado(Antena* inicio, Antena* nova);

Antena* removerAntena(Antena* inicio, int x, int y, char freq);

void destruirLista(Antena* inicio);

bool existeAntena(Antena *inicio, int x, int y);

int mostrarLista(Antena *inicio);