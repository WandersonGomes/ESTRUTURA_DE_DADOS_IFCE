#include <stdio.h>
#include "time.h"

int main() {
    PTime time;
    int pontos = 0;
    char* novo_tecnico;

    //criar o time
    time = criarTime();

    //ler dados do time
    lerDadosTime(time);

    //pontos alcancados
    pontos = pontosAlcancados(time);

    //trocar tecnico
    printf("\nInforme o nome do novo tecnico: ");
    novo_tecnico = lerString(TAMANHO_NOME_TIME);
    trocarTecnico(time, novo_tecnico);
    
    //imprimir dados tecnico
    imprimirDadosTime(time);

    //desalocar memoria
    liberarTime(time);

    return 0;
}