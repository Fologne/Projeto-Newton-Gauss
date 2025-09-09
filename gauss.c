#include <stdio.h>
#include <math.h>
#include "projeto.h"
//tolerancia de erro
//erro 1*10^(-9)
#define tol 0.000000000001
int quant1;

void recursao(int ordem, double matriz[][ordem], double resultado[], double x[]){
    if(quant1 == 300){
        printf("Erro, ultrapassou o limite maximo de interacoes (300) e nao convergiu ao resultado, retornando ao menu\n");
        return;
    }
    double max_erro = 0;//aqui verifica o valor total do erro
    //aqui calcula os valores de x y e z
    for (int i = 0; i < ordem; i++){
        double soma = resultado[i];//aqui começa a soma de cada linha
        for(int j = 0; j < ordem; j++){
            if(j != i){//nao inclui o termo diagonal da linha para calcular x
                soma -= matriz[i][j] * x[j];//a segunda parte da soma do calculo de cada linha
                //x[j] é o vetor do resultado de cada variavel
            }
        }
        double x_novo = soma/matriz[i][i];
        double erro = fabs(x_novo - x[i]);
        if(erro > max_erro){max_erro =  erro;}//aqui substitui o erro pelo maior erro da interação
        x[i] = x_novo;
    }
    //fim do calculo dos valores de Xn
    quant1++;
    if(max_erro < tol){//se o erro for menor que a tolerancia ele imprime o resultado e encerra
        printf("Solucao:\n");
        for(int i = 0; i < ordem; i++){
            printf("Solucao de x[%i]: %.12lf\n", i+1, x[i]);
        }
        return;
    }
    recursao(ordem, matriz, resultado, x);
}
//verifica se é dominante
int dominante(int ordem, double matriz[][ordem], double resultado[], double x[]){//os elementos da diagonal devem ser maiores ou iguais
    //a soma dos outros integrantes da linha
    for(int i = 0; i < ordem; i++){
        double soma = 0;
        for(int j = 0; j < ordem; j++){
            if (i != j){
                soma += fabs(matriz[i][j]);
            }
        }
        if(fabs(matriz[i][i]) < soma){//não é dominante
            return 0;
        }
    }
    return 1;//dominante
}
//verifica se é simetrica
int simetrica(int ordem, double matriz[][ordem], double resultado[], double x[]){
    for (int i = 0; i < ordem; i++){
        for (int j = 0; j < ordem; j++){
            if (matriz[i][j] != matriz[j][i]){
                return 0;//não é simetrica
            }
        }
    }
    return 1;//simetrica
}
//aqui cria a matriz e verifica
void matriz(int ordem){
    quant1 = 0;
    double matriz[ordem][ordem];
    double resultado[ordem];
    for(int i = 0; i < ordem; i++){
        for(int j = 0; j < ordem; j++){
            printf("Digite o valor do numero de a%i%i: ", i+1, j+1);
            scanf("%lf", &matriz[i][j]);
        }
    }
    for(int i = 0; i < ordem; i++){
        printf("Digite o valor do resultado %i: ", i+1);
        scanf("%lf", &resultado[i]);
    }
    double x[ordem];//vetor criado para receber os valores de x1 até xn
    double valor;
    printf("Digite o valor de teste inicial");
    scanf("%lf", &valor);
    for(int i = 0; i < ordem; i++){x[i] = valor;}
    //fim do primeiro valor para começar o loop
    int domina = dominante(ordem, matriz, resultado, x);
    int sime = simetrica(ordem, matriz, resultado, x);
    if(domina == 1 || sime == 1){
        recursao(ordem, matriz, resultado, x);
    }else{
        printf ("Matriz nao e dominante e nem simetrica, risco do metodo nao convergir\nDeseja continuar?\n1 - SIM\n2 - NAO\n");
        int escolha;
        scanf("%i", &escolha);
        if(escolha == 1){
            recursao(ordem, matriz, resultado, x);
        }else{
            return;
        }
    }
    
}

void menu_G(){
    int ordem;
    printf ("Digite o valor da ordem da matriz: ");
    scanf("%i", &ordem);
    matriz(ordem);
    return;
}