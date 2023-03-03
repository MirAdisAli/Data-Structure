#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;

node *top;

void initialize()
{
    top = NULL;
}

void push(int value)
{
    node *tmp;
    tmp = malloc(sizeof(node));
    tmp -> data = value;
    tmp -> next = top;
    top = tmp;
}

int pop()
{
    node *tmp;
    int n;
    tmp = top;
    n = tmp->data;
    top = top->next;
    free(tmp);
    return n;
}

int getTop()
{
    return top->data;
}

int isempty()
{
    return top==NULL;
}

void display(node *head)
{
    if(head == NULL)
    {
        printf("NULL\n");
    }
    else
    {
        printf("%d\n", head -> data);
        display(head->next);
    }
}

int main()
{
    initialize();
    push(10);
    push(20);
    push(30);
    printf("Content of Stack\n");
    display(top);
    printf("\nThe top is %d\n",getTop());
    printf("%d data is popped\n",pop());
    printf("The top after pop is %d\n",getTop());
    display(top);
    return 0;
}
