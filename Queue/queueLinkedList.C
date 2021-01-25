#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int data;
    struct queue *next;
} node;

node* create()
{
    node *head;

    head = (node*)malloc(sizeof(node));
    printf("Enter element to be inserted -> ");
    scanf("%d",&(head->data));
    head->next = NULL;

    if(head)
        printf("Queue Created.\n");
    else
        printf("Error! Try again\n");

    return(head);
}

void insertElement(node *head)
{
    node *ptr, *temp;

    if(head == NULL)
    {
        printf("Queue does not Exist.\n");
        return;
    }

    temp = head;
    ptr = (node*)malloc(sizeof(node));
    printf("Enter element to be inserted -> ");
    scanf("%d",&(ptr->data));

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = ptr;
    ptr->next = NULL;

    printf("Element Inserted\n");

}

void removeElement(node **head)
{
    node *temp;

    if(*head == NULL)
    {
        printf("Queue does not Exist.\n");
        return;
    }

    temp = *head;
    *head = temp->next;
    printf("Deleted element -> %d\n",temp->data);
    free(temp);
}

void printQueue(node *head)
{
    node *temp;

    if(head == NULL)
    {
        printf("Queue does not Exist.\n");
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

        printf("****** Queue ******\n\n");
        printf("1.Create Queue\n2.Insert element\n3.Remove element\n");
        printf("4.Print Queue\n5.Exit\n\n");
        printf("Your choice -> ");

        scanf("%d",&ch);

        switch(ch)
        {
            case 1: system("clear");
                    head = create();
                    break;

            case 2: system("clear");
                    insertElement(head);
                    break;

            case 3: system("clear");
                    removeElement(&head);
                    break;

            case 4: system("clear");
                    printQueue(head);
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
