/****************************************/
/* Author	: Jeevanandham P S      */
/* Date		: 15-05-2020            */
/* Filename	: queue.c	        */
/* Description	: Queue with linked list*/
/****************************************/

#include "queue.h"

struct database *head = NULL;

int queue_size;
int member = 0;

int main()
{
	int option;

	printf("Enter a stack Member\n");
	scanf("%d", &queue_size);

	while(1){
		printf("Please enter your option\n1.Enqueue\n2.Dequeue\n3.Display\n4.exit\n");
		scanf("%d",&option);
	
		switch (option){
			case 1:
				if(member == queue_size){
					printf("Stack is full, not able to add new member\n");
				}
				else{
					enqueue();
				}
				break;
			case 2:
				dequeue();
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

void enqueue()
{
	int ret;

	struct database *ptr = head;

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
		while(ptr->next != NULL){
			ptr = ptr->next;
		}
		ptr->next = temp;
		member++;
		return;
	}

}

void dequeue()
{
	if(head == NULL) {
		printf("Queue is an empty\n");
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
		printf("Queue is an Empty\n");
		return;
	}

	while(print_ptr != NULL){
		printf("%s\n",print_ptr->name);
		print_ptr = print_ptr->next;
	}
	return;
}
