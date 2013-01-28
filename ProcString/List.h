#ifndef DEFINED_LIST
#define DEFINED_LIST

typedef struct Node
{
	unsigned char data;
	struct Node *next;
	struct Node *previous;
} tNode;

typedef struct
{
	tNode *begin; //Endere�o do primeiro elemento da lista
	tNode *end; //Endere�o do �ltimo elemento ADICIONADO na lista
	int size; //Cont�m tamanho da lista
} List;


// Inicializa��o/remo��o de Lista
List* initList();
void freeList(List *L);
int clearList(List *L);
void releaseNodes(List *L);

// Informa��es da Lista
int listSize(List *L);
int cmpList(List *L1, List *L2);
int isListElement(List *L, tNode *cmpNode);

// Manipula��o de valores
tNode* findElement(List *L, char c);
int addElement(List *L, char c);
int removeElement(List *L, char c);

// Manipula��o de Node
int addNode(List *L, tNode *node);
int removeNode(List *L, tNode *node);
List* copyList(List *srcList);
void invertList(List *L);

// Strings
List* findString(List *L, char *str);
int removeString(List *L, char *str);
int countWordsInString(List *L);
List* concatList(List *L1, List* L2);
List* intersperseString(List *L1, List *L2);
List** splitList(List *L, char separator);
//List* reverseWordsOrder(List L);

#endif