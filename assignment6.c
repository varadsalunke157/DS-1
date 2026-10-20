#include <stdio.h>
#include <string.h>
char stack[20];

int ICP(char a){
    if(a=='('){
        return 5;
    }

    if (a=='^'){
        return 3;
    }
    if (a=='*' || a=='%' || a =='/'){
        return 2;
    }
    if (a== '+' || a== '-'){
        return 1;
    }
    else{
        return -1;
    }
}

int ISP(char a){
    if(a=='('){
        return 0;
    }

    if (a=='^'){
        return 4;
    }
    if (a=='*' || a=='%' || a =='/'){
        return 2;
    }
    if (a== '+' || a== '-'){
        return 1;
    }
    else{
        return -1;
    }

}


void IntoPost(char infix[], char postfix[]){

    int top = -1;
    int i = 0;
    int k = 0;

    while(infix[i] != '\0'){

        if((infix[i] >= 'A' && infix[i] <= 'Z') ||
           (infix[i] >= 'a' && infix[i] <= 'z') ||
           (infix[i] >= '0' && infix[i] <= '9')){

            postfix[k] = infix[i];
            k++;
        }

        else if(infix[i] == '('){
            top++;
            stack[top] = infix[i];
        }

        else if(infix[i] == ')'){
            while(stack[top] != '('){
                postfix[k] = stack[top];
                k++;
                top--;
            }

            if(top != -1){
                top--;
            }
        }

        else{
            while(top != -1 && ISP(stack[top]) >= ICP(infix[i])){
                postfix[k] = stack[top];
                k++;
                top--;
            }

            top++;
            stack[top] = infix[i];
        }

        i++;
    }

    while(top != -1){
        postfix[k] = stack[top];
        k++;
        top--;
    }

    postfix[k] = '\0';
}

void PretoIn(char prefix[20], char infix[20]){
    char stack[20][20];
    int top = -1;
    int i = 0;
    int k = 0;

    while(prefix[i] != '\0'){
        i++;
    }

    i--;

    while(i >= 0){

        if((prefix[i] >= 'A' && prefix[i] <= 'Z') ||
           (prefix[i] >= 'a' && prefix[i] <= 'z') ||
           (prefix[i] >= '0' && prefix[i] <= '9')){

            top++;
            stack[top][0] = prefix[i];
            stack[top][1] = '\0';
        }

        else{
            char op1[20];
            char op2[20];

            strcpy(op1, stack[top]);
            top--;

            strcpy(op2, stack[top]);
            top--;

            stack[++top][0] = '(';
            stack[top][1] = '\0';

            strcat(stack[top], op1);

            k = strlen(stack[top]);
            stack[top][k] = prefix[i];
            stack[top][k+1] = '\0';

            strcat(stack[top], op2);
            strcat(stack[top], ")");
        }

        i--;
    }

    strcpy(infix, stack[top]);
}

void PostToPre(char postfix[20], char prefix[20]){
    char stack[20][20];
    int top = -1;
    int i = 0;

    while(postfix[i] != '\0'){

        if((postfix[i] >= 'A' && postfix[i] <= 'Z') ||
           (postfix[i] >= 'a' && postfix[i] <= 'z') ||
           (postfix[i] >= '0' && postfix[i] <= '9')){

            top++;
            stack[top][0] = postfix[i];
            stack[top][1] = '\0';
        }

        else{
            char op1[20];
            char op2[20];

            strcpy(op2,stack[top]);
            top--;

            strcpy(op1,stack[top]);
            top--;

            top++;
            stack[top][0] = postfix[i];
            stack[top][1] = '\0';

            strcat(stack[top],op1);
            strcat(stack[top],op2);
        }

        i++;
    }

    strcpy(prefix,stack[top]);
}

int main(){

    char exp[20];
    char infix[20];
    char postfix[20];
    char prefix[20];
    int choice;

    printf("Enter choice of Operation to perform: \n");
    printf("1.Infix to Postfix\n 2.Prefix to Infix\n 3.Postfix to Prefix\n");
    scanf("%d",&choice);

    switch(choice){

        case 1:
        printf("Enter the valid infix expression: \n");
        scanf("%s",infix);
        IntoPost(infix,postfix);
        printf("Your Postfix expression is: \n");
        printf("%s",postfix);
        break;

        case 2:
        printf("Enter the valid prefix expression: \n");
        scanf("%s",prefix);
        PretoIn(prefix,infix);
        printf("Your Infix expression is: \n");
        printf("%s",infix);
        break;

        case 3:
        printf("Enter the valid postfix expression: \n");
        scanf("%s",postfix);
        PostToPre(postfix,prefix);
        printf("Your Prefix expression is: \n");
        printf("%s",prefix);
        break;

        default :
        printf("Exiting........");
        break;
    }

    return 0;
}