all: programa

programa: main.o aluno.o
	gcc -o programa main.o aluno.o && rm main.o aluno.o

main.o: main.c aluno.h
	gcc -o main.o -c main.c

aluno.o: aluno.c aluno.h
	gcc -o aluno.o -c aluno.c
