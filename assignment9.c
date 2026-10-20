#include<stdio.h>

int isEmpty(int front,int rear){

    if(front==-1 && rear==-1){
        return 0;

    }
    else{
        return 1;


    }
}

int isFull(int n,int front,int rear){

    if((rear+1)%n==front){
        return 0;
    }
    else{
        return 1;
    }
}

int AddQ(int cq[20],int n,int front,int rear,int elem){
    if (isFull(n,front,rear)!=0){

        if(front==-1 && rear==-1){
            front=0;
            rear=0;
        }
        else{
            rear=(rear+1)%n;
        }

        cq[rear]=elem;
        return rear;

    }
    else{
        return -1;
    }

}

int DeleteQ(int cq[20],int n,int front,int rear){

    if (isEmpty(front,rear)!=0){

        int d = cq[front];

        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            front=(front+1)%n;
        }

        return d;
    }
    else{
        return -1;
    }
}

int main(){
    int cq[20];
    int n;
    int c,a,b,c1,d,elem;
    int front = -1;
    int rear = -1;

    printf("Enter size of queue: ");
    scanf("%d",&n);

    do{
    printf("Enter operation to perform:\n1.Check if Empty\n2.Check if Full\n3.Add Element\n4.Remove element\n5.Exit\n");
    scanf("%d",&c);

    switch(c){

        case 1:

            a= isEmpty(front,rear);
            if(a==0){
                printf("Queue is Empty \n");

            }
            else{
                printf("Queue is Not Empty \n");
            }
            break;

        case 2:
            b= isFull(n,front,rear);
            if (b==0){
                printf("Queue is full \n");

            }
            else{
                printf("Queue is not full \n");
            }
            break;

        case 3:

            printf("Enter element to add \n");
            scanf("%d",&elem);

            c1=AddQ(cq,n,front,rear,elem);
            if (c1!=-1){
                rear=c1;
                if(front==-1){
                    front=0;
                }
                printf("Element added successfully \n");

            }
            else{
                printf("Queue is full \n");
            }
            break;

        case 4:

            d=DeleteQ(cq,n,front,rear);
            if (d!=-1){
                printf("Latest Element deleted successfully \n");
                printf("Element removed is: %d \n",d);

                if(front==rear){
                    front=-1;
                    rear=-1;
                }
                else{
                    front=(front+1)%n;
                }

            }
            else{
                printf("Queue is Empty \n");
            }
            break;

        case 5:
            printf("Exiting....");
            break;

        default :
            printf("Invalid input.......\n");
            break;
    }
}while(c!=5);

    return 0;

}