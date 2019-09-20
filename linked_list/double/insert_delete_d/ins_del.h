/***************************************/
/* Author	: Jeevanandham P S     */
/* Date		: 20-sep-2019          */
/* Filename	: ins_del.h	       */
/* Description	: header files         */
/***************************************/

#ifndef INS_DEL_H
#define INS_DEL_H


/* Included header files */

#include <stdio.h>
#include <stdlib.h>
 
/* Macro Definitions */

#define COLOR	"\x1b[33m"
#define RESET	"\x1b[0m"
#define RED	"\x1b[31m"

/* function prototypes */

void print();

void ins_fir();
void ins_las();
void ins_mid();

void del_fir();
void del_mid();
void del_las();


/* user defined datatype definitions */

struct node
{
	struct node *prev;
	int data;
	struct node *next;
};

#endif //INS_DEL_H
