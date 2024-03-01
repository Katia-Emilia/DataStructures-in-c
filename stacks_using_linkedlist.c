#include <stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
        int data;
        struct node *next;
};
struct node *top=NULL;
void push()
{
        struct node *newnode;
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->next=NULL;
        printf("\nEnter the data value for the node:" );
        scanf("%d",&newnode->data);
		if(newnode==NULL)
		{
			printf("unable to allocate memory!!!!!!!");
		}
		else
		{

			   if(top==NULL)
        {
              top=newnode;
        }
		else
		{
			  newnode->next=top;
	          top=newnode;
		}
			printf("\n Element added successfully\n");
		}
     
}

void pop()
{
	   struct node *ptr;
		int element;
		if(top==NULL)
		{
			printf("\n stack underflow\n");
		
		}
		else
		{
        ptr=top;
        top=top->next ;
		printf("\nThe deleted element is :%d\t",ptr->data);
        free(ptr);
		}
	
}
void peek()
{
	int element;
	if(isEmpty())
	{
		printf("\n No elements to display\n");
		return;
	}
	printf("\nelement present at the top  of stack is:%d\n",top->data);
}
int isEmpty()
{
	if(top==NULL)
	return 1;
	else
		return 0;
}
void display()
{
        struct node *ptr;
		
         ptr=top;
		if(top==NULL)
		{
			printf("\n No elements to display\n");
			return;
		}
		
                 printf("Nodes in linked list:");
                while(ptr!=NULL)
                {
                        printf("%d ->   ",ptr->data );
                        ptr=ptr->next ;
                }
				 printf("\n");
}


int main()     
{
        int choice,element;
        while(1){
                printf("\n MENU");
                printf("\n 1.Push an element into stack");
                printf("\n 2.Pop an element out of stack");

				 printf("\n 3.Display top element");
				  printf("\n 4.Display all stack elements");
				
                printf("\n--------------------------------------");
                printf("Enter your choice:\t");
                scanf("%d",&choice);
                switch(choice)
                {
						case 1:         
                                        push(); //function call
										break;
                        case 2:
                                        pop(); //function call
									
										break;

						case 3:
                                      peek(); //function call
										
										break;

						case 4:
                                        display(); //function call
										break;
           
                             
                        default:
                                        printf("n Wrong Choice:");
                                        break;
        }
		
 }
		getch();
        return 0;
}


