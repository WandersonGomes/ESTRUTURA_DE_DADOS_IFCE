/*
Autor: Wanderson Gomes da Costa
Semestre: 2020.2
Disciplina: Estrutura de Dados
Professor: Nécio de Lima Veras 
Descricao do problema:
Escreva um programa que determine a soma dos quadrados dos n primeiros números naturais, onde o n é lido pela plataforma.
*/
#include <stdio.h>

int main() {
    long long int numero = 0, soma = 0;

    scanf("%lld", &numero);

    soma = (numero * (numero + 1) * (2*numero + 1))/6;

    printf("%lld\n", soma);
    
    return 0;
}