#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define Maxvalor 100000000
#define Max 1000
typedef struct
{
    char Nrua[50], bairro[50],cidade[50];
    int numero[6],cep[8];
} Tendereco;

typedef struct
{
    char titulo[60];
    int pavimentos[2], n_quartos[3];
    float area_do_terreno[10], area_construida[10];
} Tcasa;

typedef struct
{
    char titulo[60], posicao[20];
    int n_quartos[3], andar[3];
    float area[10], valor_coond[10];
    int n_vagas_garagem[3];
} Tapartamento;

typedef struct
{
    char Informacoes_sobre[1000], titulo[60];
    float area[10];
} Tterreno;

typedef struct
{
    long long int valor[Maxvalor];
    char status[50];
} Tinfor;

int main()
{
    menu();

    return 0;
}
void menu()
{

    int op;
    do
    {
        system("clear");
        system("cls");
        printf("\n1- Cadastro de imoveis\n2- Consulta de imoveis\n0- Sair\n");
        scanf("%d", &op);
        switch(op)
        {
        case 1:
            cadastrar();
            break;
        case 2:
            consultar();
            break;
        case 0:
            exit(0);
        }
    }
    while(op!=0);
}

void cadastrar()
{
    system("clear");
    system("cls");
    int op;
    do
    {
        printf("\n1- Casa\n2- Apartamento\n3- Terreno\n0- Voltar\n");
        scanf("%d", &op);
        switch(op)
        {
        case 1:
            casa();
            break;
        case 2:
            apartamento();
            break;
        case 3:
            terreno();
            break;
        case 0:
            menu();
            break;
        }
    }
    while(op!=0);
}

void casa()
{
    int op;
    Tendereco endereco[Max];
    Tcasa casa[Max];
    do
    {
        system("clear");
        system("cls");
        printf("\nDigite o Titulo do Anuncio abaixo\n-");
        getchar();
        fgets(casa[Max].titulo,sizeof(casa[Max].titulo),stdin);
        printf("\nDigite o Numero de pavimetos(andares) abaixo\n-");
        scanf("%d", &casa[Max].pavimentos);
        printf("\nDigite o numero de quartos abaixo\n-");
        scanf("%d", &casa[Max].n_quartos);
        printf("\nDigite a area do terreno abaixo\n-");
        scanf("%d", &casa[Max].area_do_terreno);
        printf("\nDigite a area construida abaixo\n-");
        scanf("%f", &casa[Max].area_construida);
        printf("\nDigite o logradouro (nome da rua) abaixo\n-");
        getchar();
        fgets(endereco[Max].Nrua,sizeof(endereco[Max].Nrua),stdin);
        printf("\nDigite o numero da casa abaixo\n-");
        scanf("%d", &endereco[Max].numero);
        printf("\nDigite o nome bairro abaixo\n-");
        getchar();
        fgets(endereco[Max].bairro,sizeof(endereco[Max].bairro),stdin);
        printf("\nDigite o CEP abaixo\n-");
        scanf("%d", &endereco[Max].cep);
        printf("\nDigite a Cidade abaixo\n-");
        getchar();
        fgets(endereco[Max].cidade,sizeof(endereco[Max].cidade),stdin);

        printf("\n1- Continuar\n2- Voltar\n0- Sair\n");
        scanf("%d", &op);
        switch(op)
        {
        case 1:
            continue;
            break;
        case 2:
            menu();
            break;
        case 0:
            exit(0);
            break;
        }


    }
    while(op!=0);
}
void apartamento()
{
    system("clear");
    system("cls");
}

void terreno()
{
    system("clear");
    system("cls");
}

void consultar()
{
    system("clear");
    system("cls");
}


