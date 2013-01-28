/*
Criado por Guilherme Silva de Souza
guilherme.sdes@gmail.com / guilhermesouza@dcc.ufba.br
Sistemas de informa��o, UFBA
*/
#include <stdlib.h>
#include <stdio.h>
#include "List.h"


// ***********************************************
// ******  initList                         ******
// ***********************************************
// Inicializa a Lista alocando um espa�o na mem�ria
// e definine configura��es iniciais.
// Retorna o ponteira da Lista alocada.
List* initList()
{
	List *L = (List*) malloc(sizeof(List));

	//Realiza as defini��es iniciais
	L->begin = NULL;
	L->end = NULL;
	L->size = 0;

	return L;
}
// ***********************************************
// ******  freeList                         ******
// ***********************************************
// Libera a mem�ria ocupada pela Lista.
void freeList(List *L)
{
	clearList(L);
	// Apaga a Lista e define seu valor ponteiro NULL
	free(L);
	L = NULL;
}
// ***********************************************
// ******  clearList                        ******
// ***********************************************
// Apaga os nodes da Lista e retorna a quantidade 
// de elementos apagados.
int clearList(List *L)
{
	tNode *currentNodeToRemove, *nextNodeToRemove;
	int i = 0;

	// Lista n�o existe
	if(!L) 
		return 0;

	currentNodeToRemove = L->begin;
	nextNodeToRemove = currentNodeToRemove->next;

	// Remove todos os tNode da Lista
	while(currentNodeToRemove)
	{
		nextNodeToRemove = currentNodeToRemove->next;
		free(currentNodeToRemove);
		currentNodeToRemove = nextNodeToRemove;
		i++;
	}

	L->begin = NULL;
	L->end = NULL;
	L->size = 0;

	return i;
}
// ***********************************************
// ******  releaseNodes                     ******
// ***********************************************
// Desassocia os Nodes da lista.
void releaseNodes(List *L)
{
	L->begin = NULL;
	L->end = NULL;
	L->size = 0;
}
// ***********************************************
// ******  listSize                         ******
// ***********************************************
// Retorna o tamanho da lista
int listSize(List *L)
{
	return L->size;
}
// ***********************************************
// ******  cmpList                          ******
// ***********************************************
// Compara duas List, L1 e L2, e retorna 1 se 
// iguais, sen�o retorna 0.
int cmpList(List *L1, List *L2)
{
	tNode *node1, *node2;

	// Verifica se as listas existem
	if(!L1 || !L2)
		return 0;

	node1 = L1->begin;
	node2 = L2->begin;

	do 
	{
		// Verifica se os elementos s�o iguais neste ciclo.
		if(node1->data != node2->data)
			return 0;

		// Define os pr�ximos elementos do ciclo.
		node1 = node1->next;
		node2 = node2->next;
	} while(node1 != NULL || node2 != NULL);

	// L1 e L2 s�o iguais.
	return 1;
}
// ***********************************************
// ******  copyList                         ******
// ***********************************************
// Retorna uma c�pia da lista passada.
List* copyList(List *srcList)
{
	List *newList = initList();
	tNode *node = srcList->begin;

	do
	{
		addElement(newList, node->data);
		node = node->next;
	} while(node != NULL);

	return newList;
}
// ***********************************************
// ******  buscaElemento                    ******
// Busca um Elemento na lista passada.
// Se encontrado � retornado o endere�o de mem�ria
// do elemento, caso contr�rio o valor NULL �
// retornado.
// ***********************************************
tNode* findElement(List *L, char c)
{
	tNode *node = L->begin;

	// Lista vazia
	if(node == NULL) return 0;

	//Varre a lista a procura de um elemento com data == c
	do
	{
		if(node->data == c)
			return node;
		else
			node = node->next; // Define o pr�ximo elemento a ser lido
	} while(node != NULL);

	return NULL; // Nenhum elemento encontrado
}
// ***********************************************
// ******  addElement                   ******
// ***********************************************
// Verifica se o Node passado pertence a Lista
// Retorna 1 se encontrado dentro da Lista e 0
// caso contr�rio.
int isListElement(List *L, tNode *cmpNode)
{
	tNode *node = L->begin;

	// Lista vazia ou Node passado � NULL
	if(!node || !cmpNode) return 0;

	//Varre a lista a procura de um tNode igual ao passado no argumento
	do
	{
		if(node == cmpNode)
			return 1;
		else
			node = node->next; // Define o pr�ximo elemento a ser lido
	} while(!node);

	return 0; // Elemento n�o est� na lista
}
// ***********************************************
// ******  addElement                       ******
// ***********************************************
// Adiciona um elemento na lista.
int addElement(List *L, char c)
{
	tNode *node;


	if(!L)
		return 0;

	// Verifica se h� espa�o na mem�ria para alocar o tNode
	// E aloca-o caso haja.
	if(!(node = (tNode*) malloc(sizeof(tNode))))
		return 0;

	node->data = c;
	node->next = NULL;
	node->previous = NULL;

	// Verifica se a lista est� vazia
	if(L->begin == NULL)
	{
		L->begin = node;
		L->end = node;
	}
	else // Caso contr�rio adiciona normalmente
	{
		node->previous = L->end;
		L->end->next = node;
		L->end = node;
	}

	// Aumenta o tamanho da lista em 1
	L->size++;

	return 1;
}
// ***********************************************
// ******  addNode                          ******
// ***********************************************
// Adiciona um tNode na lista.
int addNode(List *L, tNode *node)
{
	// Verifica se o elemento passado � igual a NULL,
	// se sim, n�o h� necessidade de continuar.
	if(!L || !node)
		return 0;

	// Verifica se a lista est� vazia
	if(L->begin == NULL)
	{
		L->begin = node;
		L->end = node;
	}
	else
	{
		node->previous = L->end;
		L->end->next = node;
		L->end = node;
	}

	L->size++;

	return 1;
}
// ***********************************************
// ******  removeElemento                   ******
// ***********************************************
// Procura um elemento e remove-o da lista.
// Se encontrado e removido � retornado 1, caso
// contr�rio � retonado 0.
int removeElement(List *L, char c)
{
	tNode *node = findElement(L, c);

	//Nenhum elemento encontrado para remo��o
	if(!node) return 0; // Nenhum elemento removido

	// Verifica se existe somente 1 elemento na lsita
	if(node == L->begin && node == L->end)
	{
		// Torna a lista vazia
		L->begin = NULL;
		L->end = NULL;
		L->size = 0;
	}
	// Verifica se o elemento a ser removido � o primeiro da lista
	else if(node == L->begin)
	{
		// Remove o elemento e coloca outro como primeiro elemento da lista
		L->begin->next->previous = NULL;
		L->begin = L->begin->next;
		L->size--;
	}
	// Verifica se o elemento a ser removido � o �ltimo da lista
	else if(node == L->end)
	{
		// Remove o elemento e coloca outro como �ltimo elemento da lista
		L->end->previous->next = NULL;
		L->end = L->end->previous;
		L->size--;
	}
	// Remove o elemento normalmente
	else
	{
		node->previous->next = node->next;
		node->next->previous = node->previous;
		L->size--;
	}

	free(node);
	return 1; // Elemento removido com sucesso
}
// ***********************************************
// ******  removeNode                       ******
// ***********************************************
// Remove um tNode da lista.
int removeNode(List *L, tNode *node)
{
	//Elemento NULL
	if(!node) return 0;


	if(node == L->begin && node == L->end)
	{
		L->begin = NULL;
		L->end = NULL;
		L->size--;
	}
	else if(node == L->begin)
	{

		L->begin->next->previous = NULL;
		L->begin = L->begin->next;
		L->size--;
	}
	else if(node == L->end)
	{
		L->end->previous->next = NULL;
		L->end = L->end->previous;
		L->size--;
	}
	else
	{
		node->previous->next = node->next;
		node->next->previous = node->previous;
		L->size--;
	}

	free(node);

	return 1;
}
// ***********************************************
// ******  invertList                       ******
// ***********************************************
void invertList(List *L)
{
	tNode *node = L->end, *aux_node = NULL;

	do
	{
		aux_node = node->previous;
		node->previous = node->next;
		node->next = aux_node;

		// node->previous tornou-se node->next na troca.
		node = node->next;
	} while(node);

	aux_node = L->begin;
	L->begin = L->end;
	L->end = aux_node;
}
// ***********************************************
// ******  concatList                       ******
// ***********************************************
List* concatList(List *L1, List* L2)
{
	tNode *node;
	List *L3 = initList();

	if(!L1 || !L2)
		return NULL;

	// Copia os elementos de L1 para L3.
	node = L1->begin;
	while(node)
	{
		addElement(L3, node->data);
		node = node->next;
	} 

	// Copia os elementos de L2 para L3.
	node = L2->begin;
	while(node)
	{
		addElement(L3, node->data);
		node = node->next;
	} 

	return L3;
}



