//IMPLEMENTACAO DAS FUNCOES
#include "aluno.h"

struct aluno {
    char* nome;
    int matricula;
    char* turma;
    float notas[3];
};

//FUNCOES AUXILIARES
int ehLetra(char caractere) {
    if ((caractere >= 'a') && (caractere <= 'z'))
        return 1;
    if ((caractere >= 'A') && (caractere <= 'Z'))
        return 1;
    if (caractere == ' ')
        return 1;
    if ((caractere >= '0') && (caractere <= '9'))
        return 1;
    return 0;
}

char* lerString(int quantidade) {
    int i = 0;
    char letra = 'a';
    char* string = (char*) malloc(sizeof(char) * quantidade);

    while (1) {
        letra = getchar();

        if (((letra == '\n') && (i > 0)) || (i == (quantidade - 1))) {
            break;
        }

        if (ehLetra(letra)) {
            string[i] = letra;
            i++;
        }
    }

    string[i] = '\0';
    
    return string;
}

void lerNota(float* nota, int indice) {
    do {
        printf("Informe a %d.a nota: ", indice);
        scanf("%f", nota);
        if ((*nota < 0) || (*nota > 10)) {
            printf("Error: nota invalida!\nTente novamente.\n");
        }
    } while ((*nota < 0) || (*nota > 10));
}

//FUNCOES
PAluno criarAluno() {
    return (PAluno) malloc(sizeof(Aluno));
}

PAluno criarAlunos(int quantidade){
    return (PAluno) malloc(sizeof(Aluno) * quantidade);
}

void lerDadosAluno(PAluno aluno, int indice) {
    int i = 0;

    printf("Informe o nome do aluno: ");
    aluno[indice].nome = lerString(QTD_CARACTERES_NOME);

    do {
        printf("Informe a matricula do aluno: ");
        scanf("%d", &aluno[indice].matricula);
        if (aluno[indice].matricula <= 0) {
            printf("Error: valor invalido!\nTente novamente.\n");
        }
    } while (aluno[indice].matricula <= 0);

    printf("Informe a turma do aluno: ");
    aluno[indice].turma = lerString(QTD_CARACTERES_NOME);

    for(; i < 3; i++) {
        lerNota(&aluno[indice].notas[i], i+1);
    }
}

float calcularMediaAluno(Aluno aluno) {
    return (aluno.notas[0] + aluno.notas[1] + aluno.notas[2])/3.0;
}

int situacaoAluno(Aluno aluno) {
    if (calcularMediaAluno(aluno) >= MEDIA_APROVACAO) {
        return 1;
    } else {
        return 0;
    }
}

void imprimirDadosAluno(PAluno aluno, int indice) {
    printf("Nome: %s\n", aluno[indice].nome);
    printf("Matricula: %d\n", aluno[indice].matricula);
    printf("Turma: %s\n", aluno[indice].turma);
    printf("Nota 1: %.2f\n", aluno[indice].notas[0]);
    printf("Nota 2: %.2f\n", aluno[indice].notas[1]);
    printf("Nota 3: %.2f\n", aluno[indice].notas[2]);
    printf("Media: %.2f\n", calcularMediaAluno(aluno[indice]));

    printf("Situacao: ");
    if (situacaoAluno(aluno[indice])) {
        printf("Aprovado\n");
    } else {
        printf("Reprovado\n");
    }
}

void liberarAluno(PAluno aluno) {
    free(aluno);
}