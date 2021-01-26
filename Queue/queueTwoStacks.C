#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int data;
    struct stack *next;
} node;

node *top1 = NULL;
node *top2 = NULL;

void push(node **head, int ele)
{
    node *ptr;

    ptr = (node*)malloc(sizeof(node));

    ptr->data = ele;
    ptr->next = *head;
    *head = ptr;

    printf("Element Inserted\n");

}

int pop(node **head)
{
    node *temp;
    int data;

    temp = *head;
    *head = temp->next;
    data = temp->data;
    free(temp);
    return data;
}

void insertElement()
{
    int ele;
    printf("Enter element to be inserted -> ");
    scanf("%d",&ele);
    push(&top1, ele);
}

void removeElement()
{
    int ele;
    if(!top1)
    {
        if(!top2)
            printf("Queue is Empty");
    }

    else
    {
         while(top1)
        {
            ele = pop(&top1);
            push(&top2, ele);
        }
    }

    ele = pop(&top2);
    printf("Deleted element -> %d\n", ele);
}

int main()
{
    int ch=0,ele=0;
    node *head = NULL;

    do
    {
        system("clear");

        printf("****** Queue using 2 Stacks ******\n\n");
        printf("1.Insert element\n2.Remove element\n");
        printf("3.Exit\n\n");
        printf("Your choice -> ");

        scanf("%d",&ch);

        switch(ch)
        {
            case 1: system("clear");
                    insertElement();
                    break;

            case 2: system("clear");
                    removeElement();
                    break;

            case 3: break;

            default: system("clear");
                     printf("Invalid Input\n");
                     break;

        }
        printf("\nPress any key to continue...\n");
        getchar();
        getchar();

    } while(ch != 5);

    return(0);

}
