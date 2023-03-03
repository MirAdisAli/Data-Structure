#include<stdio.h>
#include<conio.h>
#define MAX 10

int queue[MAX], rear=0, front=0;

void enqueue(int token)
{
    char a;
    if(rear==MAX)
    {
        printf("\nQueue full");
        return;
    }
    do
    {
        printf("\nEnter the token to be inserted:");
        scanf("%d",&token);
        queue[front]=token;
        front=front+1;
        printf("Do you want to continue insertion Y/N? ");
        a=getch();
    }
    while(a=='y');
}

int dequeue()
{
    int t;
    if(front==rear)
    {
        printf("\nQueue empty!");
        return 0;
    }
    rear=rear+1;
    t=queue[rear-1];
    return t;
}

void display()
{
    int i;
    printf("\nThe queue elements are:");
    for(i=rear;i<front;i++)
    {
        printf("%d ",queue[i]);
    }
}



int main()
{
     char ch , a='y';
     int choice, token;
     printf("1.Insert or Enqueue");
     printf("\n2.Delete or Dequeue");
     printf("\n3.Show or display");
     do
     {
           printf("\nEnter your choice for the operation: ");
           scanf("%d",&choice);
          switch(choice)
          {
                case 1: enqueue(token);
                display();
                break;

                case 2:
                token=dequeue();
                printf("\nThe token deleted is %d",token);
                display();
                break;

                case 3:
                display();
                break;

                default:
                printf("Wrong choice");
                break;
          }
          printf("\nDo you want to continue(y/n):");
          ch=getch();
    }
    while(ch=='y'||ch=='Y');
    getch();
}


