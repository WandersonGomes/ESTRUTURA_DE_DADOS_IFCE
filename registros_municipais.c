/*
Autor: Wanderson Gomes da Costa
Semestre: 2020.2
Disciplina: Estrutura de Dados
Desenvolva um programa que cadastre registros municipais. Cada registro deve possuir o nome do município, o estado e a população.

A primeira leitura será o número de registros que será lido em seguida. Depois o programa irá ler cada registro seguindo a ordem de leitura: nome, estado (apenas a sigla com 2 caracteres) e o tamanho da população.

Ao final, o programa deve exibir todos os municípios cadastrados do estado do CE e, além disso, os dados do município que contenha a maior população (independente de qual estado ele pertença).

Observações:

    Crie um novo tipo de dado para o registro
    Manipule o registro por meio de um ponteiro
    Escreva o programa de forma modularizada
    Atente para a saída esperada

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//STRUCTS
typedef struct {
    char nome[30];
    char estado[3];
    int populacao;
} Municipio;

//FUNCAO QUE VERIFICA SE O CARACTERE E UMA LETRA
int ehLetra(char caractere) {
    if ((caractere >= 97) && (caractere <= 122)) {
        return 1;
    }
    if ((caractere >= 65) && (caractere <= 90)) {
        return 1;
    }
    if (caractere == ' ')
        return 1;
    
    return 0;
}

//FUNCAO PARA LER STRING
void lerString(char* string) {
    int i = 0;
    char caractere = 'a';

    while (1) {
        caractere = getchar();
        if ((caractere == '\n') && (i > 0)) {
            string[i] = '\0';
            break;
        } else if (ehLetra(caractere)) {
            string[i] = caractere;
            i++;
        }
    }    
}

//LER OS DADOS DOS MUNICIPIOS
void lerDadosMunicipios(Municipio* municipios, int qtd_municipios) {
    int i = 0;
    for (i = 0; i < qtd_municipios; i++) {
        lerString(municipios[i].nome);
        lerString(municipios[i].estado);
        scanf("%d", &municipios[i].populacao);
        getchar();
        //printf("%d\n", municipios[i].populacao);
    }
}

//FUNCAO QUE IMPRIME OS DADOS DOS MUNICIPIOS QUE ESTAO LOCALIZADOS NO CEARA
void imprimeMunicipiosCeara(Municipio* municipios, int qtd_municipios) {
    int i = 0;
    for (i = 0; i < qtd_municipios; i++) {
        if (strcmp(municipios[i].estado, "CE") == 0) {
            printf("%s-%s\n", municipios[i].nome, municipios[i].estado);
        }
    }
} 

//FUNCAO QUE IMPRIME OS DADOS DO MUNICIPIO COM A MAIOR POPULACAO
void imprimeMunicipioMaiorPopulacao(Municipio* municipios, int qtd_municipios) {
    int i = 0;
    Municipio municipio_maior_populacao = municipios[0];

    for (i = 1; i < qtd_municipios; i++) {
        if (municipio_maior_populacao.populacao < municipios[i].populacao) {
            municipio_maior_populacao = municipios[i];
        }
    }

    printf("%s-%s = %d\n", municipio_maior_populacao.nome, municipio_maior_populacao.estado, municipio_maior_populacao.populacao);
}

//PROGRAMA PRINCIPAL
int main() {
    int qtd_municipios = 0;
    Municipio* municipios = NULL;
    
    scanf("%d", &qtd_municipios);
    getchar();

    municipios = (Municipio*) malloc(sizeof(Municipio) * qtd_municipios);

    lerDadosMunicipios(municipios, qtd_municipios);

    imprimeMunicipiosCeara(municipios, qtd_municipios);

    imprimeMunicipioMaiorPopulacao(municipios, qtd_municipios);

    free(municipios);

    return 0;
}