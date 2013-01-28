#include <stdlib.h>
#include <stdio.h>
#include "List.h"

/*
1. Inicializar uma string vazia;
2. Criar uma string S a partir de uma string S1 fornecida, ou seja, no final S1 = S;
3. Verificar se 2 strings S1 e S2 são idênticas;
4. Contar o numero de palavras de uma string S fornecida;
5. Inverter uma string S, ou seja, trocar a ordem de suas letras;
6. Combinar 2 strings S1 e S2 fornecidas, gerando uma string nova string S3 = S1 + S2,
ou seja, S3 é formada por todos os elementos de S1 seguidos de todos os elementos
de S2;
7. Intercalar 2 strings S1 e S2 fornecidas, gerando uma nova string S3 formada pela s
palavras de S1 misturadas (em ordem) com as palavras de S2;
8. Inverter as palavras de uma string S fornecida, ou seja, trocar a ordem das palavras da
string;
9. Inverter cada palavra de uma string S fornecida, ou seja, as palavras aparecem na
mesma ordem, porém escritas ao contrário.
*/

void printList(List *L)
{
	tNode *node;
	
	if(!L || !L->begin)
		return;

	node = L->begin;

	do 
	{
		printf("%c", node->data);
		node = node->next;
	} while(node);
}


void readString(List *L)
{
	char c;

	while(1)
	{
		scanf("%c", &c);
		if(c == '\n') break;

		//Backspace
		if(c == 10)
		{
			removeNode(L, L->end);
			continue;
		}
		addElement(L, c);
	}
	addElement(L, '\0');
} 



void main()
{
	//1. Inicializar string vazia;

	List *S1 = initList(), *S2 = initList(), *S3 = initList();
	printf("1. Inicializar string vazia.\n");

	//2. Criar uma string S2 a partir de uma string S1 fornecida, ou seja, no final S2 = S1;
	printf("2. Criar uma string S2 a partir de uma string S1 fornecida, ou seja, no final S2 = S1.\n\n");
	printf("(S1) Digite uma string qualquer: ");
	readString(S1);
	S2 = copyList(S1);
	printf("\n(S2) A string copiada de S1, ou seja, S2 tem os dados: ");
	printList(S2);

	// Limpa as List S1 e S2
	clearList(S1);
	clearList(S2);
	printf("\n\n ---------- \n\n");
	

	//3. Verificar se 2 strings S1 e S2 são idênticas;
	printf("3. Verificar se 2 strings S1 e S2 sao identicas.\n\n");
	printf("Digite a String S1: ");
	readString(S1);
	printf("\nDigite a String S2: ");
	readString(S2);
	
	if(cmpList(S1, S2))
		printf("S1 == S2.\n");
	else
		printf("S1 != S2.\n");

	// Limpa as List S e S1
	clearList(S1);
	clearList(S2);
	printList(S1);
	printf("\n\n ---------- \n\n");
	
	//4. Contar o numero de palavras de uma string S fornecida;
	printf("4. Contar o numero de palavras de uma string S fornecida.\n\n");
	printf("Digite uma string para contar as palavras: ");
	readString(S1);
	printf("A String tem %i palavras.", countWordsInString(S1));

	// Limpa a List S1
	clearList(S1);	
	printf("\n\n ---------- \n\n");

	//5. Inverter uma string S, ou seja, trocar a ordem de suas letras
	printf("5. Inverter uma string S, ou seja, trocar a ordem de suas letras.\n\n");
	printf("Digite uma String para ser invertida: ");
	readString(S1);
	invertList(S1);
	printf("\nA string invertida: ");
	printList(S1);

	clearList(S1);	
	printf("\n\n ---------- \n\n");
	

	//6. Combinar 2 strings S1 e S2 fornecidas, gerando uma string nova string S3 = S1 + S2,
	//ou seja, S3 é formada por todos os elementos de S1 seguidos de todos os elementos de S2.
	printf("6. Combinar 2 strings S1 e S2 fornecidas, gerando uma string nova string S3 = S1 + S2,");
	printf("ou seja, S3 é formada por todos os elementos de S1 seguidos de todos os elementos de S2.\n\n");
	printf("Digite a string S1: ");
	readString(S1);
	printf("\nDigite a string S2: ");
	readString(S2);
	S3 = concatList(S1, S2);
	printf("\nS1+S2, S3: ");
	printList(S3);

	clearList(S1);
	clearList(S2);
	clearList(S3);
	printf("\n\n ---------- \n\n");
	
	//printascii(255);
	//printf("\n\n\n\n\n\n\n");

	//7. Intercalar 2 strings S1 e S2 fornecidas, gerando uma nova string S3 formada pelas
	//palavras de S1 misturadas (em ordem) com as palavras de S2;
	printf("7. Intercalar 2 strings S1 e S2 fornecidas, gerando uma nova string S3 formada pelas ");
	printf("palavras de S1 misturadas (em ordem) com as palavras de S2.\n\n");
	printf("Digite a String S1: ");
	readString(S1);
	printf("\nDigite a String S2: ");
	readString(S2);
	printf("\nA mistura de S1 e S2 (em ordem), S3: ");
	S3 = intersperseString(S1, S2);
	printList(S3);
	
	printf("\n\n================");
	printf("Criado por Guilherme Silva de Souza\n");
	printf("================");
/*
	Não finalizado devido a bugs que não consegui resolver a tempo! :P

	//8. Inverter as palavras de uma string S fornecida, ou seja, trocar a ordem das palavras da string.
	printf("8. Inverter as palavras de uma string S1 fornecida, ou seja, trocar a ordem das palavras da string.\n\n");
	printf("Digite a String S1: ");
	readString(S1);
	S2 = reverseWordsOrder(*S1);
	printList(S2);
	

	//9. Inverter cada palavra de uma string S fornecida, ou seja, as palavras aparecem na
	//mesma ordem, porém escritas ao contrário.
	printf("9. Inverter cada palavra de uma string S fornecida, ou seja, as palavras aparecem na mesma ordem, porém escritas ao contrário.\n\n");
	printf("Digite a String S1: ");
	readString(S1);
	reverseWordsOrder(S1);
	printList(S2);
*/
	readString(S1);
}