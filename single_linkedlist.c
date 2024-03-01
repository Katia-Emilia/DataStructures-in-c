#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();
void deletepos();
 
struct node
{
        int data;
        struct node *next;
};
struct node *head=NULL;
int main()     
{
        int choice;
        while(1){
               
                printf("\n MENU");
                printf("\n 1.Create");
                printf("\n 2.Display");
                printf("\n 3.Insert at the beginning");
                printf("\n 4.Insert at the end");
                printf("\n 5.Insert at specified position");
                printf("\n 6.Delete from beginning");
                printf("\n 7.Delete from the end");
                printf("\n 8.Delete from specified position");
                printf("\n 9.Exit");
                printf("\n--------------------------------------");
                printf("Enter your choice:\t");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                        create();
                                        break;
                        case 2:
                                        display();
                                        break;
										
                        case 3: 
                                        insert_begin();
                                        break;
										
                        case 4:
                                        insert_end();
                                        break;
										
                        case 5:
                                        insert_pos();
                                        break;
										
                        case 6:
                                        delete_begin();
                                        break;
                        case 7:
                                        delete_end();
                                        break;
                        case 8:
                                        deletepos();
                                        break;
                        
                        case 9:
                                        exit(0);
                                        break;
                             
                        default:
                                        printf("n Wrong Choice:");
                                        break;
                }
        }
		getch();
        return 0;
}
void create()
{
	//creating first node
        struct node *newnode,*temp;
        newnode=(struct node *)malloc(sizeof(struct node));
		if(newnode==NULL)
		{
			printf("memory not allocated");

		}
		else
		{
			 printf("\nEnter the data value for the node:");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL)
        {
                head=newnode;
        }
        else
        {
                temp=head;
                while(temp->next!=NULL)
                { 
                        temp=temp->next;
                }
                temp->next=newnode;
        }
		}
       
}
void display()
{
        struct node *ptr;
        if(head==NULL)
        {
                printf("\nList is empty:");  //case 1 :linked list is empty
                return;
        }
        else
        {
                ptr=head;
                 printf("Nodes in linked list:");
                while(ptr!=NULL)
                {
                        printf("%d ->   ",ptr->data );
                        ptr=ptr->next ;
                }
   
        }
}
void insert_begin()
{
        struct node *newnode;
        newnode=(struct node *)malloc(sizeof(struct node));
		if(newnode==NULL)
		{
			printf("memory not allocated");

		}
		else
		{
   
			printf("\nEnter the data value for the node:" );
			scanf("%d",&newnode->data);
			newnode->next =NULL;
			if(head==NULL)  //case 1 :linked list is empty,creatig first node 
			{
					head=newnode;
			}
			else
			{
					newnode->next=head;  //case 2: Inserting a newnode at the beginning assuming atleast one node is present in the linked list
					head=newnode;
			}
		}
}
void insert_end()
{
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
     if(temp==NULL)
		{
			printf("memory not allocated");

		}
	 else
	 {
		  printf("\nEnter the data value for the node:" );
        scanf("%d",&temp->data );
        temp->next =NULL;
        if(head==NULL) //case 1 :linked list is empty,creating first node 
        {
                head=temp;
        }
        else
        {
			//case 2: Inserting a newnode assuming atleast one node is present in the linked list
                ptr=head;
                while(ptr->next !=NULL)
                {
                        ptr=ptr->next ;
                }
                ptr->next =temp;
        }
	 }
       
}
void insert_pos()
{
        struct node *temp,*newnode, *ptr;
        int i,pos;
        newnode=(struct node *)malloc(sizeof(struct node));
		if(newnode==NULL)
		{
			printf("memory not allocated");
		}
		else
		{
			 printf("\n Enter the position for the new node to be inserted:\t");
        scanf("%d",&pos);
        printf("\n Enter the data value of the node: \t");
        scanf("%d",&newnode->data) ;
  
        newnode->next=NULL;
        if(pos==1) //case 1: Inserting a newnode at the beginning assuming atleast one node is present in the linked list
        {
                newnode->next=head;
                head=newnode;
        }
        else
        {
			    temp=head;
             
					for(i=1;i<pos-1;i++) 
				{
					temp=temp->next;
					 
                        if(temp == NULL)
                        {
                                printf("\n Invalid position : \n");
                                return;
                        }
                }
                newnode->next =temp->next ;
                temp->next=newnode;
        }
		}
       
}
void delete_begin()
{
        struct node *ptr;
		 //ptr=head;
        if(head==NULL)
        {
                printf("\nList is Empty:\n");
                return;
        }
        else
        {
                ptr=head;
                head=head->next ;
                printf("\nThe deleted element is :%d\t",ptr->data);
                free(ptr);
        }
}
void delete_end()
{
        struct node *temp,*ptr;
        if(head==NULL)
        {
                printf("\nList is Empty:");
                exit(0);
        }
        else if(head->next ==NULL)
        {
			//Performing deletion on a linked list with only one node 
                ptr=head;
                head=NULL;
                printf("\nThe deleted element is:%d\t",ptr->data);
                free(ptr);
        }
        else
        {
                ptr=head;
                while(ptr->next!=NULL)
                {
                        temp=ptr;
                        ptr=ptr->next;
                }
                temp->next=NULL;
                printf("\nThe deleted element is:%d\t",ptr->data);
                free(ptr);
        }
}

void deletepos()
{
        int i,pos;
        struct node *temp,*ptr;
        
        temp=head->next;
                printf("\nEnter the position of the node to be deleted:\t");
                scanf("%d",&pos);
                        ptr=head;
                        for(i=1;i<pos;i++) 
						{ 
							temp=temp->next;
							ptr=ptr->next ;
							if(temp == NULL)
                              {
                                printf("\n Invalid position : \n");
                                return;
                              }
                        }
                        ptr->next =temp->next ;
                        printf("\nThe deleted element is:%d\t",ptr->data );
                        free(temp);
                
} 

