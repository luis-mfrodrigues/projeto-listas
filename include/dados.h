/**
 * @file dados.h
 * @author Luís Rodrigues (a24849@alunos.ipca.pt)
 * @brief 
 * @version 0.1
 * @date 2025-03-25
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #pragma once

 #include <stdio.h>
 #include <stdlib.h>


 /**
  * @brief Estrutura Antena
  * 
  */

typedef struct Antena {
    int x, y; //Coordenadas (x=linha, y=coluna)
    char freq; //Frequência
    struct Antena* next; //apontador para a próxima lista ligada
} Antena;
