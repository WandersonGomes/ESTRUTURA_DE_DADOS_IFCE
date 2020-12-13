#ifndef LISTA_H
#define LISTA_H

typedef struct list List;

List* createList();
int insertList(List* list, int);
int insertSortList(List* list, int);
int insertIndexList(List* list, int data, int index);
int removeValueElementList(List* list, int data); 
int maxList(List* list); 
int lastList(List* list); 
int firsttList(List* list);
int countLargerElementList(List* list, int data);
int sizeList(List* list);
int isEmptyList(List* list);
int printList(List* list);
int clearList(List* list);
int emptyList(List* list);

#endif