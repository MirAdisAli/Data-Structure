#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
        int Data;
        struct Node* next;
}*rear, *front;

int dequeue()
{
      struct Node *var=rear;
      int data;
      if(var==rear)
      {
            data=rear->Data;
            rear = rear->next;
            free(var);
            return data;
      }
       else
      printf("\nQueue Empty");
      return 0;
}


void enqueue(int value)
{
      struct Node *temp;
      temp=(struct Node *)malloc(sizeof(struct Node));
      temp->Data=value;

      if (front == NULL) //first node
      {
           front=temp;
           front->next=NULL;
           rear=front;
      }
      else
      {
          front->next=temp;
          front=temp;
          front->next=rear;
      }
}


void display()
{
      struct Node *var=rear;
      if(var!=NULL)
      {
           printf("\nElements are as:  ");
            while(var!=front)
           {
                 printf("\t%d",var->Data);
                 var=var->next;
           }
           if(var==front)
           {
                printf("\t%d",var->Data);
           }
     printf("\n");
     }
     else
     printf("\nQueue is Empty");
}


int main(int argc, char *argv[])
{
     int i=0;
     front=NULL;
     printf(" \n1. Push to Queue");
     printf(" \n2. Pop from Queue");
     printf(" \n3. Display Data of Queue");
     printf(" \n4. Exit\n");
     while(1)
     {
          printf(" \nChoose Option: ");
          scanf("%d",&i);
          switch(i)
          {
          case 1:
          {
          int value;
          printf("\nEnter a value to push into Queue: ");
          scanf("%d",&value);
          enqueue(value);
          display();
          break;
          }
          case 2:
          {
          int data;
          data=dequeue();
          display();
          printf("Dequeued data=%d\n",data);
          break;
          }
          case 3:
          {
          display();
          break;
          }
          case 4:
          {
          exit(0);
     }
     default:
     {
         printf("\nWrong choice for operation");
     }
   }
 }
}


