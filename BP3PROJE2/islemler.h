#ifndef ISLEMLER_H_
#define ISLEMLER_H_
//defined methods.
void arraySum(uint8_t *numberArray1, uint8_t *numberArray2, int size1, int size2);
int findSize(FILE *file);
void resultFile(uint8_t *result, int size);
void additionResult(FILE *file1, FILE *file2);
int isGreater(uint8_t *numberArray1, uint8_t *numberArray2, int size);
void arraySubtract(uint8_t *numberArray1, uint8_t *numberArray2, int size1, int size2);
void subtractionResult(FILE *file1, FILE *file2);
#endif