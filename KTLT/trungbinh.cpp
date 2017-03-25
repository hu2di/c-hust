#include<stdio.h>
int main()
{
float a[10];
float sum=0;
for (int i=0;i<10; i++)
{
scanf("%f",&a[i]);
sum=sum+a[i];
}
float avg;
avg=sum/10;
int dem=0;
for (int i=0; i<10; i++)
{
if (a[i]>avg)
dem=dem+1;
}
printf("%d",dem);
return 0;
}
