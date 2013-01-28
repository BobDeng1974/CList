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
	tNode *begin; //Endereço do primeiro elemento da lista
	tNode *end; //Endereço do último elemento ADICIONADO na lista
	int size; //Contém tamanho da lista
} List;


// Inicialização/remoção de Lista
List* initList();
void freeList(List *L);
int clearList(List *L);
void releaseNodes(List *L);

// Informações da Lista
int listSize(List *L);
int cmpList(List *L1, List *L2);
int isListElement(List *L, tNode *cmpNode);

// Manipulação de valores
tNode* findElement(List *L, char c);
int addElement(List *L, char c);
int removeElement(List *L, char c);

// Manipulação de Node
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