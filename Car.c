#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *p;
}*t,*t1,*temp;
int count = 0;
void main()
{
    int no, ch, e;
    printf("\n 1 enter car");
    printf("\n 2 take out car");
    printf("\n 3 number of available car");
    printf("\n 4 Dipslay");
    printf("\n 5 exit");
    create();
    while (1)
    {
        printf("\n Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter ");
            scanf("%d", &no);
            push(no);
            break;
        case 2:
            pop();
            break;
        case 3:
            empty();
            break;
        case 4:
            display();
            break;
            break;
        case 5:
            exit(0);
        default :
            printf(" error ");
            break;
        }
    }
}
void create()
{
    t = NULL;
}
void stack_count()
{
    printf("\n %d", count);
}
void push(int data)
{
    if (t == NULL)
    {
        t =(struct node *)malloc(1*sizeof(struct node));
        t->p = NULL;
        t->info = data;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->p = t;
        temp->info = data;
        t = temp;
    }
    count++;
}
void display()
{
    t1 = t;
    if (t1 == NULL)
    {
        printf("empty");
        return;
    }
    while (t1 != NULL)
    {
        printf("%d ", t1->info);
        t1 = t1->p;
    }
}
void empty()
{
    if (t == NULL)
        printf("\n empty");
    else
        printf("\n car : %d ", count);
}
void pop()
{
    t1 = t;
    if (t1 == NULL)
    {
        printf("\n Error ");
        return;
    }
    else
        t1 = t1->p;
    printf("\n out: %d", t->info);
    free(t);
    t = t1;
    count--;
}
