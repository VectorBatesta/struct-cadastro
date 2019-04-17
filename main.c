/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Vitor
 *
 * Created on 24 de Outubro de 2018, 22:27
 */



//NAO TERMINEI ta no git a toa mesmo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

    
typedef struct{
    char cidade[15];
    char estado[2];
}CIDADE;

typedef struct{
    char nome[50];
    int idade;
    char endereco[50];
    CIDADE *cidad;
}PESSOA;

void *alocar(int x){
    int *tmp=NULL;
    tmp = (int *) malloc(x * sizeof(int *));
    
    for (int i=0; i<x; i++)
        tmp[i]=0;
    
    return tmp;
}

/*
 * 
 */
int main(int argc, char** argv) {
    
    int numcadastros;
    printf("Quantos cadastros serao feitos?\n");
    scanf("%i", &numcadastros);
    
    PESSOA person[numcadastros];
    
    //person = aloca(numcadastros);
    
    int selecao;
    do{
        printf("\n1-registrar nome\n"
                "2-registrar idade\n"
                "3-registrar endereco\n"
                "4-registrar cidade\n"
                "5-sair\n");
        scanf("%i", &selecao);
        switch(selecao){
                case 1://nome
                {
                    int i=0;
                    int termino=0;
                    do{
                        printf("Qual dos %i cadastros?\n", numcadastros);
                        printf("Lista:\n");
                        for (int j=0; j<numcadastros; j++)
                            printf("%i - %s, %i, %s, %s.\n", j+1, person[i].nome, person[i].idade, person[i].cidad->cidade, person[i].cidad->estado);
                        scanf("%i", &i);

                        printf("Digite o nome");
                        fgets(person[i].nome, sizeof(person[i].nome), stdin);
                        person[i].nome[strcspn(person[i].nome,"\n")]='\0';

                        printf("registrar novamente? 0 = sim, 1 = nao.");
                        scanf("%i", &termino);
                    }while (termino !=1);
                    break;
                }
                case 2://idade
                {
                    int i=0;
                    int termino=0;
                    do{
                        printf("Qual dos %i cadastros?\n", numcadastros);
                        printf("Lista:\n");
                        for (int j=0; j<numcadastros; j++)
                            printf("%i - %s, %i, %s, %s.\n", j+1, person[i].nome, person[i].idade, person[i].cidad->cidade, person[i].cidad->estado);
                        scanf("%i", &i);
                    
                        printf("Digite a idade");
                        scanf("%i", &person[i].idade);

                        printf("registrar novamente? 0 = sim, 1 = nao.");
                        scanf("%i", &termino);
                    }while (termino !=1);
                    
                    break;
                }
        }
    }while (selecao!=5);
    
    
    return (EXIT_SUCCESS);
}

