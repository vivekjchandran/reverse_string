//linked list 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student
{
	char name[40];
	struct student *next;
}ST;
ST *hptr=0;
void print();
void add_end(ST**,char*);
void reverse(ST **ptr);

int main(int argc,char *argv[])
{
	char ch;
		add_end(&hptr,argv[1]);
	reverse(&hptr);
	print();
}
void add_end(ST **ptr,char nam[20])
{
ST *temp=(ST*)malloc(sizeof(ST));
strcpy(temp->name,nam);
if(*ptr==0){
	temp->next=*ptr;
	*ptr=temp;
	}
else{
	ST *last=*ptr;
	while(last->next!=0)
	last=last->next;

	temp->next=last->next;
	last->next=temp;
	}
}
void print()
{
ST *ptr=hptr;
while(ptr!=0){
	ptr=ptr->next;
	}
printf("%s\n",hptr->name);
}


void reverse(ST **ptr)
{
	ST *q=0,*r;
	while(*ptr)
	{
		r=q;
		q=*ptr;
		*ptr=(*ptr)->next;
		q->next=r;
	}
	*ptr=q;
int n=strlen(hptr->name);
char ch;
for(int i=--n,j=0;j<i;i--,j++)
{
ch=hptr->name[i];
hptr->name[i]=hptr->name[j];
hptr->name[j]=ch;

}
}
