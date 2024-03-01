#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
int isEmpty()
{
	if(front==NULL)
	return 1;
	else
		return 0;
}
void enqueue()
{
        struct node *newnode;
        newnode=(struct node *)malloc(sizeof(struct node));
	  	if(newnode==NULL)
		{
			printf("memory not allocated");
		}
		else
		{

        newnode->next=NULL;
        printf("\nEnter the data value for the node:" );
        scanf("%d",&newnode->data);
		newnode->next=NULL;
        if(front==NULL)
		{
			 front=newnode;
			 rear=newnode;
		    
		}
		else
		{
			rear->next=newnode;
			rear=newnode;
			

		}
		
		
			printf("\n Element added successfully\n");
              }
}

void dequeue()
{
	   struct node *temp;
		int element;
		if(front==NULL)
		{
			printf("\n queue underflow\n");
			
		}
		else
		{
			temp=front;
			if(front->next==NULL)
			{
			  front=NULL;
			  rear=NULL;
			}
			else
			{
				front=front->next;
			}
		printf("\nThe deleted element is :%d\t",temp->data);
        free(temp);
		}
	
}
void peek()
{
	int element;
	if(isEmpty())
	{
		printf("\n No elements to display\n");
		
	}
	else
	{
		printf("\nelement present at the front of queue is:%d\n",front->data);
	}
	
}

void display()
{
        struct node *temp;
		
         temp=front;
		if(front==NULL)
		{
			printf("\n No elements to display\n");
			
		}
		else
		{
			  printf("Nodes in queue:");
                while(temp!=NULL)
                {
                        printf("%d ->   ",temp->data );
                        temp=temp->next ;
                }
				 printf("\n");
		}    
}



int main()     
{
        int choice,element;
        while(1){
                printf("\n MENU");
                printf("\n 1.enqueue an element into queue");
                printf("\n 2.dequeue an element out of queue");

				 printf("\n 3.Display front element");
				  printf("\n 4.Display all queue elements");
				
                printf("\n--------------------------------------");
                printf("Enter your choice:\t");
                scanf("%d",&choice);
                switch(choice)
                {
						case 1:         
                                        enqueue(); //function call
										break;
                        case 2:
                                        dequeue(); //function call
									
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


