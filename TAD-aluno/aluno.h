//INTERFACE TAD
#ifndef INCLUDED_ALUNO_H
#define INCLUDED_ALUNO_H

#define MEDIA_APROVACAO 7.0
#define QTD_CARACTERES_NOME 31

//ESTRUTURA DO ALUNO
struct aluno {
    char nome[QTD_CARACTERES_NOME];
    int matricula;
    char turma[QTD_CARACTERES_NOME];
    float notas[3];
};

typedef struct aluno Aluno, *PAluno;

PAluno criarAluno();
PAluno criarAlunos(int quantidade);
void lerDadosAluno(PAluno aluno);
float calcularMediaAluno(Aluno aluno);
int situacaoAluno(Aluno aluno);
void imprimirDadosAluno(Aluno aluno);
void liberarAluno(PAluno aluno);

#endif