// ******************************
//            STRING
// ******************************

// ***********************************************
// ******  findString                       ******
// ***********************************************
// Retorna um List com os tNode de char encontrado.
// Nota: Os tNode do List* retornado s�o os mesmo da
// lista passada, ou seja, possuem a mesma refer�ncia
// (endere�o de mem�ria) dos tNode pertencentes a 
// List que a string foi buscada.
List* findString(List *L, char *str)
{
	List *subList = initList();
	tNode *node = L->begin;
	int i = 0, pointsFound = 0, strSize = sizeof(str);

	// Varre o List procurando a String
	do
	{
		// Compara a data do tNode atual com os caracteres da String.
		// Ex: Se encontrado o primeiro caractere da string, checa-se no
		//     pr�ximo ciclo o segundo caractere da string com o pr�ximo
		//     tNode e assim por diante.
		if(node->data == *(str + i))
		{
			i++; // Aumenta o indice para que o pr�ximo char da string seja comparado.
			pointsFound++; // Sinaliza a quantidade de compara��es de sucesso.
			addNode(subList, node); // Adiciona o caractere a nova *List para retorno posterior.

			// Verifica se a String chegou no final, caso sim
			// retorna um novo *List com os *tNode da antiga Lista,
			// isso permite manipular uma parte especifica da antiga List com uma nova List. (um tipo de parti��o)
			if(pointsFound == strSize)
				return subList; 
		}
		// Zera os valores pois n�o � a String procurada.
		else
		{
			// Faz uma checagem para evitar processamento desceness�rio.
			if(subList->size)
			{
				i = 0;
				pointsFound = 0;

				// N�o poderia usar uma fun��o para limpar *subList pois
				// isso iria agir diretamente em *L, por tanto, basta
				// limpar as refer�ncias do *subList e zerar o tamanho.
				L->begin = NULL;
				L->end = NULL;
				L->size = 0;
			}
		}
		// Define o pr�ximo tNode a ser comparado.
		node = node->next;

	} while(node);

	// A String procurada n�o fora encontrada.
	return NULL;
}
// ***********************************************
// ******  removeString                     ******
// ***********************************************
// Remove a primeira string encontrada.
int removeString(List *L, char *str)
{
	List *strToRemove;
	tNode *node, *nextNode = NULL;

	// String n�o encontrada para remo��o
	if(!(strToRemove = findString(L, str)))
		return 0;

	node = strToRemove->begin;

	// Remove a string da Lista
	do
	{
		nextNode = node->next;
		removeNode(L, node);
		node = nextNode;

		// Necess�rio verificar o pr�ximo tNode, caso contr�rio n�o removeria o �ltimo elemento.
	} while(node->next != strToRemove->end->next); 

	return 1; // String removida com sucesso
}
// ***********************************************
// ******  countWordsInString               ******
// ***********************************************
int countWordsInString(List *L)
{
	tNode *node = L->begin;
	int counter = 0, isWord = 0;

	do
	{
		// Optei por n�o tratar palavras como 'super-homem' em raz�o de acreditar n�o ser necess�rio
		// neste trabalho. Por tanto, o programa h� de considerar 'super-homem' como duas palavras
		// e n�o somente uma. Considero tamb�m que a lingua em quest�o � o portugu�s, palavras como
		// "it's" ser�o consideradas como duas palavras.
		// Outro problema not�rio seria uma string "a b c d e", considerada como 5 palavras neste c�digo,
		// para o portugu�s isto estaria incorreto. Escolhi ent�o por n�o tratar este problema em raz�o de 
		// supor a correta escrita do portugu�s no input.

		// 128~165 caracteres especiais.. �, �, �, etc.
		if((node->data >= 'a' && node->data <= 'z') || (node->data >= 'A' && node->data <= 'Z') || node->data >= 128 && node->data <= 165 || node->data == 231)
		{
			if(!isWord) 
			{	
				isWord = 1;
				counter++;
			}
		}
		else
		{
			isWord = 0;
		}
		node = node->next;
	} while(node);

	return counter;
}
// ***********************************************
// ******  intersperseString                ******
// ***********************************************
List* intersperseString(List *L1, List *L2)
{
	List *L3;
	tNode *node = NULL, *nodeL1 = NULL, *nodeL2 = NULL;
	int currentList, bugFix = 0;

	// Verifica se as duas Listas existem, caso n�o retorna NULL.
	if(!L1 || !L2)
		return NULL;

	// Faz as defini��es necess�rias para o do-while.
	L3  = initList();
	nodeL1 = L1->begin;
	nodeL2 = L2->begin;
	node = nodeL1;
	currentList = 0;

	do
	{
		// Adiciona o elemento em L3.
		addElement(L3, node->data);

		// Realiza a troca de qual Lista estar� sendo escrita em L3 no ciclo.
		if(node->data == ' ')
		{
			currentList = (currentList ? 0 : 1);
		}

		if(!currentList)
		{
			//Evita que um elemento NULL seja adicionado.
			if(nodeL1->next)
			{
				// Define o pr�ximo elemento
				nodeL1 = nodeL1->next;
				node = nodeL1;	
			}
			else
			{
				// Define o pr�ximo elemento
				nodeL2 = nodeL2->next;
				node = nodeL2;
			}
		}
		else
		{
			// bugFix evita que o primeiro caractere de L2 seja pulado.
			if(!bugFix)
			{
				addElement(L3, nodeL2->data);
				bugFix = 1;
			}

			// Evita que um elemento NULL seja adicionado.
			if(nodeL2->next)
			{
				// Define o pr�ximo elemento
				nodeL2 = nodeL2->next;
				node = nodeL2;
			}
			else
			{
				// Define o pr�ximo elemento
				nodeL1 = nodeL1->next;
				node = nodeL1;
			}
		}
	} while(node);

	return L3;
}
// ***********************************************
// ******  shredList                        ******
// ***********************************************
List** splitList(List *L, char separator)
{
	List **splittedLists;
	tNode *node;
	int i = 0;

	if(!L)
		return NULL;

	splittedLists = (List**) calloc(countWordsInString(L), sizeof(List*));
	splittedLists[i] = initList();
	node = L->begin;

	printf("[");
	while(node)
	{
		if(node->data == separator)
		{
			splittedLists[++i] = initList();
			printf("][");
			node = node->next;
			continue;
		}

		addElement(splittedLists[i], node->data);
		printf("%c", node->data);
		node = node->next;
	}
	printf("]\n");
	return splittedLists;
}
/*
// ***********************************************
// ******  reverseWordsOrder                ******
// ***********************************************
List* reverseWordsOrder(List *L)
{
	List **splittedLists, *reversedList;
	tNode *firstNode, *lastNode;
	int i, j, wordsNumber;

	if(!L.begin)
		return;

	reversedList = initList();
	// Conta as palavras da string.
	wordsNumber = countWordsInString(&L);
	// Inverte a string
	//invertList(&L);
	// Cria novas List contendo somente as palavras. (Divide a string por espa�os)
	splittedLists = splitList(&L, ' ');


	for(i = 0; i < wordsNumber; i++)
	{
		invertList(splittedLists[i]);
		reversedList = concatList(reversedList, splittedLists[i]);
	}

	return reversedList;
}

*/