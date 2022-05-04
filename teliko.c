#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Case{
	char name[30];
	char surname[30];
	int age;
	int sex;
	char disease[30];
	int date;
	struct Case *next;
};
struct Case *head;
void add(char n[30],char sn[30],int a,int s,char dis[30], int d)
{
	struct Case *temp;
	temp=(struct Case *)malloc(sizeof(struct Case));
	if(!temp)
	{
		printf("Error alocating mempry..");
	}
	strcpy(temp->name,n);
	strcpy(temp->disease,dis);
	strcpy(temp->surname,sn);
	temp->age=a;
	temp->sex=s;
	temp->date=d;
	if(head==NULL)
	{
		temp->next=NULL;
		head=temp;
	}
	else
	{
		temp->next=head;
		head=temp;
	}
	
}
int count()
{   
    int count=0;
	struct Case *r;
	r=head;
	while(r!=NULL)
	{
		count++;
		r=r->next;
	}
	return count;
	
}

void display()
{
	struct Case *r;
	r=head;
	if (r==NULL)
	   return;
	printf("Names of all cases:\n");
	printf("----------------------------\n");
	printf("NAME\t\tSURNAME\n");
	printf("----------------------------\n");
	
	while(r!=NULL)
	{
		printf("%s\t",r->name);
		printf("%s\n",r->surname);
		r=r->next;
	}
	printf("----------------------------\n");
	
}

int main()
{   
  while(1)
  {

	int choice,age,sex,date;
	char disease[30],name[30],surname[30];
	printf("\t\tMENU\n");
	printf("*************************************\n");
	printf("Enter 1: to add a case\n");
	printf("Enter 2: to count cases\n");
	printf("Enter 3: to print names of all cases\n");
	printf("Enter 4: to exit\n");
	printf("*************************************\n");
	printf("Please,give your choice:\n");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			
			printf("Enter first name: ");
			scanf("%s",name);
			printf("Enter last name: ");
			scanf("%s",surname);
			printf("Enter age: ");
			scanf("%d",&age);
			printf("Enter sex (0 for man or 1 for woman): ");
			scanf("%d",&sex);
			printf("Enter if there is any underlying disease: ");
			scanf("%s",disease);
			printf("Enter the record date(united): ");
			scanf("%d",&date);
			add(name,surname,age,sex,disease,date);
			printf("Case added!\n");
			break;
		case 2:
			printf("There are : %d cases\n",count());
			break;
		case 3:
			display();
			break;
		case 4:
			printf("Bye bye!!\n");
			return 0;
		default:
			printf("You entered invalid number...\n");
    }
			
			
	}
}
