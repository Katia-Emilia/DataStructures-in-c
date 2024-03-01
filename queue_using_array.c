#include<stdio.h>
#include<conio.h>
# define MAX 5
int queue_arr[MAX];
int front=-1,rear=-1;
void Enqueue(int item); //declaration
void dequeue();
void peek();
int isEmpty();
int isFull();
void display();
int main()     
{ 
        int choice,element;
        while(1){
               
                printf("\n MENU");
                printf("\n 1.Enqueue an element into queue");
                printf("\n 2.dequeue an element out of queue");

				 printf("\n 3.Display front element");
				  printf("\n 4.Display all queue elements");
				
                printf("\n--------------------------------------");
                printf("Enter your choice:\t");
                scanf("%d",&choice);
                switch(choice)
                {
						case 1:         printf("\nEnter element to be inserted:\n");
										scanf("%d",&element);
                                        Enqueue(element); //function call
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
  



void Enqueue(int element)
{
	if(isFull())
	{
		printf("\n queue overflow\n");
		return;
	}
	if(front==-1||rear==-1)
	{
		front=rear=0;
		queue_arr[rear]=element;
	}
	else
	{
		rear=rear+1;
		queue_arr[rear]=element;
	}
	
	printf("\n Element added successfully\n");
}

void dequeue()
{
	int element;
	if(isEmpty())
	{
		printf("\n queue underflow\n");
		return;
	}
	element=queue_arr[front];
	front=front+1;
	printf("\ndeleted element is:%d\n",element);
}

void peek()
{
	int element;
	if(isEmpty())
	{
		printf("\n queue underflow\n");
		return;
	}
		printf("\nelement present at the front of queue is:%d\n",queue_arr[front]);
}



int isEmpty()
{
	if(front==-1||front==rear+1)
	return 1;
	else
		return 0;
}

int isFull()
{
	if(rear==MAX-1)
	return 1;
	else
		return 0;
}
void display()
{
	int element,i;
	if(isEmpty())
	{
		printf("\n queue empty\n");
		return;
	}

	printf("queue elements:\n\n");
	for(i=front;i<=rear;i++)
	printf("%d\n",queue_arr[i]);

	printf("\n");
}

