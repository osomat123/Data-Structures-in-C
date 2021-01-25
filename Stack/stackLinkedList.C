#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int data;
    struct stack *next;
} node;

node* create()
{
    node *head;

    head = (node*)malloc(sizeof(node));
    printf("Enter element to be inserted -> ");
    scanf("%d",&(head->data));
    head->next = NULL;

    if(head)
        printf("Stack Created.\n");
    else
        printf("Error! Try again\n");

    return(head);
}

void push(node **head)
{
    node *ptr;

    if(head == NULL)
    {
        printf("Stack does not Exist.\n");
        return;
    }

    ptr = (node*)malloc(sizeof(node));
    printf("Enter element to be inserted -> ");
    scanf("%d",&(ptr->data));

    ptr->next = *head;
    *head = ptr;

    printf("Element Inserted\n");

}

void pop(node **head)
{
    node *temp;

    if(*head == NULL)
    {
        printf("Stack does not Exist.\n");
        return;
    }

    temp = *head;
    *head = temp->next;
    printf("Deleted element -> %d\n",temp->data);
    free(temp);
}

void printStack(node *head)
{
    node *temp;

    if(head == NULL)
    {
        printf("Stack does not Exist.\n");
        return;
    }

    temp = head;

    while(temp)
    {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

}

int main()
{
    int ch=0,ele=0;
    node *head = NULL;

    do
    {
        system("clear");

        printf("****** Stack ******\n\n");
        printf("1.Create Stack\n2.Insert element\n3.Remove element\n");
        printf("4.Print Stack\n5.Exit\n\n");
        printf("Your choice -> ");

        scanf("%d",&ch);

        switch(ch)
        {
            case 1: system("clear");
                    head = create();
                    break;

            case 2: system("clear");
                    push(&head);
                    break;

            case 3: system("clear");
                    pop(&head);
                    break;

            case 4: system("clear");
                    printStack(head);
                    break;

            case 5: break;

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
