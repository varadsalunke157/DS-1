#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int stack[20];

void PostEval(char postfix[]){
    int top=-1;
    int i=0;
    int op1,op2,result;

    while(postfix[i]!='\0'){

        if(postfix[i]>='0' && postfix[i]<='9'){
            top++;
            stack[top]=postfix[i]-'0';
        }

        else{
            op2=stack[top];
            top--;

            op1=stack[top];
            top--;

            switch(postfix[i]){

                case '+':
                result=op1+op2;
                break;

                case '-':
                result=op1-op2;
                break;

                case '*':
                result=op1*op2;
                break;

                case '/':
                result=op1/op2;
                break;

                case '%':
                result=op1%op2;
                break;

                case '^':
                result=pow(op1,op2);
                break;

            }

            top++;
            stack[top]=result;
        }

        i++;
    }

    printf("Result of postfix expression is: %d\n",stack[top]);
}

int main(){

    char postfix[20];

    printf("Enter the postfix expression: \n");
    scanf("%s",postfix);

    PostEval(postfix);

    return 0;
}