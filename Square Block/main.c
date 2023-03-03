#include <stdio.h>
#include <stdlib.h>

typedef struct square{
       int height;
       int width;
       struct square *next;

} square;

int main()
{
    int no,i;
    square *pt, *temp1, *temp2;
    int area=0;
    printf("Enter how many square blocks (>1)? ");
    scanf("%d", &no);

    if(no<=1) exit(0);

    pt= (square*)malloc(sizeof(square));
    temp1= temp2= pt;
    pt->height=3;
    pt->width=3;

    for(i=1;i<no;i++){
        pt->next=(square*)malloc(sizeof(square));
        pt= pt->next;

        if(i%2==0){
            pt->height=2;
            pt->width=2;
        }else{
            pt->height=3;
            pt->width=3;
        }
    }
    pt->next=NULL;// last node

    printf("Output\n");
    i=0;

    while(temp1->next!= NULL){
        area= area+temp1->height*temp1->width;
        printf("Block %d: %d (area)\n", ++i, temp1->height*temp1->width);
        temp1=temp1->next;
    }
     printf("Block %d: %d (area)\n", ++i, temp1->height*temp1->width);
     area= area+temp1->height*temp1->width;
     //value form last node
     printf("Total area: %d", area);


    return 0;
}
