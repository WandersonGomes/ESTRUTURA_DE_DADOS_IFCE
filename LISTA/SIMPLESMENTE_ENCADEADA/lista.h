#ifndef LISTA_H
#define LISTA_H

typedef struct list List;

//create
List* createList(); 

//inserts
int insertStartList(List* list, int data);
int insertEndList(List* list, int data);
int insertIndexList(List* list, int index, int data);
int insertSortList(List* list, int data);

//consults
int isEmptyList(List* list);
int getStartList(List* list);
int getEndList(List* list);
int getSizeList(List* list);
int getElementIndexList(List* list, int index);
int getIndexElementList(List* list, int data);

//removes
int removeElementStartList(List* list);
int removeElementIndexList(List* list, int index);
int removeDataList(List* list, int data);

//print
int printList(List* list);

//destroy
int destroyList(List* list);
int emptyList(List* list);

//additional
int maxValueList(List* list);
int countGreatValueList(List* list, int data);

#endif