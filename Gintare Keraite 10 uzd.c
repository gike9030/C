//Gintare Keraite, 1k., 2grp.
/*Parasyti funkcija, kuri is duoto teksto ismeta zodzius,
sudarytus is nelyginio simboliu skaiciaus
(tarpu skaicius turi buti nepakites)*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void removeUneven(char *str, char *pathOut)
{
    char *token;
    int k = 0, spaceCntr = 0, wordCntr = 0;

    while(str[k] != '\n' && str[k] != '\0')
    {
        if(str[k] == ' ')
            spaceCntr++;
        k++;
    }
    FILE *fTemp;
    fTemp = fopen(pathOut, "a+");
    token = strtok(str, " \n");
    while(token != NULL)
    {
        if(strlen(token) % 2 == 0 )
            fputs(token, fTemp);
        wordCntr++;
        if(wordCntr <= spaceCntr)
            fputs(" ", fTemp);
        token = strtok(NULL, " \n");
    }
    fputs("\n", fTemp);
    fclose(fTemp);
}
void cleanBuffer(char *Text)
{
    printf("%s", Text);
    while(getchar() != '\n')
        ;
}
void checkTxt(char * path)
{
    int t = 1;
    while(t == 1)
        {
            if(scanf("%s", path) && path[(strlen(path)-1)] == 't' && path[strlen(path)-2] == 'x'&& path[strlen(path)-3] == 't'&& path[strlen(path)-4] == '.')
                --t;
            else
                cleanBuffer("Wrong input! File name has to end with .txt! Repeat input!\n");
        }
}
int argv_check(char * path, char * text, int *argc)
{
    int t = 0;
    while(t  < 2)
    {
        if(t == 0 && path[(strlen(path)-1)] == 't' && path[strlen(path)-2] == 'x'&& path[strlen(path)-3] == 't'&& path[strlen(path)-4] == '.')
            t = 2;
        else
        {
            t = 1;
            printf(text);
        }
        if(t == 1 && scanf("%s", path) && path[(strlen(path)-1)] == 't' && path[strlen(path)-2] == 'x'&& path[strlen(path)-3] == 't'&& path[strlen(path)-4] == '.')
            t = 2;
        else
            cleanBuffer(text);
    }
    *argc = 1;
}
void enterAgain(char * path, char * pathOut,int *argc, char *argv[])
{
    if(*argc == 1)
    {
        printf("Enter path of source file: ");
        checkTxt(path);
        printf("Enter path of output file: ");
        checkTxt(pathOut);
    }
    else
    {
        argv_check(argv[1], "Wrong input! Input file name has to end with .txt! Repeat input!\n", argc);
        strcpy(path, argv[1]);
        argv_check(argv[2], "Wrong input! Output file name has to end with .txt! Repeat input!\n", argc);
        strcpy(pathOut, argv[2]);
    }
}
void malloc_check(char *buffer, char *path, char *pathOut)
{
    if (buffer == NULL || path == NULL || pathOut == NULL)
    {
	printf("Error with malloc\n");
	exit(1);
    }

}
int main(int argc, char *argv[])
{
    FILE *fTemp;
    FILE * fPtr;
    char * path = (char*)malloc(sizeof(char) * 20);
    char * pathOut = (char*)malloc(sizeof(char) * 20);
    char * buffer = (char*)malloc(sizeof(char) * BUFFER_SIZE);
    malloc_check(buffer, path, pathOut);
    enterAgain(path, pathOut, &argc, argv);
    fPtr = fopen(path, "r");
    fTemp = fopen(pathOut, "w");
    fclose(fPtr);
    fclose(fTemp);
    while(fPtr == NULL || fTemp == NULL)
    {
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        cleanBuffer("Repeat input...\n");
        remove(pathOut);
        remove(path);
        enterAgain(path, pathOut, &argc, argv);
        fPtr = fopen(path, "r");
        fTemp = fopen(pathOut, "w");
        fclose(fPtr);
        fclose(fTemp);
    }
    fPtr = fopen(path, "r");
    fTemp = fopen(pathOut, "w");
    while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL)
        removeUneven(buffer, pathOut);

    fclose(fPtr);
    fclose(fTemp);
    free(path);
    free(pathOut);
    free(buffer);
    return 0;
}


