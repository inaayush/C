#include<stdio.h>
#include<stdlib.h>

typedef struct NODE
{
    int data;
    struct NODE* link;
}node;

node * create(int n)
{
    int i;
    node* head = NULL;
    node* temp = NULL;
    node* ptr = NULL;
    for(i=0;i<n;i++)
    {   
        //creating an isolated node
        temp = (node*)malloc(sizeof(node));
        printf("Data%d:",i+1);
        scanf("%d",&(temp->data));
        temp->link = NULL;
        //if no node is present then head will be the new node
        if(head == NULL)
        {
            head = temp;
        }else{
            ptr= head;
            //another pointer which will traverse through and link each node
            while(ptr->link!=NULL)
            {
                ptr=ptr->link;
            }
            ptr->link = temp;
         }
    }
    return head;
}


void display(node* head){
    printf("DONE!\n");
    printf("\n THE LINKED LIST=>");
   while(head!=NULL)
   {
       printf("|%d|->",head->data);
       head = head->link;
   }
   printf("NULL\n");
   printf("_____________________________________________________________");
}
void prepend(node** href,int new_data){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = new_data;
    new_node->link = *href;
    *href = new_node;
}
void append(node** href,int new_data){
    node* new_node = (node*)malloc(sizeof(node));
    node* last_node = *href;
    new_node->data = new_data;
    new_node->link = NULL;
    if(*href==NULL)
    {
        *href = new_node;
    }
    while (last_node->link!=NULL)
    {
        last_node = last_node->link;
    }
    last_node->link = new_node;
}
void insert(node** href,int pos,int new_data){
    node* new_node = (node*)malloc(sizeof(node));
    node* target = *href;
    new_node->data = new_data;

    for(int i=2;i<pos;i++){
        target = target->link;
    }
    new_node->link = target->link;
    target->link = new_node; 
}

void delete(node** href,int pos){
    node* target = *href;
    if(pos==1){
        *href = target->link;
    }else{
        for(int i=2;i<pos;i++){
        target = target ->link;
    }
    target ->link = target->link->link;
    }
}
void search(node** href,int s){
    while(*href!=NULL)
    {
        if((*href)->data==s){
            printf("\nElement found in the list");
            break;
        }
        else
        {
            // printf("\nElement not found");
            *href = (*href)->link;
            if(*href==NULL)
            {
                printf("\nElement is not present in the list");

            }
        }

    }
}
void sort(node** href){
    int temp;
    node* ptr = (*href);
    if (ptr == NULL)
    {
        printf("list empty");
    }
    
    while((ptr->link)!=NULL)
    {
        if((ptr)->data>(ptr)->link->data)
        {
            temp = ptr->data;
            ptr->data=ptr->link->data;
            ptr->link->data = temp;
        }
        ptr = ptr->link;
        
    }
}
void reverse(node** href) 
{ 
	node* prev = NULL; 
	node* ptr = *href; 
	node* next = NULL; 
	while (ptr != NULL) { 
		next = ptr->link; 
 
		ptr->link = prev; 

		prev = ptr; 
		ptr = next; 
	} 
	*href = prev; 
} 


int main()
{
    int n,data,pos,input,s;

    printf("_______________________LINKED LIST CREATER____________________\n");
    printf("No. of nodes:");
    scanf("%d",&n);
    node* head;
    head = create(n);
    printf("\n<Linked List Created Successfully>\n");
    printf("\nSelect the following Operations:\n");
    printf("Press [1]=prepend [2]=insert [3]=append [4]=delete [5]=search [6]=sort [7]=reverse:=>");
    scanf("%d",&input);

    switch (input)
    {
    case 1:
        printf("\n__________________________PREPEND______________________________\n");
        printf("Enter the data:");
        scanf("%d",&data);
        prepend(&head,data);
        display(head);
        break;
    case 2:
        printf("\n__________________________INSERT_______________________________\n");
        printf("Enter the data:");
        scanf("%d",&data);
        printf("Enter the position at which you wish to insert:");
        scanf("%d",&pos);
        if(pos>n){
            printf("WARNING:Size exceeded!");
            break;
        }
        insert(&head,pos,data);
        display(head);
        break;
    case 3:
        printf("\n__________________________APPEND________________________________\n");
        printf("Enter the data:");
        scanf("%d",&data);
        append(&head,data);
        display(head);
        break;
    case 4:
        printf("\n__________________________DELETE_________________________________\n");
        printf("Enter the position which you want to delete:");
        scanf("%d",&pos);
        delete(&head,pos);
        display(head);
        break;
    case 5:
        printf("\n__________________________SEARCH_________________________________\n");
        printf("Enter the target to be searched:");
        scanf("%d",&s);
        display(head);
        search(&head,s);
        break;
    case 6:
        printf("\n__________________________SORT_________________________________\n");
        sort(&head);
        display(head);
        break;
    case 7:
        printf("\n__________________________REVERSE_________________________________\n");
        reverse(&head);
        display(head);
        break;
    default:
        break;
    }
}
