#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
	int rollno;
	char name[40];
	struct student *next;
}ST;
ST *hptr=0;
void print();
void add_end(ST**);
void reverse(ST **ptr);

//int main(int argc,char *argv[])
int main()
{
	char ch;
	do{
		add_end(&hptr);
		puts("do you want another data?(Y/N)");
		scanf(" %c",&ch);
	  }while((ch=='y')||(ch=='Y'));
	print();
	reverse(&hptr);
	print();
}
void add_end(ST **ptr)
{
ST *temp=(ST*)malloc(sizeof(ST));
printf("enter the roll,name\n");
scanf("%d%s",&temp->rollno,temp->name);
//&temp->rollno=argv[1][0];
//temp->name=argv[1][1];

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
	printf("%d %s\n",ptr->rollno,ptr->name);
	ptr=ptr->next;
	}
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
}
