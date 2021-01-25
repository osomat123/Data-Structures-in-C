#include <stdio.h>
#include <stdlib.h>

typedef struct singly_linked_list
{
    int data;
    struct singly_linked_list *next;
} node;

node* create()
{
    node *head;

    head = (node*)malloc(sizeof(node));
    printf("Enter element to be inserted -> ");
    scanf("%d",&(head->data));
    head->next = NULL;

    if(head)
        printf("SLL Created.\n");
    else
        printf("Error! Try again\n");

    return(head);
}

void insertBegin(node **head)
{
    node *ptr;

    if(*head == NULL)
    {
        printf("SLL does not Exist.\n");
        return;
    }

    ptr = (node*)malloc(sizeof(node));
    printf("Enter element to be inserted -> ");
    scanf("%d",&(ptr->data));
    ptr->next = *head;

    *head = ptr;

    printf("Element Inserted\n");
}

void insertEnd(node *head)
{
    node *ptr, *temp;

    if(head == NULL)
    {
        printf("SLL does not Exist.\n");
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

void insertBefore(node **head,int ele)
{
    node *temp,*temp1,*temp2, *ptr;

    if(head == NULL)
    {
        printf("SLL does not Exist.\n");
        return;
    }

    temp = *head;

    if(temp->data == ele)
    {
        ptr = (node*)malloc(sizeof(node));
        printf("Enter element to be inserted -> ");
        scanf("%d",&(ptr->data));

        ptr->next = temp;
        *head = ptr;

        return;
    }

    temp1 = temp;

    while(temp1->data != ele && temp1->next != NULL)
    {
        temp2 = temp1;
        temp1 = temp1->next;
    }

    if(temp1->data != ele)
    {
        printf("Element not found\n");
        return;
    }

    ptr = (node*)malloc(sizeof(node));
    printf("Enter element to be inserted -> ");
    scanf("%d",&(ptr->data));

    ptr->next = temp1;
    temp2->next = ptr;

    printf("Element Inserted\n");
}

void insertAfter(node *head,int ele)
{
    node *temp, *ptr;

    if(head == NULL)
    {
        printf("SLL does not Exist.\n");
        return;
    }

    temp=head;

    while(temp->data != ele && temp->next != NULL)
        temp=temp->next;

    if(temp->data != ele)
    {
        printf("Element not found\n");
        return;
    }

    ptr = (node*)malloc(sizeof(node));
    printf("Enter element to be inserted -> ");
    scanf("%d",&(ptr->data));

    ptr->next = temp->next;
    temp->next = ptr;

    printf("Element Inserted\n");
}

void deleteHead(node **head)
{
    node *temp;

    if(*head == NULL)
    {
        printf("SLL does not Exist.\n");
        return;
    }

    temp = *head;
    *head = temp->next;
    free(temp);
    printf("Element deleted\n");
}

void deleteEnd(node *head)
{
    node *temp1,*temp2;

    if(head == NULL)
    {
        printf("SLL does not Exist.\n");
        return;
    }

    temp1 = head;

    while(temp1->next->next != NULL)
        temp1 = temp1->next;

    temp2 = temp1->next;
    free(temp2);

    temp1->next = NULL;
    printf("Element deleted\n");
}

void deleteElement(node **head, int ele)
{
    node *temp1,*temp2;

    if(*head == NULL)
    {
        printf("SLL does not Exist.\n");
        return;
    }

    temp1 = *head;

    if(temp1->data == ele)
    {
        *head = temp1->next;
        free(temp1);
        return;
    }

    while(temp1->data != ele && temp1->next != NULL)
    {

        temp2 = temp1;
        temp1 = temp1->next;
    }

    if(temp1->data != ele)
    {
        printf("Element not found\n");
        return;
    }

    temp2->next =temp1->next;
    free(temp1);
    printf("Element deleted\n");

}

void searchElement(node *head,int ele)
{
    node *temp;
    int i=0;

    if(head == NULL)
    {
        printf("SLL does not Exist.\n");
        return;
    }

    temp = head;

    while(temp->data != ele && temp->next != NULL)
    {
        temp = temp->next;
        i++;
    }

    if(temp->data != ele)
    {
        printf("Element not found\n");
        return;
    }

    printf("Element found at position -> %d\n",i);
    printf("Memory location -> %d\n",&temp);
}

void reverseSLL(node **head)
{
    node *cur, *next, *prev;

    cur = *head;
    prev = next = NULL;

    if(head == NULL)
    {
        printf("SLL does not Exist.\n");
        return;
    }

    while(cur != NULL)
    {
        next =  cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    *head = prev;

}

void printSLL(node *head)
{
    node *temp;

    if(head == NULL)
    {
        printf("SLL does not Exist.\n");
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

int main(int argc, char const *argv[])
{
    int ch=0,ele=0;
    char str;
    node *head = NULL;

    do
    {
        system("clear");

        printf("****** Singly Linked List ******\n\n");
        printf("1.Create SLL\n2.Insert at Beginning\n3.Insert at end\n");
        printf("4.Insert before given Element\n5.Insert after given element\n");
        printf("6.Delete Head\n7.Delete last element\n8.Delete given element\n");
        printf("9.Search for given element\n10.Reverse SLL\n11.Print SLL\n");
        printf("12.Exit\n\n");
        printf("Your choice -> ");

        scanf("%d",&ch);

        switch(ch)
        {
            case 1: system("clear");
                    head = create();
                    break;

            case 2: system("clear");
                    insertBegin(&head);
                    break;

            case 3: system("clear");
                    insertEnd(head);
                    break;

            case 4: system("clear");
                    printf("Insert Reference Element -> ");
                    scanf("%d",&ele);
                    insertBefore(&head,ele);
                    break;

            case 5: system("clear");
                    printf("Insert Reference Element -> ");
                    scanf("%d",&ele);
                    insertAfter(head,ele);
                    break;

            case 6: system("clear");
                    deleteHead(&head);
                    break;

            case 7: system("clear");
                    deleteEnd(head);
                    break;

            case 8: system("clear");
                    printf("Enter Element to be deleted -> ");
                    scanf("%d",&ele);
                    deleteElement(&head,ele);
                    break;

            case 9: system("clear");
                    printf("Enter Element to be searched -> ");
                    scanf("%d",&ele);
                    searchElement(head,ele);
                    printf("Search Complete\n");
                    break;

            case 10: system("clear");
                     reverseSLL(&head);
                     printf("SLL Reversed\n");
                     break;

            case 11: system("clear");
                     printSLL(head);
                     break;

            case 12: break;

            default: system("clear");
                     printf("Invalid Input\n");
                     break;

        }

    } while(ch != 12);

    return(0);

}
