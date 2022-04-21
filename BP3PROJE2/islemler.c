#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#include "islemler.h"
//defined resultf file.
FILE *resultf;
//with this method, calculated the sum of the two numbers from the file.
void arraySum(uint8_t *numberArray1, uint8_t *numberArray2, int size1, int size2)
{
    //defined variables and result array.
    int carry = 0, s = 0;
    uint8_t *result = (uint8_t *)malloc((size1 + 1) * sizeof(uint8_t));
    int i = size1 - 1, j = size2 - 1, k = size1;
    while (j >= 0)
    {
        s = *(numberArray1 + i) + *(numberArray2 + j);
        if (s > 9)
        {
            //taking mode of s.
            *(result + k) = (s % 10);
            s = 1;
        }
        else
        {
            *(result + k) = s;
            s = 0;
        }
        k--;
        j--;
        i--;
    }
    while (i >= 0)
    {
        if (s == 1)
        {
            *(result + k) = *(numberArray1 + i) + 1;
            s = 0;
        }
        else
        {
            *(result + k) = *(numberArray1 + i);
        }
        i--;
        k--;
    }
    while (k >= 0)
    {
        *(result + k) = s;
        k--;
    }

    for (i = 0; i < size1 + 1; i++)
    {
        printf("%d", *(result + i));
    }
    printf("\n");
    resultFile(result, size1 + 1);
    free(numberArray1);
    free(numberArray2);
    free(result);
}
void arraySubtract(uint8_t *numberArray1, uint8_t *numberArray2, int size1, int size2)
{
    //defined variables and result array.
    int carry = 0;
    uint8_t *result = (uint8_t *)malloc((size1) * sizeof(uint8_t));
    int i = size1 - 1, j = size2 - 1;
    while (j >= 0)
    {
        int d = 0;
        uint8_t s = (i >= 0 ? *(numberArray1 + i) : 0);
        if (*(numberArray2 + j) > *(numberArray1 + i))
        {
            s = 10 + *(numberArray1 + i) - *(numberArray2 + j);
            carry = 1;
        }
        else
        {
            s = *(numberArray1 + i) - *(numberArray2 + j);
        }
        if (carry == 1)
        {
            if (*(numberArray1 + i - 1) == 0)
            {
                *(numberArray1 + i - 1) = 9;
                carry = 1;
            }
            else
            {
                *(numberArray1 + i - 1) -= 1;
                carry = 0;
            }
        }
        *(result + i) = s;
        i--;
        j--;
    }
    while (i >= 0)
    {
        if (carry == 1)
        {
            if (*(numberArray1 + i - 1) == 0)
            {
                *(numberArray1 + i - 1) = 9;
                carry = 1;
            }
            else
            {
                *(numberArray1 + i - 1) -= 1;
                carry = 0;
            }
        }
        *(result + i) = *(numberArray1 + i);
        i--;
    }
    for (i = 0; i < size1; i++)
    {
        printf("%d", *(result + i));
    }
    resultFile(result, size1);
    free(numberArray1);
    free(numberArray2);
    free(result);
}
//found file size.
int findSize(FILE *file)
{
    //if isgraph is true, blank++ and return blank;
    int a, blank = 0, count = 0;
    if (file)
        do
        {
            a = fgetc(file);
            if (isgraph(a))
            {
                blank++;
            }
        } while (a != EOF);

    return blank;
}
void subtractionResult(FILE *file1, FILE *file2)
{
    //found files sizes.
    int file1Size = findSize(file1);
    int file2Size = findSize(file2);
    //rewind the files.
    rewind(file1);
    rewind(file2);
    //defined arrays.
    uint8_t *numberArray1 = (uint8_t *)malloc(file1Size * sizeof(uint8_t));
    uint8_t *numberArray2 = (uint8_t *)malloc(file2Size * sizeof(uint8_t));
    int i = 0, j = 0;
    //added array from file.
    while ((i < file1Size) && !(feof(file1)))
    {
        char c = fgetc(file1);
        if (c != '\n')
        {
            *(numberArray1 + i) = c - '0';
            i++;
        }
    }
    i = 0;
    while ((i < file2Size) && !(feof(file2)))
    {
        char c = fgetc(file2);
        if (c != '\n')
        {
            *(numberArray2 + i) = c - '0';
            i++;
        }
    }
    //printed files and result.
    printf("***NUMBER 1***\n");
    for (i = 0; i < file1Size; i++)
    {
        printf("%d", *(numberArray1 + i));
    }
    printf("\n***NUMBER 2***\n");
    for (i = 0; i < file2Size; i++)
    {
        printf("%d", *(numberArray2 + i));
    }
    printf("\n***SUBTRACTION OF NUMBERS***\n");
    if (file1Size > file2Size)
    {
        (arraySubtract(numberArray1, numberArray2, file1Size, file2Size));
    }
    else if (file1Size == file2Size)
    {
        int bigNum = isGreater(numberArray1, numberArray2, file1Size);
        if (bigNum == 0)
        {
            (arraySubtract(numberArray1, numberArray2, file1Size, file2Size));
        }
        else
        {
            (arraySubtract(numberArray2, numberArray1, file2Size, file1Size));
        }
    }
    else
    {
        (arraySubtract(numberArray2, numberArray1, file2Size, file1Size));
    }
}
void additionResult(FILE *file1, FILE *file2)
{
    //found files sizes.
    int file1Size = findSize(file1);
    int file2Size = findSize(file2);
    //rewind the files.
    rewind(file1);
    rewind(file2);
    //defined arrays.
    uint8_t *numberArray1 = (uint8_t *)malloc(file1Size * sizeof(uint8_t));
    uint8_t *numberArray2 = (uint8_t *)malloc(file2Size * sizeof(uint8_t));
    int i = 0, j = 0;
    //added array from file.
    while ((i < file1Size) && !(feof(file1)))
    {
        char c = fgetc(file1);
        if (c != '\n')
        {
            *(numberArray1 + i) = c - '0';
            i++;
        }
    }
    i = 0;
    while ((i < file2Size) && !(feof(file2)))
    {
        char c = fgetc(file2);
        if (c != '\n')
        {
            *(numberArray2 + i) = c - '0';
            i++;
        }
    }
    //printed numbers and result.
    printf("***NUMBER 1***\n");
    for (i = 0; i < file1Size; i++)
    {
        printf("%d", *(numberArray1 + i));
    }
    printf("\n***NUMBER 2***\n");
    for (i = 0; i < file2Size; i++)
    {
        printf("%d", *(numberArray2 + i));
    }
    printf("\n***SUMMATION OF NUMBERS***\n");
    if (file1Size >= file2Size)
        (arraySum(numberArray1, numberArray2, file1Size, file2Size));

    else
        (arraySum(numberArray2, numberArray1, file2Size, file1Size));
}
//calculated which number is bigger.
int isGreater(uint8_t *numberArray1, uint8_t *numberArray2, int size)
{
    int bigNum;
    for (int i = 0; i < size; i++)
    {

        //if array2 bigger than array1 big num=1
        if (*(numberArray1 + i) - *(numberArray2 + i) < 0)
        {
            bigNum = 1;
            break;
        }
        //if array1 bigger than array2 big num=0
        else if (*(numberArray2 + i) - *(numberArray1 + i) < 0)
        {
            bigNum = 0;
            break;
        }
    }
    return bigNum;
}
void resultFile(uint8_t *result, int size)
{
    //adding result to resultproject.txt file and print.
    char num;
    int i;
    resultf = fopen("resultproject.txt", "w");
    if (resultf == NULL)
    {
        printf("\nNo file is here!\n");
    }
    else
    {
        printf("\nFile is found!\n");
        for (i = 0; i < size; i++)
        {
            fprintf(resultf, "%d", *(result + i));
        }
    }
    fclose(resultf);
}
void printFiles(FILE **file, char *num)
{
    *file = fopen(num, "r");
    //print files.
    if (*file == NULL)
    {
        printf("No file is here\n");
    }
    else
    {
        while (!feof(*file))
        {
            char c = fgetc(*file);
            printf("%c", c);
        }
    }
    fclose(*file);
}