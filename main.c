#include <stdio.h>
#include "projeto.h"
//projeto de calculo numerico, metodo de newton e gauss-seidel
int main(){
    int escolha;
    do{
        printf("Digite\n1 para acessar o metodo de Newton\n2 para acessar o metodo de Gauss-Seidel\n0 para sair\n");
        scanf("%i", &escolha);
        switch (escolha){
            case 1:
                menu_N();
                break;
            case 2:
                menu_G();
                break;
            case 0:
                printf("Saindo..");
                break;
            default:
                printf("Escolha invalida\n");
                break;
    }
    }while (escolha != 0);
    return 0;
}