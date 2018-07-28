#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define Maxvalor 1000
#define Max 1000

typedef struct
{
    char Nrua[50], bairro[50],cidade[50];
    int Ncasa, Nap, cep;
} T_endereco;
T_endereco endereco[Max];

typedef struct
{
    char titulo[60];
    int pavimentos, Nquartos;
    double areaTerreno, areaConstruida;
} T_casa;
T_casa casa[Max];

typedef struct
{
    char titulo[60], posicao[20];
    int Nquartos[3], andar[3];
    double area[10], vCondominio[10];
    int Nvagas[3];
} T_apartamento;
T_apartamento apartamento[Max];

typedef struct
{
    char Informacoes[1000], titulo[60];
    double area;
} T_terreno;
T_terreno terreno[Max];

typedef struct
{
    long double valor;
    int statusc[2], statusa[2], statust[2];
} T_info;
T_info info[Max];

void menu();
void cadastrar();
void caasa();
void apartamentoo();
void terrenoo();
void consultar();
int conectar();
void desconectar();

FILE *file;


int main()
{
    // CHAMADA DA FUNÇÃO MENU
    menu();

    return 0;
}
void menu()
{

    int op;
    do
    {
        system("cls");

        printf("1 - Cadastro de imoveis\n2 - Consulta de imoveis\n0 - Sair\n-");
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
            break;
        }
    }
    while(op!=0);
}
void cadastrar()
{


    int op;
    do
    {
        system("cls");

        printf("1 - Casa\n2 - Apartamento\n3 - Terreno\n0 - Voltar\n-");
        scanf("%d", &op);

        switch(op)
        {
        case 1:
            caasa();
            break;
        case 2:
            apartamentoo();
            break;
        case 3:
            terrenoo();
            break;
        case 0:
            menu();
            break;
        }
    }
    while(op != 0);
}
void caasa()
{

    int op;
    do
    {

        system("cls");
// SOBRE O CASA
        printf("\nTitulo do Anuncio:\n-");
        getchar();
        fgets(casa[Max].titulo,sizeof(casa[Max].titulo),stdin);

        printf("\nNumero de pavimetos (Andares):\n-");
        scanf("%d", &casa[Max].pavimentos);

        printf("\nNumero de quartos:\n-");
        scanf("%d", &casa[Max].Nquartos);

        printf("\nArea do terreno:\n-");
        scanf("%lf", &casa[Max].areaTerreno);

        printf("\nArea construida:\n-");
        scanf("%lf", &casa[Max].areaConstruida);
// ENDEREÇO CASA
        printf("\nNome da Rua:\n-");
        getchar();
        fgets(endereco[Max].Nrua,sizeof(endereco[Max].Nrua),stdin);

        printf("\nNumero:\n-");
        scanf("%d", &endereco[Max].Ncasa);

        printf("\nBairro:\n-");
        getchar();
        fgets(endereco[Max].bairro,sizeof(endereco[Max].bairro),stdin);

        printf("\nCEP:\n-");
        scanf("%d", &endereco[Max].cep);

        printf("\nCidade:\n-");
        getchar();
        fgets(endereco[Max].cidade,sizeof(endereco[Max].cidade),stdin);

        printf("\n1 - Para aluguel\n2 - A venda\n-");
        scanf("%d", &info[Max].statusc[1]);
        getchar();

        if(info[Max].statusc[1]==1)
        {
            printf("\nValor do aluguel:\n-");
            scanf("%lf", &info[Max].valor);

        }
        else if(info[Max].statusc[1]==2)
        {
            printf("\nValor da Casa:\n-");
            scanf("%lf", &info[Max].valor);
        }
        printf("VEIO");
        if(conectar(1)){
            printf("VEIO AQUI");
            fprintf(file, "Titulo: %s\n", casa[Max].titulo);
            fprintf(file, "Pavimentos: %d\n", casa[Max].pavimentos);
            fprintf(file, "Numero de quartos: %d\n", casa[Max].Nquartos);
            fprintf(file, "Area Terreno: %.2lf m\n", casa[Max].areaTerreno);
            fprintf(file, "Area Construida: %.2lf m\n", casa[Max].areaConstruida);
            fprintf(file, "Rua: %s\n", endereco[Max].Nrua);
            fprintf(file, "Numero: %d\n", endereco[Max].Ncasa);
            fprintf(file, "Bairro: %s\n", endereco[Max].bairro);
            fprintf(file, "CEP: %d\n", endereco[Max].cep);
            fprintf(file, "Cidade: %s\n", endereco[Max].cidade);
            fprintf(file, "Status: %d\n", info[Max].statusc[1]);
            fprintf(file, "Valor: R$ %.2llf\n", info[Max].valor);
            desconectar();
        }


        printf("\n1 - Continuar\n2 - Voltar\n0 - Sair\n-");
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
void apartamentoo()
{

    int op;
    do
    {
        system("cls");
// SOBRE O AP
        printf("Informe o Titulo do Imovel:\n-");
        getchar();
        fgets(apartamento[Max].titulo, sizeof(apartamento[Max].titulo),stdin);

        printf("\nArea do Ap em M2:\n-");
        scanf("%lf", &apartamento[Max].area);

        printf("\nNumero de Quartos:\n-");
        scanf("%d", &apartamento[Max].Nquartos);

        printf("\nPosicao do AP:\n-");
        getchar();
        fgets(apartamento[Max].posicao, sizeof(apartamento[Max].posicao),stdin);

        printf("\nAndar:\n-");
        scanf("%d", &apartamento[Max].andar);

        printf("\nValor do condominio:\n-");
        scanf("%lf", &apartamento[Max].vCondominio);

        printf("\nNumero de vagas de garagem:\n-");
        scanf("%d", &apartamento[Max].Nvagas);

// ENDERECO AP
        printf("\nNome da Rua:\n-");
        getchar();
        fgets(endereco[Max].Nrua,sizeof(endereco[Max].Nrua),stdin);

        printf("\nNumero:\n-");
        scanf("%d", &endereco[Max].Nap);

        printf("\nBairro:\n-");
        getchar();
        fgets(endereco[Max].bairro,sizeof(endereco[Max].bairro),stdin);

        printf("\nCEP:\n-");
        scanf("%d", &endereco[Max].cep);

        printf("\nCidade:\n-");
        getchar();
        fgets(endereco[Max].cidade,sizeof(endereco[Max].cidade),stdin);

        printf("\n1 - Para aluguel\n2 - A venda\n-");
        scanf("%d", &info[Max].statusa[1]);
        getchar();

        if(info[Max].statusa[1]==1)
        {
            printf("\nValor do aluguel:\n-");
            scanf("%lf", &info[Max].valor);

        }
        else if(info[Max].statusa[1]==2)
        {
            printf("\nValor do Apartamento:\n-");
            scanf("%lf", &info[Max].valor);
        }

        printf("\n1 - Continuar\n2 - Voltar\n0 - Sair\n-");
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
    while(op != 0);
}
void terrenoo()
{
    int op;
    do
    {
        system("cls");
//INFORMAÇÃO
        printf("Informe o Titulo do Imovel:\n-");
        getchar();
        fgets(terreno[Max].titulo, sizeof(terreno[Max].titulo),stdin);

        printf("\nArea do terreno:\n-");
        scanf("%lf", &terreno[Max].area);

//ENDEREÇO
        printf("\nNome da Rua:\n-");
        getchar();
        fgets(endereco[Max].Nrua,sizeof(endereco[Max].Nrua),stdin);

        printf("\nLote:\n-");
        scanf("%d", &endereco[Max].Ncasa);

        printf("\nBairro:\n-");
        getchar();
        fgets(endereco[Max].bairro, sizeof(endereco[Max].bairro), stdin);

        printf("\nCEP:\n-");
        scanf("%d", &endereco[Max].cep);

        printf("\nCidade:\n-");
        getchar();
        fgets(endereco[Max].cidade, sizeof(endereco[Max].cidade), stdin);

        printf("\n1 - Para aluguel\n2 - A venda\n-");
        scanf("%d", &info[Max].statust[1]);
        getchar();

        if(info[Max].statust[1]==1)
        {
            printf("\nValor do aluguel:\n-");
            scanf("%lf", &info[Max].valor);
        }
        else if(info[Max].statust[1]==2)
        {
            printf("\nValor do Terreno:\n-");
            scanf("%lf", &info[Max].valor);
        }

        printf("\n1 - Continuar\n2 - Voltar\n0 - Sair\n-");
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
void consultar()
{
    system("clear");
    system("cls");
}
int conectar(int tipo){
    if(tipo == 1) {//Cadastrar
        file=fopen("C:\\Users\\Erison\\Desktop\\arquivo.txt","a");
    }

    if(file==NULL)
    {
        printf("Falha ao abrir arquivo.");
        return 0;
    }
    else
    {
        return 1;
    }
    return 0;
}
void desconectar(){
    fclose(file);
}
