#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}node;

node *headA, *headB, *merged;

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

node* MergeLists(node *a, node *b) {
    if (a == NULL) {
        return b;
    } else if (b == NULL) {
        return a;
    }

    if (a->data < b->data) {
        a->next = MergeLists(a->next, b);
        return a;
    } else {
        b->next = MergeLists(a, b->next);
        return b;
    }
}

int main()
{
    headA=(node*)malloc(sizeof(node));
    headA->data=2;
    headA->next = (node*)malloc(sizeof(node));
    headA->next->data=3;
    headA->next->next = (node*)malloc(sizeof(node));
    headA->next->next->data=4;
    headA->next->next->next=NULL;

    printf("List A:");
    print(headA);

    headB=(node*)malloc(sizeof(node));
    headB->data=3;
    headB->next = (node*)malloc(sizeof(node));
    headB->next->data=5;
    headB->next->next = NULL;

    printf("\nList B:");
    print(headB);

    merged=MergeLists(headA,headB);

    printf("\nMerged List:");
    print(merged);

    return 0;
}
