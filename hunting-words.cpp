#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>

#define MAX 10

void menu();
void findWord();

char matrix[10][10], prevWord[MAX], currentWord[MAX];
int size = 0, found = 0;

void printMatrix() {
	
	int charCol, charLin;
	
	system("cls");
	system("color 07");
	
	printf("\t");
	
	for (charCol = 0; charCol < MAX; charCol++) {
		
		printf("%d ", charCol);
		
	} 
	
	printf("\n\t");
	
	for (charLin = 0; charLin < MAX; charLin++) {
		
		printf("  ", charLin);
		
	}
	
	printf("\n");
	
	for (int j = 0; j < MAX; j++) {
		
		printf("  %d -> ", j);
		printf(" ");
		
		for (int k = 0; k < MAX; k++) {
			
			printf("%c ", matrix[j][k]);
			
		}
		
		printf("\n");
		
	}
	
	printf("\n");
	system("pause");
	menu();
	
}

void gridMatrix() {
	
	matrix[0][0] = 'q'; matrix[0][1] = 's'; matrix[0][2] = 'v'; matrix[0][3] = 'r'; matrix[0][4] = 'b'; matrix[0][5] = 'j'; matrix[0][6] = 'x'; matrix[0][7] = 'e'; matrix[0][8] = 'd'; matrix[0][9] = 'o'; 
	matrix[1][0] = 'd'; matrix[1][1] = 'd'; matrix[1][2] = 'i'; matrix[1][3] = 'u'; matrix[1][4] = 'n'; matrix[1][5] = 'k'; matrix[1][6] = 't'; matrix[1][7] = 'd'; matrix[1][8] = 'g'; matrix[1][9] = 'v'; 
	matrix[2][0] = 'g'; matrix[2][1] = 'j'; matrix[2][2] = 't'; matrix[2][3] = 'i'; matrix[2][4] = 'k'; matrix[2][5] = 'g'; matrix[2][6] = 'r'; matrix[2][7] = 'f'; matrix[2][8] = 'h'; matrix[2][9] = 'r'; 
	matrix[3][0] = 't'; matrix[3][1] = 'c'; matrix[3][2] = 'o'; matrix[3][3] = 'l'; matrix[3][4] = 'o'; matrix[3][5] = 's'; matrix[3][6] = 's'; matrix[3][7] = 'a'; matrix[3][8] = 'l'; matrix[3][9] = 'o'; 
	matrix[4][0] = 'i'; matrix[4][1] = 'd'; matrix[4][2] = 'r'; matrix[4][3] = 'p'; matrix[4][4] = 'm'; matrix[4][5] = 'f'; matrix[4][6] = 'f'; matrix[4][7] = 's'; matrix[4][8] = 'u'; matrix[4][9] = 'c'; 
	matrix[5][0] = 's'; matrix[5][1] = 'h'; matrix[5][2] = 'i'; matrix[5][3] = 'u'; matrix[5][4] = 'l'; matrix[5][5] = 'l'; matrix[5][6] = 's'; matrix[5][7] = 'd'; matrix[5][8] = 'e'; matrix[5][9] = 'd'; 
	matrix[6][0] = 'd'; matrix[6][1] = 'j'; matrix[6][2] = 'a'; matrix[6][3] = 'm'; matrix[6][4] = 'o'; matrix[6][5] = 'r'; matrix[6][6] = 'i'; matrix[6][7] = 'j'; matrix[6][8] = 'w'; matrix[6][9] = 'f'; 
	matrix[7][0] = 'f'; matrix[7][1] = 'f'; matrix[7][2] = 'f'; matrix[7][3] = 't'; matrix[7][4] = 'd'; matrix[7][5] = 'a'; matrix[7][6] = 'p'; matrix[7][7] = 'e'; matrix[7][8] = 'c'; matrix[7][9] = 'd'; 
	matrix[8][0] = 'q'; matrix[8][1] = 'k'; matrix[8][2] = 'k'; matrix[8][3] = 'r'; matrix[8][4] = 's'; matrix[8][5] = 'd'; matrix[8][6] = 'w'; matrix[8][7] = 'y'; matrix[8][8] = 'v'; matrix[8][9] = 'r'; 
	matrix[9][0] = 'w'; matrix[9][1] = 'l'; matrix[9][2] = 'g'; matrix[9][3] = 'z'; matrix[9][4] = 't'; matrix[9][5] = 'a'; matrix[9][6] = 'r'; matrix[9][7] = 't'; matrix[9][8] = 'e'; matrix[9][9] = 't';
	printMatrix();
	
}

