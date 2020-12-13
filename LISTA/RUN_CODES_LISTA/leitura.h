#ifndef LEITURA_H
#define LEITURA_H

char *readString(int size);
int stringToInteger(char *string);
int countWords(char *string);
char* getWorldString(char* string, int index, int count_words);
void clearString(char* string);

#endif