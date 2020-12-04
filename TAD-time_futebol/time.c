#include "time.h"

//STRUCTS
struct time {
    char* nome;
    char* tecnico;
    int vitorias;
    int empates;
    int derrotas;
    int gols_marcados;
    int gols_sofridos;
    int cartoes_amarelos;
    int cartoes_vermelhos;
};

//FUNCOES AUXILIARES
int ehLetra(char caractere) {
    if ((caractere >= 'a') && (caractere <= 'z'))
        return 1;
    if ((caractere >= 'A') && (caractere <= 'Z'))
        return 1;
    if ((caractere == ' ') || (caractere == '-'))
        return 1;
    if ((caractere >= '0') && (caractere <= '9'))
        return 1;

    return 0;
}

int lerDadoInteiroPositivo(char* mensagem) {
    int valor = 0;

    do {
        printf("%s", mensagem);
        scanf("%d", &valor);
        if (valor < 0) {
            printf("Error: valor invalido!\nTente novamente.\n");
        }
    } while (valor < 0);

    return valor;
}

//FUNCOES DO TAD
char* lerString(int quantidade_caracteres) {
    int i = 0;
    char letra = 'a';
    char* string = (char *) malloc(sizeof(char) * quantidade_caracteres);
    
    while (1) {
        letra = getchar();

        if (((letra == '\n') && (i > 0)) || (i == (quantidade_caracteres - 1))) {
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

PTime criarTime() {
    return (PTime) malloc(sizeof(Time));
}

void lerDadosTime(PTime time) {
    printf("Informe o nome do time: ");
    time->nome = lerString(TAMANHO_NOME_TIME);

    printf("Informe o nome do tecnico: ");
    time->tecnico = lerString(TAMANHO_NOME_TIME);

    time->vitorias = lerDadoInteiroPositivo("Informe o numero de vitorias: ");

    time->empates = lerDadoInteiroPositivo("Informe o numero de empates: ");

    time->derrotas = lerDadoInteiroPositivo("Informe o numero de derrotas: ");

    time->gols_marcados = lerDadoInteiroPositivo("Informe o numero de gols marcados: ");

    time->gols_sofridos = lerDadoInteiroPositivo("Informe o numero de gols sofridos: ");

    time->cartoes_amarelos = lerDadoInteiroPositivo("Informe a quantidade de cartoes amarelos: ");

    time->cartoes_vermelhos = lerDadoInteiroPositivo("Informe a quantidade de cartoes vermelhos: ");
}

int pontosAlcancados(PTime time) {
    return ((time->empates*PONTO_EMPATE) + (time->vitorias * PONTO_VITORIA));
}

void trocarTecnico(PTime time, char* novo_tecnico) {
    strcpy(time->tecnico, novo_tecnico);
}
void imprimirDadosTime(PTime time) {
    printf("\nDADOS DO TIME:\n");
    printf("Nome: %s\n", time->nome);
    printf("Tecnico: %s\n", time->tecnico);
    printf("QTD. Vitorias: %d\n", time->vitorias);
    printf("QTD. Empates: %d\n", time->empates);
    printf("QTD. Derrotas: %d\n", time->derrotas);
    printf("QTD. Gols Marcados: %d\n", time->gols_marcados);
    printf("QTD. Gols Sofridos: %d\n", time->gols_sofridos);
    printf("QTD. Cartoes Vermelhos: %d\n", time->cartoes_vermelhos);
    printf("QTD. Cartoes Amarelos: %d\n", time->cartoes_amarelos);
    printf("QTD. Pontos: %d\n", pontosAlcancados(time));
}

void liberarTime(PTime time) {
    free(time);
}