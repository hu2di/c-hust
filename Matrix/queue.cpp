#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct PRIORITY_QUEUE * pNode;
struct PRIORITY_QUEUE
{
char data;
int priority;
pNode link;
struct PRIORIT_QUEUE;
};
void enqueue(pNode *front,pNode *rear,pNode*newNode)
{
if(*rear)
{
(*rear)->link=*newNode;
*rear=*newNode;
}
else
{
*rear=*newNode;
*front=*newNode;
}
}
void addQueue(pNode *front,pNode *rear)
{
char data;
int priority;
pNode link;
pNode ptr;
ptr=new(PRIORITY_QUEUE);
strcpy(ptr->data,data);
ptr->priority=priority;
ptr->link=NULL;
enqueue(front,rear,&ptr);
}
int main()
{
pNode front=NULL,rear=NULL;
addQueue(&front,&rear);
return 0;
}
