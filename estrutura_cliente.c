/*
Autor: Wanderson Gomes da Costa
Semestre: 2020.2
Disciplina: Estrutura de Dados
Professor: Nécio de Lima Veras 
Descricao do problema:
Implemente um codigo que utilize uma estrutura para ler
e armazenar dados de um cliente (nome, CPF, RG e endereco).
Imprima os dados na tela.
*/
#include <stdio.h>

//Structs
typedef struct {
    int numero;
    char rua[30];
    char bairro[30];
} Endereco;

typedef struct {
    char nome[30];
    char cpf[16];
    char rg[30];
    Endereco end;
} Cliente;

//FUNCAO QUE LER OS DADOS DO CLIENTE;
void lerDadosCliente (Cliente* cliente) {
    if (cliente != NULL) {
        //nome
        printf("Informe o nome do cliente: ");
        fgets(cliente->nome, 30, stdin);
        //cpf
        printf("Informe o CPF do cliente: ");
        fgets(cliente->cpf, 16, stdin);
        //rg
        printf("Informe o RG do cliente: ");
        fgets(cliente->rg, 30, stdin);
        //endereco
        printf("===ENDERECO===\n");
        printf("Numero: ");
        scanf("%d", &cliente->end.numero);
        getchar();
        printf("Rua: ");
        fgets(cliente->end.rua, 30, stdin);
        printf("Bairro: ");
        fgets(cliente->end.bairro, 30, stdin);
    }
}

//FUNCAO QUE APRESENTA OS DADOS DO CLIENTE
void imprimeDadosCliente(Cliente cliente) {
    printf("\nDADOS DO CLIENTE:\n");
    printf("Nome: %s", cliente.nome);
    printf("CPF: %s", cliente.cpf);
    printf("RG: %s", cliente.rg);
    printf("===ENDERECO===\n");
    printf("Numero: %d\n", cliente.end.numero);
    printf("Rua: %s", cliente.end.rua);
    printf("Bairro: %s", cliente.end.bairro);
}

//PROGRAMA PRINCIPAL
int main() {
    Cliente cliente;

    lerDadosCliente(&cliente);
    imprimeDadosCliente(cliente);

    return 0;
}