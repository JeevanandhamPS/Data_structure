/***************************************/
/* Author	: Jeevanandham P S     */
/* Date		: 20-sep-2019          */
/* Filename	: ins_del.c	       */
/* Description	: insert & delete node */
/***************************************/


/* Included header file */

#include "ins_del.h"


/* Global variable definitions */

struct node *head	= NULL; //Header pointer(first node of the list)
struct node *printer	= NULL; 
struct node *last	= NULL;
struct node *mid	= NULL;
struct node *del	= NULL;



/* function definitions */

int main()
{
	int inp, opt;

	while(1)
	{
		
		/* Choose an option to progress */
		
		printf("\nPlease enter your choice\n\t 1.Insert\n\t 2.Delete\n\t 3.Exit\n\n\t\t\toption = ");
		
		scanf("%d", &inp); 
		
		printf("\n");

		/* If user enters 1 insert block will get a command to start a work & it will ask one more option to choose a place to insert new node */

		if(inp == 1)
		{
			printf("\tPlease enter your option for an insertion\n\t\t 1.Insert_First\n\t\t 2.Insert_Mid\n\t\t 3.Insert_Last\n\n\t\t\tinsert_option = ");
			scanf("%d", &opt);
	
			if(opt == 1)
				ins_fir();
			else if(opt == 2)
			{
				if(head == NULL)
					printf(RED"\nSorry node is empty, there is no middle place\n\n"RESET); //invalid option (with out middle place, user ask to insert in middle)
				else
					ins_mid();
			}
			else if(opt == 3)
				ins_las();
			else
				printf(RED"\nPlease enter the Valid option\n\n"RESET);
		}

		/* If user enters 2 the delete block will get command to start a work & it will ask one more option to choose a place */

		else if(inp == 2)
		{
			if(head == NULL)
			{
				printf(RED"Sorry node is empty, Please enter valid option\n"RESET);
				continue;
			}
		
			printf("\n\tPlease enter your option for deletion \n\t\t 1.Delete_First\n\t\t 2.Delete_mid\n\t\t 3.Delete_Last\n\t\t\toption = ");
			scanf("%d", &opt);

			if(opt == 1)
			{
				if(head == NULL)
					printf(RED"\nSorry node is empty, There is no option to delete, PLease Enter a valid option\n\n"RESET);
				else
					del_fir();
			}

			else if(opt == 2)
			{
				if(head == NULL)
					printf(RED"\nSorry node is empty, There is no option to delete, Please Enter a valid option\n\n"RESET);
				else
					del_mid();
			}

			else if(opt == 3)
			{
				if(head == NULL)
					printf(RED"\nSorry node is empty, There is no option to delete, Please enter a valid option\n\n"RESET);
				else
					del_las();
			}
		}

		else if(inp == 3)
		{
			printf("\n-------------------------------------------\n");
			printf("You exit from the process, The final list  ");
			print();
			exit (0);
		}

		else
		{
			printf(RED"\nSorry there is no option like, what you enter, Please enter a Valid option\n\n"RESET);
			print();
		}

		printf("-------------------------------------------\n");

	}
}

void print()
{

	if(head == NULL)
	{
		printf("is empty\n\n");
		return;
	}

	else
	{
		printf("Values are   ==>> ");

		printer = head;

		while(printer)
		{
			printf(COLOR"%d "RESET,printer->data);
			printer = printer->next;
		}

		printf("\n\n");
	}
}


void ins_fir()
{
	int inp_data;

	printf("\n\t\t\tPlease enter a value = ");
	scanf("%d",&inp_data);

	struct node *ptr = (struct node *)malloc(sizeof(struct node));

	/* Insert a node at first, make ptr's next node is head and make ptr as a head */

	ptr->data = inp_data;
	ptr->next = head;

	head = ptr;

	print();
}

void ins_las()
{
	int inp_data;
	printf("\n\t\t\tPlease enter a value = ");
	scanf("%d",&inp_data);

	struct node *ptr = (struct node *)malloc(sizeof(struct node));

	ptr->data = inp_data;
	ptr->next = NULL;


	/*If head is NULL make the new node as head because, that is empty node, else wait upto second last and make new node as current node's next */

	if(head == NULL)
		head = ptr;
	else
	{
		last = head;

		while(1)
		{
			if(last->next == NULL)
			{
				last->next = ptr;
				break;
			}

			last = last->next;
		}
	}
	print();
}

void ins_mid()
{
	int mid_place, inp_data, count = 0;

	struct node *ptr = (struct node *)malloc(sizeof(struct node));

	mid = head;

	/* To count the number of nodes present in the linked list */

	while(mid)
	{
		mid = mid->next;
		count++;
	}

	/* We can find the midplace by using count */

	mid_place = (count/2);

	/* if mid_place == 0, the count of the list is lessthen 1, so there is no way for mid place, indicate the user */

	if(mid_place == 0)
	{
		printf(RED"\nSorry no middle place is availabe, please enter valid option\n"RESET);
		return;
	}

	else
	{
		printf("\n\t\t\tPlease enter a value = ");
		scanf("%d",&inp_data);

		ptr->data = inp_data;
		
		count = 0;

		mid = head;
		
		/* Wait upto the mid place then insert the new node at the middle ... */

		while(1)
		{
			count++;

			if(count == mid_place)
			{
				ptr->next = mid->next;
				mid->next = ptr;
				break;
			}

			mid = mid->next;
		}
	}
	print();
}

void del_fir()
{
	
	/* Make a head's next as a head, the first node will delete from the node */

	head = head->next;
	print();
}

void del_mid()
{

	/* Find a mid place and delete the node */  

	int count = 0, mid_place;

	mid = head;
	
	/* We can find the midplace by using count */

	while(mid)
	{
		mid = mid->next;
		count++;
	}

	mid_place = count/2;

	/* if mid_place == 0, the count of the list is lessthen 1, so there is no way for mid place, indicate the user */
	
	if(mid_place < 2)
	{
		printf(RED"\nSorry no middle place is availabe, please enter valid option\n"RESET);
		return;
	}

	count = 0;

	mid = head;

	while(1)
	{
		count++;
		
		/* Wait upto the mid place then delete the node ... */

		if(count == mid_place)
		{
			mid->next = mid->next->next;
			break;
		}

		mid = mid->next;
	}
	print();
}

void del_las()
{
	del = head;

	/* if list as only one node, make head is NULL */

	if(del->next == NULL)
		head = NULL;
	else
	{	
		/* Wait upto last third node make the current node's next is NULL */

		while(1)
		{
			if(del->next->next == NULL)
			{
				del->next = NULL;
				break;
			}
			del = del->next;
		}
	}
	print();
}
