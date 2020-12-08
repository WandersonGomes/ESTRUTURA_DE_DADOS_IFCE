//INTERFACE TAD
#ifndef _ALUNO_H
#define _ALUNO_H

//DEPENDENCIAS
#include <stdio.h>
#include <stdlib.h>

//CONSTANTES
#define MEDIA_APROVACAO 7.0
#define QTD_CARACTERES_NOME 31

typedef struct aluno Aluno, *PAluno;

PAluno criarAluno();
PAluno criarAlunos(int quantidade);
void lerDadosAluno(PAluno aluno, int indice);
float calcularMediaAluno(Aluno aluno);
int situacaoAluno(Aluno aluno);
void imprimirDadosAluno(PAluno aluno, int indice);
void liberarAluno(PAluno aluno);

#endif