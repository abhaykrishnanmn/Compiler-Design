#include<stdio.h>
#include<string.h>
char stack[100];
int top=-1;
void push(char ch){
    if(top==100){
        printf("\nStack is full");
    }
    else{
        top++;
        stack[top]=ch;
    }
}
char pop(){
    char item;
    if(top==-1){
        printf("\nStack is empty");
    }
    else{
        item=stack[top];
        top--;
    }
    return item;
}
int isOperator(char ch){
    if(ch=='+' || ch=='-' || ch=='/' || ch=='*' || ch=='^'){
        return 1;
    }
    else
        return 0;
}
int precedence(char ch){
    if(ch=='^')
        return 3;
    else if(ch=='/' || ch=='*')
        return 2;
    else if(ch=='+' || ch=='-')
        return 1;
    return 0;
}
int isOperand(char ch){
    if((ch>=97 && ch<=122) || (ch>=65 && ch<=90)){
        return 1;
    }
    else
        return 0;
}
int main(){
    char exp[50],ch;
    char output[50];
    int i,j,len,k=0;
    printf("\nEnter the expression : ");
    scanf("%s",exp);
    len=strlen(exp);
    for(i=0;i<len;i++){
        ch=exp[i];
        if(isOperand(ch)){
            output[k++]=ch;
        }
        else if(isOperator(ch)){
            if(top==-1){
                push(ch);
            }
            else{
                char temp;
                int flag=0;
                while(top>-1 && isOperator(stack[top]) && precedence(stack[top])>=precedence(ch)){
                    temp=pop();
                    output[k++]=temp;
                }
                push(ch);
            }
        }
    }
    while(top!=-1){
        char temp=pop();
        output[k++]=temp;
    }
    printf("\nPostfix is : %s",output);
    printf("\n\nIntermediate code is : \n");
    char a,b,op,a1='\0',b1='\0';
    int c=1;
    for(i=0;i<len;i++){
        ch=output[i];
        if(isOperand(ch))
        {
            push(ch);
        }
        else if(isOperator(ch)){
            a=pop();
            if(a=='t')
                a1=pop();
            b=pop();
            if(b=='t')
                b1=pop();

            printf("\nt%d = %c%c %c %c%c",c,b,b1,ch,a,a1);
            char m=c+'0';
            push(m);
            push('t');
            c++;
        }
    }
    printf("\n");
    return 0;
}