void left_right(char currentWord[]) {
	
	int l1, c1;
	
	system("cls");
	
	int notFound = 1;
	
	size = strlen(currentWord);
	
	for (l1 = 0; l1 < MAX; l1++) {
		
		for (c1 = 0; c1 < MAX; c1++) {
			
			int count = 0;
			
			while (matrix[l1][c1 + count] == currentWord[count] && matrix[c1][c1 + count] != '\0' && count != size && c1 != MAX) {
				
				count++;
				
					if (count == size) {
					
					system("color 20");
					
					printf("\t|\n");
					printf("\t|\n");
					printf("\t|_-Palavra [%s] Encontrada!", currentWord);
					printf(" \n |\n |\n |\n |_-Linha: %d", l1);
					printf("\n    Coluna: %d", c1);
					found++;
					notFound--;
					
					if (found == 5) {
						
						system("cls");
						system("color 20");
						
						printf("+-----------------------------------------------------------------------------+\n");
						printf("|                         VOCÊ ACHOU TODAS AS PALAVRAS!                       |\n");
						printf("+-----------------------------------------------------------------------------+\n");
						
						exit(1);
						
					}
					
					printf("\n\n");
					system("pause");
					gridMatrix();
					system("cls");
					
				}	
				
			}
			
		}
		
	}
	
	if (notFound == 0) {
		
		system("cls");
		system("color 47");
		
		printf("\t|\n");
		printf("\t|\n");
		printf("\t|_-[404] Palavra Não Encontrada!\n\n");
		system("pause");
		menu();
		
	}
	
}

void right_left(char currentWord[]) {
	
	int l2, c2;
	
	system("cls");
	
	int notFound = 0;
	
	size = strlen(currentWord);
	
	for (l2 = 0; l2 < MAX; l2++) {
		
		for (c2 = MAX - 1; c2 > -1; c2--) {
			
			int count = 0;
			
			while (matrix[l2][c2 - count] == currentWord[count] && count != size && c2 != -1) {
				
				count++;
				if (count == size) {
					
					system("color 20");
					
					printf("\t|\n");
					printf("\t|\n");
					printf("\t|_-Palavra [%s] Encontrada!", currentWord);
					printf(" \n |\n |\n |\n |_-Linha: %d", l2);
					printf("\n    Coluna: %d", c2);
					found++;
					notFound--;
					
					if (found == 5) {
						
						system("cls");
						system("color 20");
						
						printf("+-----------------------------------------------------------------------------+\n");
						printf("|                         VOCÊ ACHOU TODAS AS PALAVRAS!                       |\n");
						printf("+-----------------------------------------------------------------------------+\n");
						
						exit(1);
						
					}
					
					printf("\n\n");
					system("pause");
					gridMatrix();
					system("cls");
					
				}
				
			}
			
		}
		
	}
	
	if (notFound == 0) {
		
		system("cls");
		system("color 47");
		
		printf("\t|\n");
		printf("\t|\n");
		printf("\t|_-[404] Palavra Não Encontrada!\n\n");
		system("pause");
		menu();
		
	}
	
}

void up_down(char currentWord[]) {
	
	int l3, c3;
	
	system("cls");
	
	int notFound = 0;
	
	size = strlen(currentWord);
	
	for (c3 = 0; c3 < MAX; c3++) {
		
		for (l3 = 0; l3 < MAX; l3++) {
			
			int count = 0;
			
			while (matrix[l3 + count][c3] == currentWord[count] && matrix[l3 + count][c3] != '\0' && count != size && l3 != MAX) {
				
				count++;
				if (count == size) {
					
					system("color 20");
					
					printf("\t|\n");
					printf("\t|\n");
					printf("\t|_-Palavra [%s] Encontrada!", currentWord);
					printf(" \n |\n |\n |\n |_-Linha: %d", l3);
					printf("\n    Coluna: %d", c3);
					found++;
					notFound--;
					
					if (found == 5) {
						
						system("cls");
						system("color 20");
						
						printf("+-----------------------------------------------------------------------------+\n");
						printf("|                         VOCÊ ACHOU TODAS AS PALAVRAS!                       |\n");
						printf("+-----------------------------------------------------------------------------+\n");
						
						exit(1);
						
					}
					
					printf("\n\n");
					system("pause");
					gridMatrix();
					system("cls");
					
				}
				
			}
			
		}
		
	}
	
	if (notFound == 0) {
		
		system("cls");
		system("color 47");
		
		printf("\t|\n");
		printf("\t|\n");
		printf("\t|_-[404] Palavra Não Encontrada!\n\n");
		system("pause");
		menu();
		
	}
	
}

