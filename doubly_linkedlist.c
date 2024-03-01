#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node * head = NULL;
struct node
{
	int data;
	struct node* next;
	struct node *prev;
};
void insertatbeginning()
{
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	if (newnode == NULL)
		printf("Memory not allocated\n");
	else {
		printf("Enter element:");
		scanf_s("%d", &newnode->data);
		newnode->next = NULL;
		newnode->prev = NULL;
		if (head == NULL)//if list is empty
		{
			head = newnode;
		}
		else
		{
			newnode->next = head;
			head->prev = newnode;
			head = newnode;
		}
	}
}
void create()
{
	insertatbeginning();
}
void insertatend()
{
	struct node *newnode, *temp;
	newnode = (struct node*)malloc(sizeof(struct node));
	temp = head;
	newnode->next = NULL;
	printf("Enter element:");
	scanf_s("%d", &newnode->data);
	if (head == NULL)//if list is empty
	{
		head = newnode;
		newnode->prev = NULL;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		newnode->prev = temp;
		temp->next = newnode;
	}

}
void display()
{
	struct node*temp = head;
	if (head == NULL)
		printf("Empty list");
	else {
		while (temp != NULL)
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}
	}
}
void delbyval()
{
	int n;
	printf("\nValue to be deleted: ");
	scanf_s("%d", &n);
	struct node * temp = head;
	if (head == NULL)
		printf("Empty list");
	else if (temp->prev == NULL && temp->next==NULL)
	{
		head = NULL;
		free(temp);
	}
	else
	{
		while (temp != NULL)
		{
			if (temp->data == n)
			{
				if (temp->prev == NULL) {
					temp->next->prev = NULL;
					head = temp->next;
					free(temp);
					break;
				}
				else if (temp->next == NULL) {
					temp->prev->next = NULL;
					free(temp);
					break;
				}
				 
				else {
					temp->prev->next = temp->next;
					temp->next->prev=temp->prev;
					free(temp);
					break;
				}
			}
			else {
				temp = temp->next;
				if (temp == NULL) {
					printf("\nElement not found.\n");
					free(temp);
					break;
				}
			}

		}
		
	}
}
void main()
{

	int c = 0;
	while (c == 0)
	{
		int choice, f=0;
		printf("\nMenu\n");
		printf("\n1.Create");
		printf("\n2.Insert at beginning");
		printf("\n3.Insert at end");
		printf("\n4.Display");
		printf("\n5.Delete by value");
		printf("\n6.Exit\n");
		printf("\nEnter choice:");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			create();
			break;
		case 2:
			insertatbeginning();
			break;
		case 3:
			insertatend();
			break;
		case 4:
			display();
			break;
		case 5:
			delbyval();
			break;
		case 6:
			f = 1;
			break;
		default:
			printf("Invalid value entered.");
		}
		if (f == 1) 
			c = 1;
	}
	_getch();
}
