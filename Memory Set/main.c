#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

#define coberto 0
#define descoberto 1

// TABULEIRO
int jogo1[4][5]=
{
    0,1,2,3,4,
    5,6,7,8,9,
    0,1,2,3,4,
    5,6,7,8,9
};

// PARA SABER QUAIS JÁ FORAM DESCOBERTOS
int jogo2[4][5]=
{
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0
};

// PROTÓTIPOS DAS FUNÇÕES
void monta(); // Imprime o tabuleiro
int analiza(); // Analiza se todas as peças foram descobertas


int main(){
    int l, c, l2, c2;
    int op, gameover=0;
    
    printf("\t\tBem-vindo(a) ao JOGO DA MEMORIA\n\n");
    printf("Escolha ums opcao:\n");
    printf("(1) Jogar\n");
    printf("(2) Sair\n");
    printf("Op: ");
    scanf("%d", &op);
    
    if(op==1){
        while(!gameover){
            jgd1: system("cls");
            monta();
            printf("Digite a linha e a coluna, respectivamente: ");
            scanf("%d %d", &l, &c);
            if(l>4 || l<1 || c>5 || c<1){
                printf("Numeros invalidos!! Digite e 1 a 5 para linha\ne de 1 a 4 para a coluna.\n");
                system("pause");
                goto jgd1;
            }
            if(jogo2[l][c]==descoberto){
                printf("Ops... Lugar ja descoberto.\n");
                system("pause");
                goto jgd1;
            }
            jogo2[l][c]=descoberto;
            jgd2: system("cls");
            monta();
            printf("Digite a linha e a coluna, respectivamente: ");
            scanf("%d %d",&l2,&c2);
            if(l2>4 || l2<1 || c2>5 || c2<1){
                printf("Numeros invalidos!! Digite e 1 a 5 para linha\ne de 1 a 4 para a coluna.\n");
                system("pause");
                goto jgd2;
            }
            if(jogo2[l2][c2]==descoberto){
                printf("Ops... Lugar ja descoberto.\n");
                system("pause");
                goto jgd2;
            }
            jogo2[l2][c2] = descoberto;
            system("cls");
            monta();
            if(jogo1[l][c] != jogo1[l2][c2]){
                printf("Errou!\n");
                jogo2[l][c]=coberto;
                jogo2[l2][c2]=coberto;
            }
            else printf("Boa!\n");
            Sleep(1000);
            gameover = analiza();
        }
    }
    system("cls");
    exit(2);
    return 0;
}

// MONTA O TABULEIRO
void monta(){
    int l, c;
    printf("  1 2 3 4 5\n");
    for(l=0; l<4; l++){
            printf("%d ",l+1);
        for(c=0; c<5; c++){
            if(jogo2[l][c]==descoberto)
                printf("%d|",jogo2[l][c]);
            else if(l<3) printf("_|");
            else printf(" |");
        }
        printf("\n");
    }
    printf("\n\n");
}

// ANALIZA O JOGO
int analiza(){
    int qt, l, c;
    for(l=0; l<4; l++) for(c=0; c<5; c++) if(jogo2[l][c]==descoberto) qt++;
    if(qt==20) return 1;
    return 0;
}