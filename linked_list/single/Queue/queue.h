/***************************************/
/* Author	: Jeevanandham P S     */
/* Date		: 15-05-2020           */
/* Filename	: queue.h	       */
/* Description	: header files         */
/***************************************/

#ifndef QUEUE_H
#define QUEUE_H

/* Included header files */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


/* function prototypes */

void enqueue();
void dequeue();
void display();

/* user defined datatype definitions */

struct database{
	int roll_num;
	char name[10];
	struct database *next;
};

#endif //QUEUE_H
