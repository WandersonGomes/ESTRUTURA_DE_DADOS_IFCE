#ifndef _TIME_H
#define _TIME_H

#define TAMANHO_NOME_TIME 31
#define PONTO_VITORIA 3
#define PONTO_EMPATE 1

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct time Time, *PTime;

char* lerString(int quantidade_caracteres);
PTime criarTime();
void lerDadosTime(PTime time);
int pontosAlcancados(PTime time);
void trocarTecnico(PTime time, char* novo_tecnico);
void imprimirDadosTime(PTime time);
void liberarTime(PTime time);

#endif