//
//  main.c
//  Thema 7
//
//  Created by Michael Irimus on 09.01.18.
//  Copyright © 2018 Michael Irimus. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char matrix[3][3];

void initBoard(void);
void printBoard(void);
int checkField(int x, int y);
void set(int player, int x, int y);
int checkIfWon(void);
void compmove(void);

void clearscr ( void )
{
    for ( int i = 0; i < 20; i++ )
        printf("\n");
}

typedef struct {
    char pname [50];
    char symbol;
} player;

player p1, p2;
int mode = 0, spieler = 1;

int main() {
    p1.symbol = 'X';
    strcpy(p2.pname, "Computer");
    p2.symbol = 'O';
    printf("Tic Tac Toe / X vs O\n\n");
    printf("Bitte gib die gewünschte Spielmodi ein (1 = PvP, 2 = PvC):");
    scanf("%i", &mode);
    switch(mode){
        case 1:
            printf("\nSpielernamen eingeben\nSpieler 1 (X): ");
            scanf("%s", &*p1.pname);
            printf("Spieler 2 (O): ");
            scanf("%s", &*p2.pname);
            printf("\n%s gegen %s!\n", p1.pname, p2.pname);
            int zeile = 1, spalte = 1, count = 1;
            initBoard();
            printBoard();
            printf("\n%s beginnt. Bitte gib eine Zeile und eine Spalte ein: \n", p1.pname);
            while (checkIfWon() == 0){
                scanf("%d", &zeile);
                scanf("%d", &spalte);
                clearscr();
                if(zeile > 3 || spalte > 3){
                    printf("Die Position %d | %d existiert nicht.\n", zeile, spalte);
                    printBoard();
                    printf("\n%s, Bitte gib eine Zeile und eine Spalte ein: \n", p1.pname);
                    continue;
                }
                printf("---------------------------------------------------");
                if(checkField(zeile-1, spalte-1) == 1){
                    set(spieler, zeile-1, spalte-1);
                    printBoard();
                    if(checkIfWon() == 1){
                        break;
                    }
                    if(spieler == 0){
                        printf("\n%s, Bitte gib eine Zeile und eine Spalte ein: \n", p1.pname);
                    } else {
                        printf("\n%s, Bitte gib eine Zeile und eine Spalte ein: \n", p2.pname);
                    }
                } else {
                    printf("\nFalsche Eingabe, Feld ist belegt\n");
                    printBoard();
                    if(spieler == 0){
                        printf("\n%s, Bitte gib eine Zeile und eine Spalte ein: \n", p2.pname);
                    } else {
                        printf("\n%s, Bitte gib eine Zeile und eine Spalte ein: \n", p1.pname);
                    }
                    continue;
                }
                count++;
                spieler=(count)%2;
            }
            break;
        case 2:
            printf("Spielernamen eingeben:\n");
            scanf("%s", &*p1.pname);
            printf("\n%s gegen Computer!\n", p1.pname);
            initBoard();
            printBoard();
            printf("\n%s beginnt. Bitte gib eine Zeile und eine Spalte ein: \n", p1.pname);
            while(checkIfWon() == 0){
                scanf("%d", &zeile);
                scanf("%d", &spalte);
                clearscr();
                if(zeile > 3 || spalte > 3){
                    printf("Die Position %d | %d existiert nicht.\n", zeile, spalte);
                    printBoard();
                    printf("\n%s, Bitte gib eine Zeile und eine Spalte ein: \n", p1.pname);
                    continue;
                }
                printf("---------------------------------------------------");
                if(checkField(zeile-1, spalte-1) == 1){
                    set(spieler, zeile-1, spalte-1);
                    printBoard();
                    if(checkIfWon() == 1){
                        break;
                    }
                } else {
                    printf("\nFalsche Eingabe, Feld ist belegt\n");
                    printBoard();
                    printf("\n%s, Bitte gib eine Zeile und eine Spalte ein: \n", p1.pname);
                    continue;
                }
                printf("---------------------------------------------------\nComputer move:");
                compmove();
                printBoard();
                if(checkIfWon() == 1){
                    break;
                }
                printf("\n%s, Bitte gib eine Zeile und eine Spalte ein: \n", p1.pname);
            }
            break;
    }
    return 0;
}

void initBoard(void){
    int i, j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            matrix[i][j] = ' ';
        }
    }
}

void printBoard(void){
    int t;
    printf("\n");
    for(t = 0; t < 3; t++) {
        printf(" %c | %c | %c ", matrix[t][0], matrix[t][1], matrix [t][2]);
        if(t != 2){
            printf("\n---|---|---\n");
        }
    }
    printf("\n");
}

int checkField(int x, int y){
    if(matrix[x][y] == ' '){
        return 1;
    } else {
        return 0;
    }
}

void set(int player, int x, int y){
    switch (player) {
        case 0:
            matrix[x][y] = p2.symbol;
            break;
        case 1:
            matrix[x][y] = p1.symbol;
            break;
    }
}

int checkIfWon(){ // ergänzen mit Parameter
    int i, j, count1 = 0, count2 = 0, count0 = 9, won = 0;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if((matrix[i][j] == p1.symbol && i == j) || ((matrix[0][j] == p1.symbol) && (matrix[1][j] == p1.symbol) && (matrix[2][j] == p1.symbol)) || ((matrix[j][0] == p1.symbol) && (matrix[j][1] == p1.symbol) && (matrix[j][2] == p1.symbol)) || ((matrix[0][2] == p1.symbol) && (matrix[1][1] == p1.symbol) && (matrix[2][0] == p1.symbol))){
                count1++;
                if(count1 == 3){
                    printf("\n%s hat gewonnen!\n", p1.pname);
                    won = 1;
                    break;
                }
            } else if((matrix[i][j] == p2.symbol && i == j) || ((matrix[0][j] == p2.symbol) && (matrix[1][j] == p2.symbol) && (matrix[2][j] == p2.symbol)) || ((matrix[j][0] == p2.symbol) && (matrix[j][1] == p2.symbol) && (matrix[j][2] == p2.symbol)) || ((matrix[0][2] == p2.symbol) && (matrix[1][1] == p2.symbol) && (matrix[2][0] == p2.symbol))){
                count2++;
                switch (count2){
                    case 3:
                        printf("\n%s hat gewonnen!\n", p2.pname);
                        won = 1;
                        break;
                }
            }
            if(matrix[i][j] != ' '){
                count0--;
            }
            if(count0 == 0){
                printf("\nUnentschieden!\n");
                won = 1;
                break;
            }
        }
    }
    return won;
}

void compmove(){
    srand((int)time(NULL)); /* Initialisierung */
    rand();
    int r1 = 1+(int)(3.0*rand()/(RAND_MAX+1.0)), r2 = 1+(int)(3.0*rand()/(RAND_MAX+1.0));
    while(checkField(r1, r2) == 0){
        r1 = 1+(int)(3.0*rand()/(RAND_MAX+1.0));
        r2 = 1+(int)(3.0*rand()/(RAND_MAX+1.0));
    }
    matrix[r1][r2] = p2.symbol;
}
