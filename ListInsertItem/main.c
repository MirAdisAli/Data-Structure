#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}node;

node *head,*temp;

//Insert the data in the list
void insert(node *pointer, int data)
{
        /* Iterate through the list till we encounter the last node.*/
        while(pointer->next!=NULL)
        {
                pointer = pointer -> next;
        }
        /* Allocate memory for the new node and put data in it.*/
        pointer->next = (node *)malloc(sizeof(node));
        pointer = pointer->next;
        pointer->data = data;
        pointer->next = NULL;

        printf("%d data Inserted!\n",data);
}

void insertPosition(node *pointer, int pos,int data)
{
        /* Iterate through the list till we encounter the last node.*/
        node *temp;
        int cnt=0;
        temp=(node*)malloc(sizeof(node));
        temp->data=data;
        temp->next=NULL;

        while(pointer->next!=NULL)
        {
                if(cnt==(pos-1))
                {
                  break;
                }
                else{
                    pointer=pointer->next;
                    cnt++;
                }
        }
        temp->next=pointer->next;
        pointer->next=temp;

        printf("%d data Inserted at position %d!\n",data,pos);
}


//Display the list
void print(node *pointer)
{
        if(pointer==NULL)
        {
                return;
        }
        printf("%d ",pointer->data);
        print(pointer->next);
}

int main()
{
    int no,position,data,i;

    head=(node*)malloc(sizeof(node));
    head->next=NULL;
    temp=head;

    printf("Enter how many in list? ");
    scanf("%d",&no);

    for(i=0;i<no;i++){
        printf("Enter %d data:",i+1);
        scanf("%d",&data);

        insert(head,data);
    }

    print(head->next);

    printf("Enter data to insert:");
    scanf("%d",&data);
    printf("Enter position to insert:");
    scanf("%d",&position);

    insertPosition(head->next,position,data);
    print(head->next);


    return 0;
}
