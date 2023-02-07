#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char exps[20][100];
char hash_table[20][100];
int hash[20],r=0,t=0;
int isOperator(char ch){
if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
return 1;
return 0;
}
int constant_checker(char test_exp[],int m){
int len=strlen(test_exp),k=0;
char buffer[10];
bzero(buffer,10);
for(int j=(m+1);j<len;j++){
if(!isdigit(test_exp[j])){
return 0;
}
buffer[k++]=test_exp[j];
}
return atoi(buffer);
}
void replace_operands(char test_exp[],int i,int index){
int len=strlen(test_exp),k=0;
char buffer[100];
bzero(buffer,100);
for(int j=0;j<=i;j++){
buffer[k++]=test_exp[j];
}
for(int j=i+1;j<len;j++){
char ch=test_exp[j];
if(isOperator(ch) || isdigit(ch) || ch=='='){
buffer[k++]=ch;
}
else{
char temp[2];
char ch_val[10];
temp[1]='\0';
temp[0]=test_exp[j];
int flag=0;
for(int y=0;y<20;y++){
if( (strcmp(temp,hash_table[y]))==0){
flag=1;
sprintf(ch_val,"%d",hash[y]);
strcat(buffer,ch_val);
k=k+strlen(ch_val);
break;
}
}
if(flag==0){
buffer[k++]=ch;
}
}
}
strcpy(exps[index],buffer);
}
void store_constant(char test_exp[],int val){
char buffer[20];
int k=0;
bzero(buffer,20);
for(int i=0;i<strlen(test_exp);i++){
if(test_exp[i]=='=')
break;
buffer[k++]=test_exp[i];
}
strcpy(hash_table[r++],buffer);
hash[t++]=val;
}
void main(){
int n;
char exp1[100];
printf("\nEnter number of expressions : ");
scanf("%d",&n);
for(int i=0;i<n;i++){
bzero(exps[i],100);
scanf("%s",exps[i]);
}
for(int i=0;i<n;i++){
strcpy(exp1,exps[i]);
for(int j=0;exp1[j]!='\0';j++){
if(exp1[j]=='='){
int val=constant_checker(exp1,j);
if(val!=0){
store_constant(exp1,val);
break;
}
else{
replace_operands(exp1,j,i);
break;
}
}
}
}
printf("\nOptimized expressions are\n");
for(int i=0;i<n;i++){
	if(constant_checker(exps[i],1)!=0)
	{
		continue;
	}
	printf("%s\n",exps[i]);
}
}

