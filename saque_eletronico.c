/*
Autor: Wanderson Gomes da Costa
Semestre: 2020.2
Disciplina: Estrutura de Dados
Professor: Nécio de Lima Veras 
Descricao do problema:
Um programa para gerenciar os saques de um caixa eletrônico deve possuir algum mecanismo para decidir o número de notas de cada valor que deve ser disponibilizado para o cliente que realizou o saque. Um possível critério seria o da “distribuição ótima” no sentido de que as notas de menor valor fossem distribuídas em número mínimo possível.

Por exemplo, se a quantia solicitada fosse R$ 87,00, programa deveria indicar uma nota de R$ 50,00, três notas de R$ 10,00, uma nota de R$ 5,00 e uma nota de R$ 2,00. Escreva um programa que receba o valor da quantia solicitada e retorne a distribuição das notas de acordo com o critério da distribuição ótima. Considere que existem as seguintes notas: R$ 100,00 R$ 50,00 R$ 20,00 R$ 10,00 R$ 5,00 R$ 2,00 R$ 1,00

Para a entrada dos dados o algoritmo deve ler APENAS o valor a ser sacado e como saída informar a quantidade exata para cada nota (seguindo a ordem decrescente de notas). Exemplo: 232
2
0
1
1
0
2
0

Ou seja: O valor a ser sacado é igual a 232. O sistema retornará o seguinte quantitativo: 2 notas de R$ 100,00 0 nota de R$ 50,00 1 nota de R$ 20,00 1 nota de R$ 10,00 0 nota de R$ 5,00 2 notas de R$ 2,00 0 nota de R$ 1,00
*/
#include <stdio.h>

int main() {
    int valor = 0;

    scanf("%d", &valor);

    //100
    printf("%d\n", (valor/100));
    valor = valor%100;
    //50
    printf("%d\n", (valor/50));
    valor = valor%50;
    //20
    printf("%d\n", (valor/20));
    valor = valor%20;
    //10
    printf("%d\n", (valor/10));
    valor = valor%10;
    //5
    printf("%d\n", (valor/5));
    valor = valor%5;
    //2
    printf("%d\n", (valor/2));
    valor = valor%2;
    //1
    printf("%d\n", valor);

    return 0;
}