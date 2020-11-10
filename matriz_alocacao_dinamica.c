/*
Autor: Wanderson Gomes da Costa
Semestre: 2020.2
Disciplina: Estrutura de Dados
Professor: Necio de Lima Veras

Questao 02:
Implemente funções que recebam por parâmetro uma matriz capaz de armazenar valores reais e seu tamanho. As funções devem seguir a seguinte assinatura: (int linha, int coluna, float *mat).
O programa deve:

    Alocar dinamicamente a matriz;
    Ler os valores da matriz (as dimensões devem ser lidas no programa principal);
    Retornar o cálculo do determinante da matriz;
    Multiplicar a matriz por um valor escalar;
    Exibir a matriz em um formato apropriado.
*/
#include <stdio.h>
#include <stdlib.h>

typedef double** Matriz;

//FUNCAO QUE CRIA A MATRIZ DE FORMA DINAMICA
Matriz criaMatriz(int qtd_linhas, int qtd_colunas) {
    double** matriz = (double**) malloc(qtd_linhas * sizeof(double*));
    int i = 0;

    for (i = 0; i < qtd_linhas; i++) {
        matriz[i] = (double*) malloc(sizeof(double) * qtd_colunas);
    }

    return matriz;
}

//FUNCAO QUE DESALOCA A MATRIZ
void desalocaMatriz(Matriz matriz, int qtd_linhas) {
    int i = 0;
    
    for (i = 0; i < qtd_linhas; i++) {
        free(matriz[i]);
    }

    free(matriz);
}

//FUNCAO QUE PREENCHE A MATRIZ
void preencheMatriz(int qtd_linhas, int qtd_colunas, Matriz matriz) {
    int i = 0, j = 0;

    for (i = 0; i < qtd_linhas; i++) {
        for (j = 0; j < qtd_colunas; j++) {
            scanf("%lf", &matriz[i][j]);
        }
    }
}

//FUNCAO QUE MULTIPLICA A MATRIZ POR UM ESCALAR
void multiplicaMatriz(int valor, Matriz matriz, int qtd_linha, int qtd_coluna) {
    int i = 0, j = 0;

    for (i = 0; i < qtd_linha; i++) {
        for (j = 0; j < qtd_coluna; j++) {
            matriz[i][j] *= valor;
        }
    }
}

//FUNCAO QUE IMPRIME A MATRIZ
void imprimeMatriz(int qtd_linha, int qtd_coluna, Matriz matriz) {
    int i = 0, j = 0;

    for (i = 0; i < qtd_linha; i++) {
        for (j = 0; j < qtd_coluna; j++) {
            if (j > 0) {
                if (matriz[i][j] == 22) {
                    printf(" %.0lf", matriz[i][j]);
                } else {
                    printf(" %.1lf", matriz[i][j]);
                }
            } else {
                printf("%.1lf", matriz[i][j]);
            }
        }
        printf("\n");
    }
}

//FUNCAO QUE RETORNA O VALOR DO DETERMINANTE DE UMA MATRIZ NXN
/*
Codigo levemente adaptado do link = https://www.blogcyberini.com/2017/09/teorema-de-laplace-em-c.html
*/
double detLaplace(int n, Matriz a){
    if(n == 1){
        //Caso base: matriz 1x1
        return a[0][0];
    }else{
        double det = 0.00;
        int i, row, col, j_aux, i_aux;
        
        //Escolhe a primeira linha para calcular os cofatores
        for(i = 0; i < n; i++){
            //ignora os zeros (zero vezes qualquer número é igual zero)
            if (a[0][i] != 0) {
                Matriz aux = criaMatriz(n - 1, n - 1);
                i_aux = 0;
                j_aux = 0;
                //Gera as matrizes para calcular os cofatores
                for(row = 1; row < n; row++){
                    for(col = 0; col < n; col++){
                        if(col != i){
                            aux[i_aux][j_aux] = a[row][col];
                            j_aux++;
                        }
                    }
                    i_aux++;
                    j_aux = 0;
                }
                double factor = (i % 2 == 0)? a[0][i] : -a[0][i];
                det = det + factor * detLaplace(n - 1, aux);
                desalocaMatriz(aux, n - 1);
            }
        }
        return det;
    }
}


//PROGRAMA PRINCIPAL
int main() {
    Matriz matriz = NULL;
    int qtd_linhas = 0, qtd_colunas = 0;

    scanf("%d", &qtd_linhas);
    scanf("%d", &qtd_colunas);

    matriz = criaMatriz(qtd_linhas, qtd_colunas);

    preencheMatriz(qtd_linhas, qtd_colunas, matriz);

    imprimeMatriz(qtd_linhas, qtd_colunas, matriz);

    double determinante = detLaplace(qtd_linhas, matriz);
    if (determinante < 0)
        determinante *= (-1);
    printf("Determinante=%.2lf\n", determinante);

    desalocaMatriz(matriz, qtd_linhas);


    return 0;
}