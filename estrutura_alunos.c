/*
Autor: Wanderson Gomes da Costa
Semestre: 2020.2
Disciplina: Estrutura de Dados
Professor: Nécio de Lima Veras 
Descricao do problema:
Implemente um código para ler dados de 5 alunos. Os dados são:
Nome, matrícula, turma, nota1 e nota2. Imprima os dados de
todos os alunos, a média de cada um ((nota1+nota2) /2) e se o
aluno está aprovado ou não, considerando 7 como a média
mínima para aprovação.
*/
#include <stdio.h>

#define MEDIA_APROVACAO 7.0
#define MAX_ALUNOS 5

typedef struct {
    char nome[30];
    int matricula;
    int turma;
    float nota1;
    float nota2;
    float media;
} Aluno;

//FUNCAO QUE LER OS DADOS DOS ALUNOS
void preencheDadosAlunos(int quantidade, Aluno alunos[]) {
    int i = 0;
    if (alunos != NULL) {
        for (i = 0; i < quantidade; i++) {
            printf("\nDADOS DO %d.o ALUNO:\n", i+1);
            //nome
            printf("Nome do aluno: ");
            fgets(alunos[i].nome, 30, stdin);
            //matricula
            do {
                printf("Matricula do aluno: ");
                scanf("%d", &alunos[i].matricula);
                if (alunos[i].matricula <= 0) {
                    printf("Error: matricula invalida!\nTente novamente.\n");
                }
            } while (alunos[i].matricula <= 0);
            //turma
            do {
                printf("Turma do aluno: ");
                scanf("%d", &alunos[i].turma);
                if (alunos[i].turma <= 0) {
                    printf("Error: matricula invalida!\nTente novamente.\n");
                }
            } while (alunos[i].turma <= 0);
            //notas
            do {
                printf("Informe a primeira nota: ");
                scanf("%f", &alunos[i].nota1);
                if (alunos[i].nota1 < 0) {
                    printf("Error: nota invalida!\nTente novamente.\n");
                }
            } while (alunos[i].nota1 < 0);
            do {
                printf("Informe a segunda nota: ");
                scanf("%f", &alunos[i].nota2);
                if (alunos[i].nota2 < 0) {
                    printf("Error: nota invalida!\nTente novamente.\n");
                }
            } while (alunos[i].nota2 < 0);
            
            getchar();
            alunos[i].media = (alunos[i].nota1 + alunos[i].nota2)/2.0;
        }
    }
}

//FUNCAO QUE APRESENTA OS DADOS DOS ALUNOS
void imprimeDadosAlunos(int quantidade, Aluno alunos[]) {
    int i = 0;
    if (alunos != NULL) {
        for (i = 0; i < quantidade; i++) {
            printf("\nDADOS ALUNO %d\n", i+1);
            printf("Nome: %s", alunos[i].nome);
            printf("Matricula: %d\n", alunos[i].matricula);
            printf("Turma: %d\n", alunos[i].turma);
            printf("Nota 01: %.2f\n", alunos[i].nota1);
            printf("Nota 02: %.2f\n", alunos[i].nota2);
            printf("Media: %.2f\n", alunos[i].media);
            if (alunos[i].media >= MEDIA_APROVACAO) {
                printf("Situacao: Aprovado\n");
            } else {
                printf("Situacao: Reprovado\n");
            }
        }
    }
}

//PROGRAMA PRINCIPAL
int main() {
    Aluno alunos[MAX_ALUNOS];

    preencheDadosAlunos(MAX_ALUNOS, alunos);
    imprimeDadosAlunos(MAX_ALUNOS, alunos);

    return 0;
}