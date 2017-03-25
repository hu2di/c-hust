#include<stdio.h>
#include<conio.h>
int main()
{
int i,n;
double a=1.0,e=0.0;
scanf("%d",&n);
for(i=1;i<=n;i++)
{
a = a *(1.0/i);
e = e + a;
}
printf("%2.4f",e);
getch();
}
