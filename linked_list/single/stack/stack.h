/***************************************/
/* Author	: Jeevanandham P S     */
/* Date		: 15-05-2020           */
/* Filename	: stack.h	       */
/* Description	: header files         */
/***************************************/

#ifndef STACK_H
#define STACK_H

/* Included header files */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/* function prototypes */

void push();
void pop();
void display();

/* user defined datatype definitions */

struct database{
	int roll_num;
	char name[10];
	struct database *next;
};

#endif //SATCK_H
