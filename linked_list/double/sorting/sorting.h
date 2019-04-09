/***************************************/
/* Author	: Jeevanandham PS      */
/* Date		: 9-apr-2019           */
/* Filename	: sorting.h            */
/* Description	: header files         */
/***************************************/

#ifndef SORTING_H
#define SORTING_H

/* Included header files */

#include <stdio.h>
#include <stdlib.h>


/*function prototypes*/

void ins(int, char *);
void print_list();
void arrange();

/* Macro Definitions */


/* user defined datatype definitions */

struct node
{
	struct node *prev;
	int reg;
	char *name;
	struct node *next;
};

#endif //SORTING_H
