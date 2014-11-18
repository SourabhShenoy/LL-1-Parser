
// Name: LL(1) Parser
// Description:This program simulates the LL(1) Parsing Action
// By: Sourabh S Shenoy

#include<stdio.h>
#include<conio.h>
#include <string.h>
//char nt[]={'E','A','T','B','F'},ter[]={'i','+','*','(',')','$'};
char nt[]={'B','C'},ter[]={'e','b','s','$'};
//char arr[20][20][20]={
//			{"TA"," "," ","TA"," "," "},
//			{" ","+TA"," "," ","#","#"},
//			{"FB"," "," ","FB"," "," "},
//			{" ","#","*FB"," ","#","#"},
//			{"i"," "," ","(E)"," "," "}
//		 };
char arr[20][20][20]={
			{"CC"," "," "," "},
			{"ebs"," "," ","#"}
		 };

char ipstr[20];
char stack[40],prod[10];
int i=0,top=1,ia,ix;
void main(void )
{
	void pop();
	void push(char );
	int resolve_nt(char );
	int resolve_t(char );
	void advance();
	char a,x;
	int len,temp,k;
	//clrscr();
	stack[0]='$';
	stack[1]='B';
	printf("PRODUCTIONS : \nE -> TA\nA -> A+T\nT -> FB\nB -> B*F\nF -> i/(E)\n");
	printf("\nENTER THE INPUT STRING AND END IT WITH $:\n");
	scanf("%s",ipstr);
	printf("I/P String\t\tStack Contents\t\tProduction Used\n");
	while(1)
	{
		a=ipstr[i];
		x=stack[top];
		/*To display the input string*/
		for(k=i;ipstr[k]!='$';k++)
			printf("%c",ipstr[k]);
		printf("$\t\t");
		if(x==a)
		{
			if(x=='$')
			{
				printf("\rinput string is accepted");
				break;
			}
			else
			{
				pop();
				advance();
			}
		}
		else if(isupper(x))
		{
			ix=resolve_nt(x);
			ia=resolve_t(a);
			strcpy(prod,arr[ix][ia]);
			len=strlen(prod);
			pop();
			for(k=1;k<=len;k++)
				push(prod[len-k]);
			if(stack[top]=='#')
				pop();
		}
		else
		{
			printf("Error: Could not parse the input string");
			break;
		}
		/*To display the stack contents and the production used*/
		for(k=0;k<=top;k++)
			printf("%c",stack[k]);
		printf("\t\t\t\t%s\n",prod);
	}
getch();
}
void push(char t)
{
	top+=1;
	stack[top]=t;
}
void pop()
{
	top--;
}
void advance()
{
	i++;
}
int resolve_nt(char t)
{
	int k,index;
	for(k=0;k<2;k++)
	{
		if(t==nt[k])
		{
			index=k;
			break;
		}
	}
	return index;
}
int resolve_t(char t)
{
	int k,index;
	for(k=0;k<4;k++)
	{
		if(t==ter[k])
		{
			index=k;
			break;
		}
	}
	return index;
}

