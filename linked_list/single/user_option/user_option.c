/***************************************/
/* Author	: Jeevanandham P S     */
/* Date		: 15-05-2020           */
/* Filename	: user_option.c	       */
/* Description	: single linked list   */
/***************************************/

#include "user_option.h"


struct database *head = NULL;


int main()
{
	int option;


	while(1){
		printf("Please enter your option\n1.Add New Data\n2.Print Database\n3.exit\n");
		scanf("%d",&option);
	
		switch (option){
			case 1:
				add();
				break;
			case 2:
				print();
				break;
			case 3:
				exit(0);
			default:
				printf("Invalid option\n");
				break;
		}
	}
}

void add()
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
	}
	else{
		while(ptr != NULL)
		{
			ret = strcmp(temp->name, ptr->name);

			printf("%d\n",ret);
			if(ret == 0){
				printf("Member already exist\n");
				break;
			}
			else if( ret > 0) {
				if(ptr->next == NULL){
					ptr->next = temp;
					break;
				}
				else{
					prev_ptr = ptr;
					ptr = ptr->next;
				}
			}
			else if(ret < 0){
				if(ptr == head){
					temp->next = head;
					head = temp;
					break;
				}
				else{
					prev_ptr->next = temp;
					temp->next = ptr;
					break;
				}
			}
		}
	}

}

void print()
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
