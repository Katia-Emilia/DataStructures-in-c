#include<stdio.h>  
#include<conio.h>
#include<stdlib.h>  
struct node   
{  
    int data;  
    struct node *next;   
};  
struct node *head;  
  
void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos(); 
int main ()  
{  
     int choice;
        while(1){
               
                printf("\n MENU");
                printf("\n 1.Display");
                printf("\n 2.Insert at the beginning");
                printf("\n 3.Insert at the end");
                printf("\n 4.Insert at specified position");
                printf("\n 5.Delete from beginning");
                printf("\n 6.Delete from the end");
                printf("\n 7.Delete from specified position");
                printf("\n 8.Exit");
                printf("\n--------------------------------------");
                printf("Enter your choice:\t");
                scanf("%d",&choice);
                switch(choice)
                {
                  
                        case 1:
                                        display();
                                        break;
										
                       case 2: 
                                        insert_begin();
                                        break;
						 			
                        case 3:
                                        insert_end();
                         	              break;
										
                        case 4:
                                        insert_pos();
                                        break;
						 			
                        case 5:
                                        delete_begin();
                                        break;
										
                    case 6:
                                        delete_end();
                                        break;
									    
                        case 7:
                                        delete_pos();
                                        break;
                        
                        case 8:
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


void insert_begin()
{
        struct node *newnode,*temp;
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
		   if(head==NULL) //if linked list is empty
        {       
			head=newnode;
			 newnode->next=head;
	    }
		else    
		{
			temp = head;  
            while(temp->next != head)  //traverse to the last node
			{
                temp = temp->next;  
			}
            newnode->next = head;   
            temp -> next = newnode;   
            head = newnode;  
		}
		   printf("\nnode inserted\n");
		   }
}


void insert_end()  
{  
    struct node *newnode,*temp;   
    int item;  
    newnode = (struct node *)malloc(sizeof(struct node));  
		if(newnode==NULL)
		{
			printf("memory not allocated");
		}
		else
		{
	 printf("\nEnter the data value for the node:" );
        scanf("%d",&newnode->data);
        newnode->next =NULL;
        if(head == NULL)  //if linked list is empty
        {  
            head = newnode;  
            newnode -> next = head;    
        }  
        else  
        {  
            temp = head;   
            while(temp -> next != head)  //traverse to the last node
            {  
                temp = temp -> next;  
            }  
            temp -> next = newnode;   
            newnode -> next = head;  
        }  
          
        printf("\nnode inserted\n");  
		}
}  

void insert_pos()
{
        struct node *temp,*newnode,*ptr;
        int i,n=0,pos;
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
		ptr=head;    
         if(head == NULL)  //if linked list is empty
        {  
            head = newnode;  
            newnode -> next = head;    
        }  
		 else
		 {
			 while(ptr -> next != head)  //traversing to the last node
			{  
				n++;
				ptr = ptr -> next;  
				printf("number of nodes are:%d",n);
			}  
			if(pos==1)//if newnode is to be inserted at pos 1
			{ 

              newnode->next = head;   
              ptr -> next = newnode;   
              head = newnode;  
			}
			else
			{
			if(n+2>=pos) //if newnode to be inserted at pos not equal to 1(all other cases)
			{
					 temp=head;
					  for(i=1;i<pos-1;i++)
						{
							temp=temp->next;
						}
					  newnode->next=temp->next;
					  temp->next=newnode;
		     }else
				 {
					 printf("\n Invalid position : \n");
											return;
				 }
			}
		 

		 }
			
			}
		
}
  
void delete_begin()  
{  
    struct node *temp;   
    if(head == NULL)  
    {  
        printf("\nlist is empty");    
    }  
    else if(head->next == head)  
    {  
        
        free(head);  
		 head = NULL; 
        printf("\nnode deleted\n");  
    }  
      
    else  
    {   temp = head; 
	     
        while(temp -> next != head)  
		{

            temp = temp -> next;   
		}
        temp->next = head->next;  
		 free(head); 
		 head = temp->next;  
        
       
        printf("\nnode deleted\n");  
  
    }  
}  
void delete_end()  
{  
    struct node *ptr, *temp;  
    if(head==NULL)  
    {  
        printf("\nlist is empty");  
    }   
    else   
    {  
        temp = head;  
        while(temp ->next != head)  
        {  
            ptr=temp;  
            temp = temp->next;  
        }  
        ptr->next = head;  
		   printf("\nThe deleted element is:%d\t",ptr->data );
        free(ptr);  
    
  
    }  
}  
  void delete_pos()
  {
	   int i,pos;
        struct node *temp,*ptr;
        if(head==NULL)
        {
                printf("\nThe List is Empty:\n");
                return;
        }
        else
        {
                printf("\nEnter the position of the node to be deleted:\t");
                scanf("%d",&pos);
                if(pos==1)
                {
                        if(head->next == head)  
						{  
							head = NULL;  
							free(head);  
							printf("\nnode deleted\n");  
						}  
      
						else  
						{   temp = head;   
							ptr=head;
							while(temp -> next != head)  //traversing to the last node
							{

								temp = temp -> next;   
							}
		 					temp->next = head->next;  
							free(ptr);  
							head = temp->next;  
							printf("\nnode deleted\n");  
  
						}  
                }
                else
                { 
                        ptr=head;
                        for(i=1;i<pos;i++) 
						{ 
							temp=ptr;
							ptr=ptr->next ;
                                if(ptr->next==head && i!=pos-1)//checks if it is last node and i should not be equal to pos-1
								{
									printf("\n Invalid position : \n");
												return; 
								}
                        }
                        temp->next =ptr->next ;
                        printf("\nThe deleted element is:%d\t",ptr->data );
                        free(ptr);
                }
        }


  }
 

void display()  
{  
    struct node *ptr;  

    ptr=head;  
    if(head == NULL)  
    {  
        printf("\nlinked list empty");  
    }     
    else  
    {  
        
        while(ptr -> next != head)  
        {  
          
           printf("%d `", ptr->data);
            ptr = ptr -> next;  
        }  
         printf(" %d", ptr->data);
    }  
              
}  

