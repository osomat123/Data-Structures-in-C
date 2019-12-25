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
    printf("Enter element -> ");
    scanf("%d",&(head->data));
    head->next = NULL;

    if(head)
        printf("SLL Created.\n");
    else
        printf("Error! Try again\n");

    return(head);
}

void insertBegin(node *head)
{
    node *ptr;

    if(head == NULL)
    {
        printf("SLL does not Exist.\n");
        return;
    }

    ptr = (node*)malloc(sizeof(node));
    printf("Enter element -> ");
    scanf("%d",&(ptr->data));
    ptr->next = head;

    head = ptr;

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
    printf("Enter element -> ");
    scanf("%d",&(ptr->data));

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = ptr;
    ptr->next = NULL;

    printf("Element Inserted\n");

}

void insertBefore(node *head,int ele)
{
    node *temp, *ptr;

    if(head == NULL)
    {
        printf("SLL does not Exist.\n");
        return;
    }

    temp=head;
    ptr = (node*)malloc(sizeof(node));
    printf("Enter element -> ");
    scanf("%d",&(ptr->data));

    while(temp->next->data != ele && temp != NULL)
        temp=temp->next;

    if(temp == NULL)
    {
        printf("Element not found\n");
        return;
    }

    ptr->next = temp->next;
    temp->next = ptr;

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
    ptr = (node*)malloc(sizeof(node));
    printf("Enter element -> ");
    scanf("%d",&(ptr->data));

    while(temp->data != ele && temp != NULL)
        temp=temp->next;

    if(temp == NULL)
    {
        printf("Element not found\n");
        return;
    }

    ptr->next = temp->next;
    temp->next = ptr;

    printf("Element Inserted\n");
}

void deleteHead(node *head)
{
    node *temp;

    if(head == NULL)
    {
        printf("SLL does not Exist.\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);
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
}

void deleteElement(node *head, int ele)
{
    node *temp1,*temp2;

    if(head == NULL)
    {
        printf("SLL does not Exist.\n");
        return;
    }

    temp1 = head;

    if(head->data == ele)
    {
        head = head->next;
        free(temp1);
        return;
    }

    while(temp1->data != ele && temp1 != NULL)
    {
        temp2 = temp1;
        temp1 = temp1->next;
    }

    if(temp1 == NULL)
    {
        printf("Element not found\n");
        return;
    }

    temp2->next =temp1->next;
    free(temp1);

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

    while(temp->data != ele)
    {
        temp = temp->next;
        i++;
    }

    if(temp == NULL)
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
        //printf("%d %d %d\n",prev->data,cur->data,next->data);

        next =  cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;

    }

    //printf("%d %d %d\n",prev->data,cur->data,next->data);

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
                    insertBegin(head);
                    break;

            case 3: system("clear");
                    insertEnd(head);
                    break;

            case 4: system("clear");
                    printf("Insert Element -> ");
                    scanf("%d",&ele);
                    insertBefore(head,ele);
                    break;

            case 5: system("clear");
                    printf("Insert Element -> ");
                    scanf("%d",&ele);
                    insertAfter(head,ele);
                    break;

            case 6: system("clear");
                    deleteHead(head);
                    printf("Element deleted\n");
                    break;

            case 7: system("clear");
                    deleteEnd(head);
                    printf("Element deleted\n");
                    break;

            case 8: system("clear");
                    printf("Enter Element to be deleted -> ");
                    scanf("%d",&ele);
                    deleteElement(head,ele);
                    printf("Element deleted\n");
                    break;

            case 9: system("clear");
                    printf("Enter Element to be deleted -> ");
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

            default: printf("Invalid Input");
                     break;

        }

        scanf("%d",&ch);

    } while(ch != 12);

    return(0);

}
