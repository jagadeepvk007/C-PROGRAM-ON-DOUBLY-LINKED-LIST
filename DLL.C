#include<stdio.h>
#include<conio.h>
struct employee
{
char ssn[15];
char name[25];
char dept[4];
char desi[10];
long int salary;
char phno[15];
struct employee *prev;
struct employee *next;
};
typedef struct employee node;
node* insertfront(node *first)
{
node *temp;
temp=(node*)malloc(sizeof(node));
printf("enter the ssn,name,dept,desi,salary,phno\n");
scanf("%s%s%s%s%ld%s",&temp->ssn,&temp->name,&temp->dept,&temp->desi,&temp->salary,&temp->phno);
temp->prev=temp->next=NULL;
if(first==NULL)
{
first=temp;
return(first);
}
temp->next=first;
temp->prev=temp;
first=temp;
return first;
}

node* insertend(node *first)
{
int i,n;
node *temp,*ptr;
temp=(node*)malloc(sizeof(node));
printf("enter no. of employee\n");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
printf("enter the ssn,name,dept,design,salary,phno of employee %d",i);
scanf("%s%s%s%s%ld%s",&temp->ssn,&temp->name,&temp->dept,&temp->desi,&temp->salary,&temp->phno);
}
temp->prev=temp->next=NULL;
if(first==NULL)
{
first=temp;
return(first);
}
ptr=first;
while(ptr->next!=NULL)
ptr=ptr->next;
ptr->next=temp;
temp->prev=ptr;
return first;
}
node* deletefront(node *first)
{
node *ptr;
if(first==NULL)
{
printf("list is empty,cannot delete\n");
return first;
}
printf("employee record deleted is %s",first->name);
ptr=first;
first=ptr->next;
free(ptr);
first->prev=NULL;
return(first);
}
node* deleteend(node *first)
{
node *ptr,*last;
if(first==NULL)
{
printf("list is empty,cant delete\n");
return(first);
}
ptr=first;
while(ptr->next!=NULL)
{
last=ptr;
ptr=ptr->next;
}
printf("employee record deleted is %s",ptr->name);
free(ptr);
last->next=NULL;
return first;
}
 void display(node *first)
 {
 node *ptr;int count=0;
 ptr=first;

 while(ptr!=NULL)
 {
 count++;
 printf("\n%s\n%s\n%s\n%s\n%ld\n%s\n",ptr->ssn,ptr->name,ptr->dept,ptr->desi,ptr->salary,ptr->phno);
 ptr=ptr->next;
 }
 printf("total no. of records is %d",count);
 }
node* doubleendedqueues(node *first)
{
int ch;
printf("\n1.insertfront\n2.insertend\n3.deletefront\n4.deleteend\n5.return\n");
while(1)
{
printf("\nenter the choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:first=insertfront(first);
break;
case 2:first=insertend(first);
break;
case 3:first=deletefront(first);
break;
case 4:first=deleteend(first);
break;
case 5:return;
}
}
return first;
}

 void main()
  {
   node *first=NULL;
   int ch,n,i;
   clrscr();
   printf("double linked list\n");
   printf("\n1.createlist\n2.insertfront\n3.insertend\n4.deletefront\n5.deleteend\n6.display\n7.to demonstrate dll as queue\n8.exit\n");
   while(1)
   {
   printf("\nenter the choice\n");
   scanf("%d",&ch);
   switch(ch)
   {
   case 1:printf("enter the number of employees\n");
   scanf("%d",&n);
   for(i=1;i<=n;i++)
   first=insertfront(first);
   break;
   case 2:first=insertfront(first);
   break;
   case 3:first=insertend(first);
   break;
   case 4:first=deletefront(first);
   break;
   case 5:first=deleteend(first);
   getch();
   break;
   case 6:display(first);
   break;
   case 7:first=doubleendedqueues(first);
   getch();
   break;
   case 8:exit();
   }
   }
   }