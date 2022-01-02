// $ gcc linked_list.c -o linked_list
// $ ./linked_list

#include<stdio.h>
struct node
{
int data;
struct node *next;
};
struct node *first,*temp,*prev;
struct node *creation(struct node *first);
struct node *insertion(struct node *first);
struct node *deletion(struct node *first);
void display(struct node *first);
void findelement(struct node *first);

void main()
{
int choice;
printf("\n List using pointers");
do
{
printf("\n Menu \n 1.Create \n 2.Insert\n 3.Delete\n 4.Element search\n 5.Make empty\n 6.Display\n 7.Exit \n Enter your choice");
scanf("%d",&choice);
switch(choice)
{
case 1:
 printf("\n Type 999 to stop");
 first=creation(first);
 printf("\nList is");
 display(first);
break;
 case 2:
  first=insertion(first);
  printf("\n List is");
  display(first);
  break;
 case 3:
  first=deletion(first);
  printf("\n List is");
  display(first);
  break;
 case 4:
  findelement(first);
  break;
  case 5:
  first=NULL;
  printf(“\nList is empty”);
  break;
  case 6:
  display(first);
  break;
  case 7:
  exit(0);
  break;
  }
}while(choice<=7);
  }
 
 struct node *creation(struct node *first)
  {
  int item;
  prev=first=NULL;
  printf("\n Enter the data item");
  scanf("%d",&item);
  while(item!=999)
  {
  temp=(struct node*)malloc(sizeof(struct node));
  temp->data=item;
  temp->next=NULL;
  if(first==NULL)
  first=temp;
  else
  prev->next=temp;
  prev=temp;
  printf("\n Enter the data element");
  scanf("%d",&item);
  }
  return(first);
  }
  struct node *insertion(struct node *first)
  {
  struct node *newnode,*temp;
  int item,pos,i;
  printf("Enter the data & position");
  scanf("%d%d",&item,&pos);
  newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=item;
  if((pos==1)||(first==NULL))
  {
  newnode->next=first;
  first=newnode;
  }
  else
  {
   i=2;
  temp=first;
  while((i<pos)&&(temp->next!=NULL))
  {
  temp=temp->next;
  i++;
  }
  newnode->next=temp->next;
  temp->next=newnode;
  }
  return(first);
  }
 
 struct node *deletion(struct node *first)
  {
  int x;
  printf("\n Enter the data to be selected");
  scanf("%d",&x);
  if(first==NULL)
  printf("\n List is empty");
  else
  {
  prev=NULL;
  temp=first;
  while((temp!=NULL)&&(temp->data!=x))
  {
  prev=temp;
  temp=temp->next;
  }
  if(temp==NULL)
  printf("\n Match not found");
  else if(prev==NULL)
  first=first->next;
else
  prev->next=temp->next;
  }
  return(first);
  }
 
void display(struct node *first)
  {
  temp=first;
  if(first==NULL)
  printf("\n List is empty");
  else
  {
  while(temp->next!=NULL)
  {
  printf("|%d| -->",temp->data);
  temp=temp->next;
  }
   } printf("|%d|--->NULL",temp->data);
   }
  
void findelement(struct node *first)
  {
  int x,i=1;
  printf("\n Enter the position");
  scanf("%d",&x);
  if(first==NULL)
  printf("\n First is empty");
  else
  {
  prev=NULL;
  temp=first;
  while((temp!=NULL)&&(i!=x))
  {
  prev=temp;
  temp=temp->next;
  i++;
  }
  if(temp==NULL)
  printf("\n Match not found");
  else
  printf("\n%d is found at %d",temp->data,x);
  }
}
 
