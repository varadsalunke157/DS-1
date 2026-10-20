
#include <stdio.h>

int isFull(int rear, int size)
{
    if(rear == size - 1)
        return 1;
    else
        return 0;
}

int isEmpty(int front, int rear)
{
    if(front == rear)
        return 1;
    else
        return 0;
}

int AddQ(int q[], int front, int rear, int size)
{
    int x;

    if(isFull(rear, size))
    {
        printf("Queue is full\n");
        return rear;
    }

    printf("Enter element: ");
    scanf("%d", &x);

    front++;
    q[front]=x;
    return rear;
}

int DeleteQ(int q[], int front, int rear)
{
    if(isEmpty(front, rear))
    {
        printf("Queue is empty!\n");
        return front;
    }

    printf("Deleted element: %d\n", q[front]);
    rear++;

    return front;
}

int main()
{
    int q[10];
    int size = 10;
    int front = -1, rear = -1;
    int choice;

    do
    {
        printf("QUEUE\n");
        printf("1. Add Q\n");
        printf("2. Delete Q\n");
        printf("3. Is Empty\n");
        printf("4. Is Full\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                if(front == -1)
                    front = 0;

                rear = AddQ(q, front, rear, size);

                if(rear == -1)
                    front = -1;
                break;

            case 2:
                front = DeleteQ(q, front, rear);

                if(front > rear)
                {
                    front = -1;
                    rear = -1;
                }
                break;

            case 3:
                if(isEmpty(front, rear))
                    printf("Queue is empty\n");
                else
                    printf("Queue is not empty\n");
                break;

            case 4:
                if(isFull(rear, size))
                    printf("Queue is full\n");
                else
                    printf("Queue is not full\n");
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 5);

    return 0;
}