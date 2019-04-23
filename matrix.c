#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

void printMatrix(char **matrix, int rows, int cols)
	{
		int i, j;

		for (i = 0; i < rows; i++)
		{
			for (j = 0; j < cols; j++)
			{
				// *(*(matrix + i) + j) is equivalent to matrix[i][j]
				printf("%c ", **(matrix));
				(*matrix) += sizeof(char);
			}
			matrix += sizeof(char);
			printf("\n");
		}
		printf("\n");
	}



	void count(char ** bigMat, char ** smallMat, char * charMax, int * countMax)
	{
		int **resMat, *resArr;
		char **tmpBigMat, **tmpSmallMat = smallMat;
		char *verticalBigMat, *verticalSmallMat;
		int *verticalResMat, **tmpResMat;
		char c;
		int counter;
		resMat = (int **)malloc(sizeof(int)*COLUMNSSMALL*ROWSSMALL);
		int **tempNewMat = resMat;
		int max = 0, imax, jmax;

		for (int i = 0; i < ROWSSMALL; i++)
		{
			verticalSmallMat = *tmpSmallMat;//location
			resArr = (int *)malloc(sizeof(int)*COLUMNSSMALL);
			for (int j = 0; j < COLUMNSSMALL; j++)
			{
				counter = 0;
				c = *verticalSmallMat;
				tmpBigMat = bigMat;
				for (int k = 0; k < ROWSBIG; k++) { //tmpBigMat[k][l]
					verticalBigMat = *tmpBigMat;//location
					for (int l = 0; l < COLUMNSBIG; l++) {
						if (*verticalBigMat == c) //info of ptr in location
							counter++;
						if (l != COLUMNSBIG - 1)
							verticalBigMat = (verticalBigMat)+sizeof(char); //++ to location
					}
					tmpBigMat = (tmpBigMat)+sizeof(char);//ptr reference next row
				}
				verticalSmallMat = (verticalSmallMat)+sizeof(char);
				*(resArr + j) = counter;
			}
			tmpSmallMat = (tmpSmallMat)+sizeof(char);
			{
				*(resMat + i) = resArr;
			}

			tmpResMat = resMat;
			for (int i = 0; i < ROWSSMALL; i++) {
				verticalResMat = *tmpResMat;
				for (int j = 0; j < COLUMNSSMALL; j++)
				{
					if (*verticalResMat >max)
					{
						max = *verticalResMat;
						imax = i;
						jmax = j;
					}
				}

			}

		}
		printMatrixInt(resMat, ROWSSMALL, COLUMNSSMALL);
		if (max == 0) //all the elements in the new matrix are zero
		{
			printf("Most repetitive:NO COMMON LETTERS(max=0)\n");
			charMax = NULL;
		}
		else
		{
			*charMax = *(*(smallMat + imax) + jmax);
		}
		*countMax = max;
	}

	void inputMatrix(char **mat, int rows, int cols)
	{
		int i, j;
		srand((int)time(NULL));
		for (i = 0; i < rows; i++)
		{
			char *temp = (char *)malloc(sizeof(char)*cols);
			for (j = 0; j < cols; j++)
			{
				*(temp + j) = 'A' + rand() % ('Z' - 'A' + 1);
			}
			*(mat + i) = temp;
		}
	}

	void printMatrixInt(int **matrix, int rows, int cols)
	{
		int i, j;
//		if (rows == ROWSBIG && cols == COLUMNSBIG)
//			printf("Big Matrix:\n");
//		else
//			printf("Small Matrix:\n");

		for (i = 0; i < rows; i++)
		{
			for (j = 0; j < cols; j++)
			{
				// *(*(matrix + i) + j) is equivalent to matrix[i][j]
				printf("%d ", **(matrix));
				(*matrix) += sizeof(char);
			}
			matrix += sizeof(char);
			printf("\n");
		}
		printf("\n");
	}


char *makestring (char **charMatrix)
{
    char *str = (char *)malloc (sizeof(char)* SIZE + SIZE-1);
    char *p = *str;
    for (int i = 0; i < SIZE; i++) {
        if (i==SIZE-1)
            *p++ = ' ';
        for (int j = 0; j < SIZE; j++)
            *p++ = *(*(charMatrix + i) + j);
    }
    *p = 0;
    return *str;
}


// char allocbuf[SIZE * (SIZE + 1)]
//
//char *MakeString(){
//	char *str = (char *)(malloc (SIZE * SIZE + SIZE-1));
//    for (int i = 0; i < SIZE; i++) {
//        memcpy(allocbuf + i * SIZE, matrix + i, SIZE);
//        if (i < SIZE - 1) {
//            // write space between rows
//            *(allocbuf + i * SIZE + SIZE) = ' ';
//        } else {
//            // write null at end
//            *(allocbuf + i * SIZE + SIZE) = 0;
//        }
//    }
//    return allocbuf;
//}

void swap1(char **str1_ptr, char **str2_ptr)
{
  char *temp = *str1_ptr;
  *str1_ptr = *str2_ptr;
  *str2_ptr = temp;
}

