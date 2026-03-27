// Bibliotecas usadas

#include <stdio.h>
#include <string.h> // Especificamente para realizar busca com strings

// Padronizar tamanho das matrizes, facilita alteracao

#define linha 2
#define coluna 2

// Variaveis utilizadas, chamei no global para nao ter conflito

int opcaoMenu, i = 0, j = 0;
char nomeP[linha][coluna][50], pesquisa[50];
int quantidade[linha][coluna];
int lin, col, soma, found = 0;
int lin2, col2, sub;

// Trouxe as funcoes para aqui em cima para nao ter problema de continuidade no codigo

void cadprod();
void switchmenuP();
void exiprod();
void adcquant();
void removquant();
void busca();

// Funcao menu contendo as opcoes para o usuario

void menu(){

    printf("Estoque\n\n");
    printf("1 - Cadastrar produtos\n");
    printf("2 - Exibir estoque\n");
    printf("3 - Dar entrada(Adicionar)\n");
    printf("4 - Dar saida(Remover)\n");
    printf("5 - Buscar produto\n");
    printf("6 - Encerrar acesso\n\n");
    printf("O que deseja fazer?: ");
    scanf("%d", &opcaoMenu);

}

// Funcao switch para navegar entre as opcoes do menu com encerramento

void switchmenuP(){

    switch(opcaoMenu){

        case 1:
            cadprod();
        break;
            
        case 2:
            exiprod();
        break;

        case 3:
            adcquant();
        break;

        case 4:
            removquant();
        break;

        case 5:
            busca();
        break;

        case 6:
            printf("\nAcesso encerrado.");
        break;

        default:
            printf("\nOpcao invalida, tente novamente\n");
        break;
    }
}

/* Funcao de cadastro
Aqui utilizei matrizes e nao struct por questao de ainda nao ter aprendido
As estruturas de repeticao percorrem todas as duas matrizes para cadastrar o nome do produto e a quantidade*/

void cadprod(){

    printf("\n-- Sistema de cadastro --\n\n");

    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){

            printf("Nome do produto: ");
            scanf("%s", nomeP[i][j]);
            printf("Quantidade(Unidade): ");
            scanf("%d", &quantidade[i][j]);
            printf("\n");
        }
    }
    printf("\nCadastro realizado\n\n");
}

// Funcao de exibicao dos produtos cadastrados

void exiprod(){

    printf("\n-- Produtos em estoque:\n\n");

    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){

            printf("Produto: %s\nQuantidade: %d\n Posicao: [%d][%d]\n\n", nomeP[i][j], quantidade[i][j], i, j);
        }
    }
}

/* Essa funcao adiciona quantidade de acordo com a entrada do usuario ao item especificado pelo codigo da matriz
Eu exibo o codigo de cada quantidade de cada item especifico no menu exibir
O usuario escolhe o codigo e faz a adicao */

void adcquant(){

    printf("\n--Adicionar quantidade ao estoque--\n\n");

    printf("Primeiro digito da posicao do produto: ");
    scanf("%d", &lin);

    printf("Segundo digito da posicao do produto: ");
    scanf("%d", &col);

    if(lin >= 0 && lin < linha && col >= 0 && col < coluna){

        printf("\nQuantidade atual: %d\n\n", quantidade[lin][col]);

        printf("Quantas unidades deseja adicionar?: ");
        scanf("%d", &soma);

        quantidade[lin][col] += soma;

        printf("\nNova quantidade: %d\n", quantidade[lin][col]);
        printf("Operacao realizada com sucesso\n\n");

    } else {
        printf("Posicao invalida!\n\n");
    }
    }

/* Mesma aplicabilidade da funcao anterior. Essa subtrai
Utilizei estrutura de condicao para que nao seja possivel estoque negativo*/

void removquant(){

    printf("\n--Retirar quantidade do estoque--\n\n");

    printf("Primeiro digito da posicao do produto: ");
    scanf("%d", &lin2);

    printf("Segundo digito da posicao do produto: ");
    scanf("%d", &col2);

    if(lin2 >= 0 && lin2 < linha && col2 >= 0 && col2 < coluna){

        printf("\nQuantidade atual: %d\n\n", quantidade[lin2][col2]);

        printf("Quantas unidades deseja retirar?: ");
        scanf("%d", &sub);

        if(sub > quantidade[lin2][col2]){

            printf("\nQuantidade solicitada maior que o estoque\n\n");
        }
        else {
            quantidade[lin2][col2] -= sub;

            printf("\nNova quantidade: %d\n", quantidade[lin2][col2]);
            printf("Operacao realizada com sucesso\n\n");
        }

    } else {
        printf("Posicao invalida!\n\n");
    }
}

/* Essa funcao realiza a busca de um item especifico pelo nome
O strcmp possibilita isso
Ainda sem opcao de entrada de dados para strings com espaco porque nao aprendi*/

void busca(){

    found = 0;

    printf("\nDigite abaixo o item que deseja procurar: ");
    scanf("%s", pesquisa);

    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){

            if(strcmp(nomeP[i][j], pesquisa) == 0){

                printf("\n%s Ja esta cadastrado. Existem %d unidades em estoque\n\n", pesquisa, quantidade[i][j]);
                found = 1;
                break;
            }   
        }
            if (found) break;
    }
    if (!found) {
        printf("Produto nao encontrado\n\n");
    }
}

// Onde tudo acontece e roda, laco de repeticao para que so seja encerrado de acordo com a vontade do usuario.

int main(){

    do{
    menu();
    switchmenuP();
    }
    while(opcaoMenu != 6);

return 0;
}
