/***************************************/
/* Author	: Jeevanandham P S     */
/* Date		: 15-05-2020           */
/* Filename	: stack.c	       */
/* Description	: stack_single_list    */
/***************************************/

#include "stack.h"

struct database *head = NULL;

int stack_size;
int member = 0;

int main()
{
	int option;

	printf("Enter a stack Member\n");
	scanf("%d", &stack_size);

	while(1){
		printf("Please enter your option\n1.PUSH\n2.POP\n3.Display\n4.exit\n");
		scanf("%d",&option);
	
		switch (option){
			case 1:
				if(member == stack_size){
					printf("Stack is full, not able to add new member\n");
				}
				else{
					push();
				}
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
			default:
				printf("Invalid option\n");
				break;
		}
	}
}

void push()
{
	int ret;

	struct database *ptr = head;
	struct database *prev_ptr = NULL;

	struct database *temp = (struct database *)malloc(sizeof(struct database));

	printf("Enter details\n");
	scanf("%s",temp->name);	

	temp->next = NULL;

	if(head == NULL){
		head = temp;
		member++;
		return;
	}
	else{
		temp->next = head;
		head = temp;
		member++;
		return;
	}

}

void pop()
{
	if(head == NULL) {
		printf("Stack is an empty\n");
		return;
	}
	else {
		head = head->next;
		member--;
		return;
	}
}

void display()
{
	struct database *print_ptr = head;

	if(head == NULL){
		printf("List is Empty\n");
		return;
	}

	while(print_ptr != NULL){
		printf("%s\n",print_ptr->name);
		print_ptr = print_ptr->next;
	}
	return;
}