void down_up(char currentWord[]) {
	
	int l4, c4;
	
	system("cls");
	
	int notFound = 0;
	
	size = strlen(currentWord);
	
	for (c4 = 0; c4 < MAX; c4++) {
		
		for (l4 = MAX - 1; l4 > -1; l4--) {
			
			int count = 0;
			
			while (matrix[l4 - count][c4] == currentWord[count] && count != size && l4 != -1) {
				
				count++;
				if (count == size) {
					
					system("color 20");
					
					printf("\t|\n");
					printf("\t|\n");
					printf("\t|_-Palavra [%s] Encontrada!", currentWord);
					printf(" \n |\n |\n |\n |_-Linha: %d", l4);
					printf("\n    Coluna: %d", c4);
					found++;
					notFound--;
					
					if (found == 5) {
						
						system("cls");
						system("color 20");
						
						printf("+-----------------------------------------------------------------------------+\n");
						printf("|                         VOCÊ ACHOU TODAS AS PALAVRAS!                       |\n");
						printf("+-----------------------------------------------------------------------------+\n");
						
						exit(1);
						
					}
					
					printf("\n\n");
					system("pause");
					gridMatrix();
					system("cls");
					
				}
				
			}
			
		}
		
	}
	
	if (notFound == 0) {
		
		system("cls");
		system("color 47");
		
		printf("\t|\n");
		printf("\t|\n");
		printf("\t|_-[404] Palavra Não Encontrada!\n\n");
		system("pause");
		menu();
		
	}
	
}

void findWord() {
	
	int optFind;
	
	system("cls");
	system("color 07");
	
	printf("|--------------------------|\n");
	printf("\n");
	printf("| [1] Esquerda - Direita\n");
	printf("\n");
	printf("| [2] Direita - Esquerda\n");
	printf("\n");
	printf("| [3] De Cima - Para Baixo\n");
	printf("\n");
	printf("| [4] De Baixo - Para Cima\n");
	printf("\n");
	printf("| [0] Voltar ao Menu\n");
	printf("\n");
	printf("|--------------------------|\n");
	
	printf("|\n");
	printf("|__> Selecione a posição em que a palavra se encontra: ");
	scanf(" %d", &optFind);
	
	if (optFind == 0) {
		
		menu();
		
	} else {
		
		printf(" | \n");
		printf(" |__>Digite a palavra a ser encontrada: ");
		scanf(" %s", currentWord);
		
		if (strcmp(currentWord, prevWord) == 0) {
			
			printf("\n - Palavra [%s] repetida. Por favor, digite outra palavra.\n\n", currentWord);
			found--;
			system("pause");
			system("cls");
			findWord();
			
		}
		
		strcpy(prevWord, currentWord);
		
		switch(optFind) {
			
			case 1:
				left_right(currentWord);
				break;
				
			case 2:
				right_left(currentWord);
				break;
				
			case 3:
				up_down(currentWord);
				break;
				
			case 4:
				down_up(currentWord);
				break;
				
			case 0:
				printf("\n\n - Retornando ao menu...\n");
				system("pause");
				menu();
				
			default:
				system("cls");
				system("color 47");
				printf("[404] Option Not Found!\n\n");
				system("pause");
				menu();
				break;
			
		}
		
	}
	
}

void menu() {
	
	int opt;
	
	system("cls");
	system("color 07");
	
	printf("_________________________________________________\n");
	printf("|\t              MENU                    \t|\n");
	printf("|-----------------------------------------------|\n");
	printf("|\t[0] Sair                              \t|\n");
	printf("|\t[1] Caça-Palavras                     \t|\n");
	printf("|\t[2] Pesquisar Palavra                 \t|\n");
	printf("|-----------------------------------------------|\n");
	printf("|\n");
	printf("|______> ");
	scanf(" %d", &opt);
	
	switch(opt) {
		
		case 0:
			system("cls");
			system("color 70");
			printf("_________________________________________________\n");
			printf("|\t        VOLTE MAIS VEZES           \t|\n");
			printf("|-----------------------------------------------|\n");
			printf("|\t                                     \t|\n");
			printf("|\t                                     \t|\n");
			printf("|\t           BYE BYE :(                \t|\n");
			printf("|\t                                     \t|\n");
			printf("|\t                                     \t|\n");
			printf("|-----------------------------------------------|\n");
			exit(1);
			break;
		
		case 1:
			gridMatrix();
			break;
		
		case 2:
			findWord();
			break;
			
		default:
			system("cls");
			system("color 47");
			printf("[404] Option Not Found!");
			break;
		
	}
	
}

int main() {
	setlocale(LC_ALL, "portuguese");
	
	menu();
	
	return 0;
	
}
