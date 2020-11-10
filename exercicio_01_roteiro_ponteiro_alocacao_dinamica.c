/*
Autor: Wanderson Gomes da Costa
Semestre: 2020.2
Disciplina: Estrutura de Dados
Professor: Necio de Lima Veras

Questao 01:
Crie um programa modularizado capaz de alocar dinamicamente um
vetor de números reais de tamanho n. Nesse vetor, serão armazenados a
altura de n pessoas. Ao final, o programa deve imprimir a maior, a
menor e a média das alturas.
*/
#include <stdio.h>
#include <stdlib.h>

//LIMITES DAS ALTURAS
#define ALTURA_MINIMA 0.20
#define ALTURA_MAXIMA 2.50

//FUNCAO QUE ALOCA UM VETOR DE FORMA DINAMICA
float* alocaVetor(int tamanho) {
    float* vetor = (float *) malloc(tamanho * sizeof(float));
    return vetor;
}

//FUNCAO QUE LER UMA ALTURA VALIDA E RETORNA A ALTURA LIDA
float lerAltura(int indice) {
    float altura = 0.0;
    do {
        printf("Informe a %d.a altura: ", indice);
        scanf("%f", &altura);
        if (altura < ALTURA_MINIMA || altura > ALTURA_MAXIMA) {
            printf("Error: altura invalida!\nTente novamente.\n");
        }
    } while (altura < ALTURA_MINIMA || altura > ALTURA_MAXIMA);

    return altura;
}

//PROGRAMA PRINCIPAL
int main() {
    int numero_alturas = 0, i = 0;
    float altura = 0.0, maior_altura = 0.0, menor_altura = 0.0, media_altura = 0.0;
    float *alturas = NULL;

    do {
        printf("Informe a quantidade de alturas que serao lidas: ");
        scanf("%d", &numero_alturas);
        if (numero_alturas <= 0) {
            printf("Error: quantidade invalida!\nTente novamente.\n");
        }
    } while (numero_alturas <= 0);

    alturas = alocaVetor(numero_alturas);

    menor_altura = ALTURA_MAXIMA + 1; //inicializar a menor altura com um valor fora dos limites
    for (i = 0; i < numero_alturas; i++) {
        altura = lerAltura(i+1);
        if (altura > maior_altura) {
            maior_altura = altura;
        }
        if (altura < menor_altura) {
            menor_altura = altura;
        }
        media_altura += altura;

        *(alturas+i) = altura;
    }
    media_altura = media_altura/numero_alturas; //calcula a media corretamente

    printf("\nALTURAS INFORMADAS:\n");
    for (i = 0; i < numero_alturas; i++) {
        printf("%d.a ALTURA = %.2f\n", (i+1), *(alturas+i));
    }

    printf("\nA MAIOR ALTURA INFORMADA FOI: %.2f\n", maior_altura);
    printf("A MENOR ALTURA INFORMADA FOI: %.2f\n", menor_altura);
    printf("A MEDIA ARITMETICA DAS ALTURAS E: %.2f\n", media_altura);

    //LIBERA A MEMORIA ALOCADA
    free(alturas);
    return 0;
}