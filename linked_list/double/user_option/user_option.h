/***************************************/
/* Author	: Jeevanandham P S     */
/* Date		: 15-05-2020           */
/* Filename	: user_option.h	       */
/* Description	: header files         */
/***************************************/

#ifndef USER_OPTION_H
#define USER_OPTION_H

/* Included header files */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


/* function prototypes */

void add();
void print();

/* user defined datatype definitions */

struct database{
	int roll_num;
	char name[10];
	struct database *next;
	struct database *prev;
};

#endif //USER_OPTION_H
