#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main()
{
	char **smallMat = (char **)malloc(sizeof(int)*COLUMNSSMALL*ROWSSMALL);
	char **bigMat = (char **)malloc(sizeof(int)*COLUMNSBIG*ROWSBIG);

	int countMax = -1;
	char charMax = NULL;

	inputMatrix(smallMat, ROWSSMALL, COLUMNSSMALL);
	inputMatrix(bigMat, ROWSBIG, COLUMNSBIG);

	printf("Res matrix:\n");
	count(bigMat, smallMat, &charMax, &countMax);
	printf("Small Matrix:\n");
	printMatrix(smallMat, ROWSSMALL, COLUMNSSMALL);
	printf("Big Matrix:\n");
	printMatrix(bigMat, ROWSBIG, COLUMNSBIG);

	if (charMax != NULL && countMax != -1 )
	printf("Most repetitive %c ....%d \n", charMax ,countMax);

	char str=NULL,str1=NULL,str2=NULL;
	str = makestring (smallMat);  /* validate call to makestring */

	printf ("string: %s\n", str);    /* output string */


     swap1(&str1, &str2);
     printf("str1 is %s, str2 is %s", str1, str2);
     getchar();

	return 0;
}
