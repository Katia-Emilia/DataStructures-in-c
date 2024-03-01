

#include<stdio.h>
#include<conio.h>
# define MAX 5
int stack_arr[MAX];
int top=-1;
void push()
{
	int element;
	if(top==MAX-1)
	{
		printf("\n stack overflow\n");
	}
	else
	{
		printf("\nEnter element to be pushed:\n");
		scanf("%d",&element);
	top=top+1;
	stack_arr[top]=element;
	printf("\n Element added successfully\n");
	}
}
void pop()
{
	if(top==-1)
	{
		printf("\n stack underflow\n");
	}
	else
	{
	top=top-1;
	printf("\nelement deleted");
	}
}

void peek()
{
	if(top==-1)
	{
		printf("\n stack underflow\n");
	}
	else
		printf("\nelement present at the top of stack is:%d\n",stack_arr[top]);
}
void display()
{
	int i;
	if(top==-1)
	{
		printf("\n stack underflow\n");
	}
	else
	{
		printf("Stack elements:\n\n");
	for(i=top;i>=0;i--)
	printf("%d\n",stack_arr[i]); 
	}
	
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
  






