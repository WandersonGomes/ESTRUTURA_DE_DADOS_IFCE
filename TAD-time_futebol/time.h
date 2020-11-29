#ifndef TIME_INCLUDED
#define TIME_INCLUDED

#define TAMANHO_NOME_TIME 31
#define PONTO_VITORIA 3
#define PONTO_EMPATE 1

struct time {
    char nome[TAMANHO_NOME_TIME];
    char tecnico[TAMANHO_NOME_TIME];
    int vitorias;
    int empates;
    int derrotas;
    int gols_marcados;
    int gols_sofridos;
    int cartoes_amarelos;
    int cartoes_vermelhos;
};

typedef struct time Time, *PTime;

void lerString(char *string, int quantidade);
PTime criarTime();
void lerDadosTime(PTime time);
int pontosAlcancados(PTime time);
void trocarTecnico(PTime time, char* novo_tecnico);
void imprimirDadosTime(PTime time);
void liberarTime(PTime time);

#endif