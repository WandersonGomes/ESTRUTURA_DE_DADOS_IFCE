/*
Autor: Wanderson Gomes da Costa
Semestre: 2020.2
Disciplina: Estrutura de Dados
Professor: Nécio de Lima Veras 
Descricao do problema:
Faca um codigo para ler e mostrar os seguintes dados de um
cliente: nome, CPF, telefone, endereco, estado civil e salario.
O endereco e formado pelos campos: rua, bairro, cidade, estado e
CEP.
*/
#include <stdio.h>

//STRUCTS
typedef struct {
    char rua[30];
    char bairro[30];
    char cidade[30];
    char estado[30];
    char cep[30];
} Endereco;

typedef struct {
    char nome[30];
    char cpf[30];
    char telefone[30];
    char estado_civil[30];
    float salario;
    Endereco endereco;
} Cliente;

//FUNCAO PARA LER OS DADOS DO CLIENTE E ENVIAR PARA O PROGRAMA PRINCIPAL
Cliente criaCliente() {
    Cliente cliente;
    //nome
    printf("Informe o nome do cliente: ");
    fgets(cliente.nome, 30, stdin);
    //cpf
    printf("Informe o CPF do cliente: ");
    fgets(cliente.cpf, 30, stdin);
    //telefone
    printf("Informe o telefone do cliente: ");
    fgets(cliente.telefone, 30, stdin);
    //estado_civil
    printf("Informe o estado civil do cliente: ");
    fgets(cliente.estado_civil, 30, stdin);
    //salario
    do {
        printf("Informe o salario do cliente: ");
        scanf("%f", &cliente.salario);
        if (cliente.salario <= 0) {
            printf("Error: salario invalido!\nTente novamente.\n");
        }
    } while (cliente.salario <= 0);
    getchar();
    //rua
    printf("Informe a rua do cliente: ");
    fgets(cliente.endereco.rua, 30, stdin);
    //bairro
    printf("Informe o bairro do cliente: ");
    fgets(cliente.endereco.bairro, 30, stdin);
    //cidade
    printf("Informe a cidade do cliente: ");
    fgets(cliente.endereco.cidade, 30, stdin);
    //estado
    printf("Informe o estado do cliente: ");
    fgets(cliente.endereco.estado, 30, stdin);
    //CEP
    printf("Informe o CEP do cliente: ");
    fgets(cliente.endereco.cep, 30, stdin);

    return cliente;
}

//FUNCAO QUE EXIBE OS DADOS DO CLIENTE
void exibeDadosCliente(Cliente cliente) {
    printf("\n===DADOS CLIENTE===\n");
    printf("Nome: %s", cliente.nome);
    printf("CPF: %s", cliente.cpf);
    printf("Telefone: %s", cliente.telefone);
    printf("Endereco: %s, %s, %s, %s, %s", cliente.endereco.rua, cliente.endereco.bairro, cliente.endereco.cidade, cliente.endereco.estado, cliente.endereco.cep);
    printf("Estado Civil: %s", cliente.estado_civil);
    printf("Salario: %.2f\n", cliente.salario);
}

//PROGRAMA PRINCIPAL
int main() {
    Cliente cliente;

    cliente = criaCliente();
    exibeDadosCliente(cliente);

    return 0;
}