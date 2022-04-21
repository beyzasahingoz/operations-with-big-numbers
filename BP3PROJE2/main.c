#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include "islemler.h"
int main()
{
    //defined variables.
    char selection;
    bool control = true;
    char sayi1, sayi2, num;
    //print menu selections.
    printf("*****************************************\n");
    printf("Mathematical Operations with Large Numbers\n");
    printf("*****************************************\n");
    //defined files and open with mode r.
    FILE *file1 = fopen("sayi1.1.txt", "r");
    FILE *file2 = fopen("sayi2.1.txt", "r");
    FILE *resultFile = fopen("resultproject.txt", "r");
    //made controls.
    while (control)
    {
        printf("\n1- Print numbers\n");
        printf("2- Choose your operation (+)\n");
        printf("3- Choose your operation (-)\n");
        printf("4- Print the result\n");
        printf("5- Exit\nEnter your selection:");
        scanf(" %c", &selection);

        if (selection == '5')
        {
            //close the files. end of the program.
            control = false;
            fclose(file1);
            fclose(file2);
            printf("..PROGRAM IS OVER..\n");
        }
        else if (selection == '1')
        {
            //calling printFiles method for print the files.
            printf("You choose 'print from file'\n");
            printFiles(&file1, "sayi1.1.txt");
            printf("\n\n");
            printFiles(&file2, "sayi2.1.txt");
        }
        else if (selection == '2')
        {
            //calling additionResult method for addition of the files.
            printf("\nYou choose '+ operations'\n");
            additionResult(file1, file2);
        }
        else if (selection == '3')
        {
            //calling subtractionResult method for subtraction of the files.
            printf("You choose '- operations'\n");
            subtractionResult(file1, file2);
        }
        else if (selection == '4')
        {
            //calling printFiles method for print the result.
            printf("You choose 'print the results'\n");
            printFiles(&resultFile, "resultproject.txt");
        }
        else
        {
            if (selection < '1' || selection > '5')
            {
                printf("WRONG!!! TRY AGAIN!\n");
            }
        }
    }

    return 0;
}