/*
Autor: Wanderson Gomes da Costa
Instituicao: IFCE - Campus Tiangua
Professor: Necio de Lima Veras
Disiciplina: Estrutura de Dados

Problema:
Implemente um TAD denominado aluno. O TAD deverá ser capaz de manipular os
seguintes dados: nome, matrícula, turma e 3 notas por aluno. Um aluno é aprovado se a
média aritmética das 3 notas é igual ou maior que 7. O tipo abstrato de dados deve ler os
dados de n alunos e possuir as seguintes funcionalidades:

● Criar aluno (alocar memória para n alunos);
● Ler os dados individualmente;
● Calcular a média;
● Aferir a situação do aluno: “aprovado” ou “reprovado”;
● Imprimir os dados de todos os alunos;
● Desalocar a memória utilizada.

O projeto deverá ser composto pelos seguintes arquivos:

● aluno.h
● aluno.c
● main.c
● makefile - será útil para “ensinar" como compilar e como executar o projeto.
*/
#include <stdio.h>
#include "aluno.h"

int main() {
    int quantidade_alunos = 0, i = 0;
    PAluno alunos = NULL;

    do {
        printf("Informe a quantidade de alunos: ");
        scanf("%d", &quantidade_alunos);
        if (quantidade_alunos <= 0) {
            printf("Error: quantidade invalida!\nTente novamente.\n");
        }
    } while (quantidade_alunos <= 0);

    alunos = criarAlunos(quantidade_alunos);

    for (i = 0; i < quantidade_alunos; i++) {
        printf("\nINFORME DADOS DO %d.o ALUNO:\n", i+1);
        lerDadosAluno(alunos, i);
    }
    
    for (i = 0; i < quantidade_alunos; i++) {
        printf("\nDADOS DO %d.o ALUNO:\n", i+1);
        imprimirDadosAluno(alunos, i);
    }

    liberarAluno(alunos);

    return 0;
}