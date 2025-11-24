#ifndef SORTEIO_H
#define SORTEIO_H

extern int pos;

typedef struct no {
    char nome[100];
    struct no *next;
} no;
void add_pessoa(no **lista, char name[]);
void mostrar_pessoa(no **lista);
void tirar_caba(no **lista, char name[], int num);
void sort_caba(no **lista);
void sort_time(no **lista, no **times);
void time_s(char name[], no **times);
void mostrar_time(no **times, int numero);

#endif

