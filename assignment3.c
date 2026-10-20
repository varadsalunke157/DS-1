#include<stdio.h>
#include<string.h>



struct players{

    
    char name[20];
    char position[20];
    int ga;

};

void accept(struct players p[100],int n){
    for(int i=0;i<n;i++){
        printf("Enter data for player %d \n\n",i+1);
        
        printf("Enter Name of player: ");scanf("%s",p[i].name);
        printf("Enter Position of player: ");scanf("%s",p[i].position);
        printf("Enter Goals and Assists this season: ");scanf("%d",&p[i].ga);
        printf("\n");
    }
}

void display(struct players p[100],int n){
    printf("=====List of players===== \n");
    for(int i=0;i<n;i++){
        printf("Player %d : \n",i+1);
        
        printf("Name: %s \nPosition: %s \nG/As: %d\n",p[i].name,p[i].position,p[i].ga);
        printf("\n");
    }
}


int linearsearch(struct players p[100],int n){

    char target[20];

    printf("Enter player you want to scout: \n");
    scanf("%s",target);
    int flag=0;
    printf("\n\n");

    for(int i=0;i<n;i++){
        if(strcmp(p[i].name, target) == 0){
            
            return i;

        }
       

        
    } 

    
    return -1;
}


void Namesort(struct players p[100], int n){

    struct players temp;

    for(int i=0;i<n-1;i++){

        for(int j=0;j<n-1-i;j++){

            if(strcmp(p[j].name,p[j+1].name)>0){

                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
}

int Binarysearch(struct players p[100],int n,char target[20]){
    

    

    

    int low=0;
    int high=n-1;

    while(low<=high){

        int mid=(low+high)/2;

        if(strcmp(p[mid].name,target)==0){
            return mid;
        }

        else if(strcmp(p[mid].name,target)<0){
            low=mid+1;
        }

        else{
            high=mid-1;
        }
    }

    return -1;


    
}


void Bubblesort(struct players p[100], int n) {
    int temp = 0;
    char tempn[20];
    char tempp[20];

    
    for (int i = 0; i < n - 1; i++) {
        
        for (int j = 0; j < n - 1; j++) {
            
            
            if (p[j].ga < p[j+1].ga) {
                
                
                temp = p[j].ga;
                p[j].ga = p[j+1].ga;
                p[j+1].ga = temp;
                
                
                strcpy(tempn, p[j].name);
                strcpy(p[j].name, p[j+1].name);
                strcpy(p[j+1].name, tempn);
                
                
                strcpy(tempp, p[j].position);
                strcpy(p[j].position, p[j+1].position);
                strcpy(p[j+1].position, tempp);
            }
        }
    }


   

}


void Insertionsort(struct players p[100], int n){

    struct players temp;

    for(int i=1;i<n;i++){

        temp = p[i];
        int j=i-1;

        while(j>=0 && p[j].ga < temp.ga){

            p[j+1]=p[j];
            j--;
        }

        p[j+1]=temp;
    }
}

void Selectionsort(struct players p[100],int n){

    struct players temp;
    int min_index;
    int j;
    for(int i=0;i<n-1;i++){

        min_index=i;
        j=i+1;
        for(j;j<n;j++){
            if(p[j].ga<p[min_index].ga){
                min_index=j;
            }
        }

        temp=p[i];
        p[i]=p[min_index];
        p[min_index]=temp;

    }
}

void Shellsort(struct players p[100],int n){
    struct players temp;

    
    for(int gap=n/2;gap>0;gap=gap/2){

        for(int i=gap;i<n;i++){

            temp=p[i];
            int j=i;

            while(j>=gap && p[j-gap].ga < temp.ga){

                p[j]=p[j-gap];
                j=j-gap;
            }

            p[j]=temp;
        }
    }

}







int main(){
    int n;
    struct players p[100];
    int choice;
    int result;
    int result1;
    char target[20];

    printf("Enter total no. of players in team: \n");
    scanf("%d",&n);
    printf("\n");
    
    accept(p,n);


    printf("Enter operation to perform \n1.Display\n2.Search For Scouting\n3.Sort on basis of G/A\n4.Insertion sort on basis of G/A\n5.Selection Sort\n6.Shell Sort\n7.Binary");
    scanf("%d",&choice);

    switch(choice){
        case 1:
        display(p,n);
        break;

        case 2:

        result = linearsearch(p, n);
        if(result != -1) {
            printf("Data of your Player to be scouted is: \n");
            printf("Name of player: %s \n", p[result].name);
            printf("Position of player: %s \n", p[result].position);
            printf("Goals and Assists this season: %d \n", p[result].ga);
            printf("\n");
        } 
        else {
            printf("Player not found\n");
        }
        break;
        

        case 3:
        Bubblesort(p,n);
        display(p,n);

        case 4:
        Insertionsort(p,n);
        display(p,n);
        break;

        case 5:
        Selectionsort(p,n);
        display(p,n);
        break;

        case 6:
        Shellsort(p,n);
        display(p,n);
        break;

        case 7:
        Namesort(p,n);
        printf("Enter player you want to scout: \n");
        scanf("%s",target);
        result1=Binarysearch(p,n,target);
        if(result1 != -1) {
            printf("Data of your Player to be scouted is: \n");
            printf("Name of player: %s \n", p[result1].name);
            printf("Position of player: %s \n", p[result1].position);
            printf("Goals and Assists this season: %d \n", p[result1].ga);
            printf("\n");
        } 
        else {
            printf("Player not found\n");
        }
        break;
        


        default:
        printf("Invalid choice");

    }
    


    
    return 0;

}