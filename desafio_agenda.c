/*
Autor: Wanderson Gomes da Costa
Semestre: 2020.2
Disciplina: Estrutura de Dados
Faça um programa para manipular uma agenda telefônica de N contatos.
(alocados dinamicamente). Cada contato deve ter os seguintes dados:
• Nome
• E-mail
• Endereço (Rua, bairro, cidade, estado, país)
• Telefone
• Data de aniversário(dia e mês)
Implemente as funções para:
● Ler os dados dos contatos.
● buscar um contato pelo nome e imprimir os dados do contato.
● Receber uma data e imprimir os contatos que fazem aniversário nesta
data.
● Imprimir a agenda inteira.
Faça um menu principal com as funções acima.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//STRUCT
typedef struct {
    int numero;
    char rua[30];
    char bairro[30];
    char cidade[30];
    char estado[30];
    char cep[30];
} Endereco;

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char nome[30];
    char email[30];
    Endereco endereco;
    char telefone[15];
    Data aniversario;
} Contato;

//FUNCAO QUE CRIA CONTATO
Contato criaContato() {
    Contato contato;

    printf("Nome: ");
    fgets(contato.nome, 30, stdin);
    printf("Email: ");
    fgets(contato.email, 30, stdin);
    printf("Numero casa: ");
    scanf("%d", &contato.endereco.numero);
    getchar();
    printf("Rua: ");
    fgets(contato.endereco.rua, 30, stdin);
    printf("Bairro: ");
    fgets(contato.endereco.bairro, 30, stdin);
    printf("Cidade: ");
    fgets(contato.endereco.cidade, 30, stdin);
    printf("Estado: ");
    fgets(contato.endereco.estado, 30, stdin);
    printf("CEP: ");
    fgets(contato.endereco.cep, 30, stdin);
    printf("Telefone: ");
    fgets(contato.telefone, 15, stdin);
    printf("Dia nascimento: ");
    scanf("%d", &contato.aniversario.dia);
    printf("Mes nascimento: ");
    scanf("%d", &contato.aniversario.mes);
    printf("Ano nascimento: ");
    scanf("%d", &contato.aniversario.ano);

    return contato;
}

//FUNCAO QUE EXIBE OS DADOS DE UM CONTATO
void exibeDadosContato(Contato contato) {
    printf("\n===Dados Contato===\n");
    printf("Nome: %s", contato.nome);
    printf("Email: %s", contato.email);
    printf("Numero casa: %d\n", contato.endereco.numero);
    printf("Rua: %s", contato.endereco.rua);
    printf("Bairro: %s", contato.endereco.bairro);
    printf("Cidade: %s", contato.endereco.cidade);
    printf("Estado: %s", contato.endereco.estado);
    printf("CEP: %s", contato.endereco.cep);
    printf("Telefone: %s", contato.telefone);
    printf("Dia nascimento: %d\n", contato.aniversario.dia);
    printf("Mes nascimento: %d\n", contato.aniversario.mes);
    printf("Ano nascimento: %d\n", contato.aniversario.ano);
}

//FUNCAO PARA APRESENTAR OS DADOS DO CONTATO
void buscarPeloNome(char* nome, Contato agenda[], int qtd) {
    int i = 0;

    for (i = 0; i < qtd; i++) {
        if (strcmp(agenda[i].nome, nome) == 0) {
            exibeDadosContato(agenda[i]);
            return;
        }
    }

    printf("Nenhum contato encontrado!\n");
}

//FUNCAO PARA IMPRIMIR A AGENDA TODA
void exibeAgenda(Contato agenda[], int qtd) {
    int i = 0;
    
    if (qtd == 0) {
        printf("Agenda vazia!\n");
        return;
    }

    for (i = 0; i < qtd; i++) {
        exibeDadosContato(agenda[i]);
    }
}

//FUNCAO QUE IMPRIME OS CONTATOS QUE POSSUEM A DA DE NASCIMENTO
void exibeContatoAniversario(int dia, int mes, int ano, Contato agenda[], int qtd) {
    int i = 0, flag = 1;

    for (i = 0; i < qtd; i++) {
        if (agenda[i].aniversario.dia == dia && agenda[i].aniversario.mes == mes && agenda[i].aniversario.ano == ano) {
            exibeDadosContato(agenda[i]);
            flag = 0;
        }
    }

    if (flag) {
        printf("Nenhum contato faz aniversario em %d/%d/%d\n", dia, mes, ano);
    }
}

//PROGRAMA PRINCIPAL
int main() {
    int quantidade_contatos = 0;
    int opcao = 0, qtd_atual = 0;
    char nome[30];
    int dia = 0, mes = 0, ano = 0;

    do {
        printf("Informe a quantidade de contatos da agenda: ");
        scanf("%d", &quantidade_contatos);
        if (quantidade_contatos <= 0) {
            printf("Error: quantidade invalida!\nTente novamente.\n");
        }
    } while (quantidade_contatos <= 0);

    Contato* agenda = (Contato*) malloc(quantidade_contatos * sizeof(Contato));

    while (1) {
        do {
            printf("\n===MENU===\n");
            printf("1 - Adicionar contato\n");
            printf("2 - Buscar contato pelo nome\n");
            printf("3 - Imprimir contatos com data de aniversario\n");
            printf("4 - Imprimir a agenda inteira\n");
            printf("5 - Sair\n");
            printf("Opcao: ");
            scanf("%d", &opcao);
            if (opcao < 0 || opcao > 5) {
                printf("Error: opcao invalida!\nTente novamente.\n");
            }
        } while (opcao < 0 || opcao > 5);
        getchar();

        switch (opcao) {
            case 1:
                agenda[qtd_atual] = criaContato();
                qtd_atual++;
                break;
            case 2:
                printf("Informe o nome que se deseja buscar: ");
                fgets(nome, 30, stdin);
                buscarPeloNome(nome, agenda, qtd_atual);
                break;
            case 3:
                printf("Informe o dia, mes e ano da data de aniversario: ");
                scanf("%d %d %d", &dia, &mes, &ano);
                exibeContatoAniversario(dia, mes, ano, agenda, qtd_atual);
                break;
            case 4:
                exibeAgenda(agenda, qtd_atual);
                break;
            case 5:
                return 0;
        }
    }

    return 0;
}