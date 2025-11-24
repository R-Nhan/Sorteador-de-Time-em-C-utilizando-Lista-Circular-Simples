#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "sorteio.h"

int pos = 1;

void add_pessoa(no **lista, char name[]){
    no *bomenovo = malloc(sizeof(no));
    if (bomenovo == NULL) {
        printf("Falha de alocação!\n");
        return;
    }
    strcpy(bomenovo->nome, name);
    if (*lista == NULL){
        *lista = bomenovo;
        bomenovo->next = *lista;
    } else {
        no *aux = *lista;
        while (aux->next != *lista){
            aux = aux->next;
        }
        aux->next = bomenovo;
        bomenovo->next = *lista;
    }
    return;
}

void mostrar_pessoa(no **lista){
    if (*lista == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    no *aux = *lista;
    pos = 1;
    do {
        printf("%iº = %s\n", pos, aux->nome);
        aux = aux->next;
        pos++;
    } while (aux != *lista);
    return;
}

void tirar_caba(no **lista, char name[], int num){
    int x = 1;
    if (*lista == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    
    no *atual = *lista;
    no *anterior = NULL;
    
    do {
        if (strcmp(atual->nome, name) == 0) {
            if (atual == *lista && atual->next == *lista){
                free(atual);
                *lista = NULL;
            } else if (atual == *lista){
                no *ultimo = *lista;
                while (ultimo->next != *lista){
                    ultimo = ultimo->next;
                }
                *lista = atual->next;
                ultimo->next = *lista;
                free(atual);
            } else {
                anterior->next = atual->next;
                free(atual);
            }
            if (num == 1){
            printf("Pessoa '%s' removida com sucesso!\n", name);
            }
            return;
        }
        anterior = atual;
        atual = atual->next;
    } while(atual != *lista);
    printf("Pessoa '%s' não encontrada na lista.\n", name);
}

void sort_caba(no **lista){
    no *aux = *lista;
    srand(time(NULL));
    int min = 1, max = 100;
    int num = rand() % (max - min + 1) + min;
    if (*lista == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    for (int i = 0; i < num; i++){
        printf("Sorteando...\n");
        printf("%s\n", aux->nome);
        usleep(100000); 
        system("clear");
        aux = aux->next;
    }
    printf ("A pessoa sorteada foi: %s \n", aux->nome);
}

void mostrar_time(no **times, int numero){
    if (*times == NULL) {
        printf("Sem times!\n");
        return;
    }
    no *aux = *times;
    int grupo = 1;
    while (aux != NULL){
        printf("Grupo %i:\n", grupo);
        for (int i = 0; i < numero; i++){
            if (aux != NULL) {
                printf("%s\n", aux->nome);
                aux = aux->next;
            } else {
                printf("?\n"); // mostra interrogação quando faltar participante
            }
        }
        grupo++;
        printf("\n");
    }

    no *tmp;
    while (*times != NULL) {
        tmp = *times;
        *times = (*times)->next;
        free(tmp);
    }
}

void sort_time(no **lista, no **times){
   if (*lista == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    // COPIAR A LISTA ORIGINAL
    no *copia = NULL;
    no *aux = *lista;

    // Como é circular, percorre até voltar ao início
    do {
        add_pessoa(&copia, aux->nome);
        aux = aux->next;
    } while (aux != *lista);

    // Agora o sorteio será feito na cópia
    srand(time(NULL));
    int min = 1, max = 100;
    aux = copia;

    while (copia != NULL) {
        int num = rand() % (max - min + 1) + min;
        for (int i = 0; i < num; i++) {
            aux = aux->next;
        }

        char n[50];
        strcpy(n, aux->nome);

        // guarda o próximo antes de remover
        no *proximo = aux->next;

        time_s(n, times);
        tirar_caba(&copia, n, 0); // remove só da cópia

        if (copia == NULL)
            break;

        aux = proximo;
        if (aux == NULL || aux == copia)
            aux = copia;
    }
    int numero;
    printf("Digite o tamanho do Time: ");
    scanf("%i", &numero);
    mostrar_time(times, numero);
}

void time_s(char name[], no **times){
    no *bomenovo = malloc(sizeof(no));
    if (bomenovo == NULL) {
        printf("Erro de alocação!\n");
        return;
    }
    strcpy(bomenovo->nome, name);
    bomenovo->next = *times;
    *times = bomenovo;
}