/***********************************************/
/* Author	: Jeevanandham PS              */
/* Date		: 9-apr-2019                   */
/* Filename	: insert.c                     */
/* Description	: sigle linked list sorting    */
/***********************************************/


/* Included header file */

#include "insert.h"

/* Global variable definitions */

struct node *print = NULL;
struct node *head = NULL;
struct node *start = NULL;

int lmt;

/* function definitions */
int main()
{
	printf("Enter the number of nodes\n");
	scanf("%d",&lmt); // get number of nodes from the user

	int r_no[lmt],c; //roll numbers  
	char s_name[lmt][15]; // names, max 15 characters

	for(c=0; c<lmt; c++) //get the input for all nodes from the user
		scanf("%d%s",&r_no[c],s_name[c]);

	for(c=0; c<lmt; c++) // store the values to the structure pointer
		ins(r_no[c], s_name[c]);
	printf("\n");

	printf("\n-----After Insertion------\n");
	print_list();
}

void ins(int num, char *nme)
{
	static int i=0;
	struct node *ptr = (struct node *)malloc(sizeof(struct node));

	//first value store to the head..
	if(i==0)
	{
		ptr->reg = num;
		ptr->name = nme;
		head = ptr;
		start = head;
		i++;
	}

	//other than first value all are stored one by one..
	else
	{
		ptr->reg = num;
		ptr->name = nme;
		start->next = ptr;
		start = start->next;
	}
}

//print function..
void print_list()
{
	print = head; 
	while(print != NULL)
	{
		printf("%d %s\n",print->reg,print->name);
		print = print->next;
	}
}
