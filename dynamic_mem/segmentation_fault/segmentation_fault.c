/***********************************************/
/* Author	: Jeevandham PS                */
/* Date		: 26-mar-2018                  */
/* Filename	: segmentation_fault.c         */
/* Description	: check the segmentation fault */
/***********************************************/

/* Included header file */
#include "seg_f.h"

/* Global variable definitions */


/* function definitions */

int main()
{
	char *str = (char *)malloc(10); //allocate 10 bytes memory

	while(1)
	{
		printf("%c",*str);
		printf("%p\n",str);
		str++;
	}
}
