#include <stdio.h>
#include <math.h>
#include "projeto.h"
//criacao de tolerancia de erro, global para que não use muita memoria conforme a recursão
//erro 1*10^(-9)
#define tol 0.000000000001
//definindo o valor de h para derivada
#define h 0.000001
//valores das variaveis do problema
#define c 0.0001
#define l 5
#define t 0.05
int quant = 0;

double f(double x){//aqui é a função para ser calculada
    double expo = (-x*t)/(2*l);//expoente do euler
    double calc = x/(2*l);
    double radi = (1/(l*c)) - (pow(calc, 2));
    if (radi < 0){
        printf("Função não continua no ponto %lf\n", x);
        return NAN;
    }
    double raiz = sqrt(radi);
    double cosseno = raiz * t;
    return exp(expo) * cos(cosseno) - 0.01;
}

double deriva(double x){
    double fxh = f(x + h);
    double fhx = f(x - h);
    double derivada =  (fxh - fhx)/(2*h);
    if (fabs(derivada) < tol){//verificação se a derivada não está muito próxima de 0 ou se é 0
        printf("Derivada no ponto %lf igual a 0 ou muito proxima a 0, metodo nao convergiu", x);
        return NAN;
    }
    return derivada;
}

double calculo(double xr){
    double fx = f(xr);
    if (quant == 150){
        printf("Metodo nao convergiu apos 150 interacoes, encerrando ele");
        return NAN;
    }
    //inicio dos verificadores
    if(isnan(fx))
        return NAN;
    double derivada = deriva(xr);
    if (isnan(derivada))
        return NAN;
    if(fx == 0)
        return xr;
    //fim dos verificadores
    double prox = xr - (fx/derivada);//calculo do proximo ponto XR
    if(fabs(prox - xr) < tol)
        return prox;
    else{
        quant++;
        return calculo(prox);
    }
}

void menu_N(){
    quant = 0;
    double xr;
    printf("xr = ");
    scanf("%lf", &xr);
    double x = calculo (xr);
    if(isnan(x)){}
    else{
        printf("A raiz da funcao eh %.12lf\n", x);
    }
}