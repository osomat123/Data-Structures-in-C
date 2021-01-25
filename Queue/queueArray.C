/* This is an implemntation of a queue using a circular array */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];

int rear = 0;
int front = 0;

int isEmpty()
{
    return rear == front;
}

int isFull()
{
    return (rear+1) % MAX == front;
}

void insert(int data)
{
    if(isFull())
    {
        printf("Queue is full!\n");
        return;
    }

    rear = (rear + 1) % MAX;
    queue[rear] = data;
    printf("Element inserted\n");
}

int remove()
{
    if(isEmpty())
    {
        printf("Queue is empty!\n");
        return -9999;
    }

    front = (front + 1) % MAX;
    return queue[front];
}

void printQueue()
{
    int temp = (front + 1) % MAX;

    while(temp != rear)
    {
        printf("%d -> ", queue[temp]);
        temp = (temp + 1) % MAX; 
    }
    printf("END");
}

int main()
{
    int ch, data, ele;;

    do
    {
        system("clear");

        printf("****** Queue ******\n\n");
        printf("1.Insert Element\n2.Remove Element\n3.Print queue\n");
        printf("4.Exit\n");
        printf("Your choice -> ");

        scanf("%d",&ch);

        switch(ch)
        {
            case 1: system("clear");

                    printf("Enter element to be inserted -> ");
                    scanf("%d",&ele);
                    insert(ele);
                    break;

            case 2: system("clear");

                    data = remove();
                    if(data != -9999)
                        printf("Removed element -> %d",data);
                    break;

            case 3: system("clear");
                    printQueue();
                    break;

            case 4: break;

            default: system("clear");
                     printf("Invalid Input\n");
                     break;
        }

        printf("\nPress any key to continue...\n");
        getchar();
        getchar();

    } while(ch != 4);

    return 0;
}
