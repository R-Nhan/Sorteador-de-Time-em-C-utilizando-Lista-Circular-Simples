#include <stdio.h>
#include <unistd.h>
#include "sorteio.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
    no *lista = NULL;
    no *times = NULL;
    char name[100];
    int d, fim = 1;
    while (fim != 1246){
        printf("-------------------------------\n");
        printf("           M E N U\n");
        printf("-------------------------------\n\n");
        printf("1 - Adicionar na lista\n");
        printf("2 - mostrar lista\n");
        printf("3 - Tirar Pessoa\n");
        printf("4 - Sorteiar Pessoa\n");
        printf("5 - Sorteiar Time\n");
        printf("6 - sair\n");
        printf("escolha uma opção: \n");
        scanf("%d",&d);
        system("clear");
        switch(d){
            case 1:
                printf("digite o nome\n");
                scanf ("%s", name);
                add_pessoa(&lista, name);
                break;
            case 2:
                mostrar_pessoa(&lista);
                break;
            case 3:
                if (lista == NULL) {
                    printf("Lista vazia!\n");
                } else { 
                    mostrar_pessoa(&lista);
                    printf("Digite a pessoa que deseja tirar\n");
                    scanf("%s", name);
                    tirar_caba(&lista, name, 1);
                }
                break;
            case 4:
                sort_caba(&lista);
                break;
            case 5:
                sort_time(&lista, &times);
                break;
            case 6:
                fim = 1246;
                break;
            default:
                printf("opção inválida!\n");
                break;
        }
    }
    return 0;
}