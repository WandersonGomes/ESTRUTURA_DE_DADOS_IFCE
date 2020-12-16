#ifndef LIST_H
#define LIST_H

typedef struct list List;

//create
List* createList();

//inserts
int insertStartList(List* list, int data);
int insertEndList(List* list, int data);
int insertSortList(List* list, int data);
int insertIndexList(List* list, int index, int data);

//consults
int isEmptyList(List* list);
int startList(List* list);
int endList(List* list);
int dataIndexList(List* list, int index);
int sizeList(List* list);

//remove
int removeStartList(List* list);
int removeEndList(List* list);
int removeDataList(List* list, int data);
int removeAllDataList(List* list, int data);
int removeDataIndexList(List* list, int index);

//clear
int clearList(List* list);

//print
int printList(List* list);

//destroy
int destroyList(List* list);

//additional
int maxDataList(List* list);
int minDataList(List* list);
int countLargerDataList(List* list, int data);

//challenge
List* mergeList(List* list1, List* list2);
int reverseList(List* list);
int convertListToCircular(List* list);
int reverseListCircularRecursive(List* list);

#endif