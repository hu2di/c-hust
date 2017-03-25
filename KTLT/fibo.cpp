#include<stdio.h>
int main()
{
int n;
scanf("%d",&n);
unsigned long long f=0,f1=1,f2=1;
if ((n==1)or(n==2)) f=1;
else
for (int i=3;i<=n;i++)
{
    f=f1+f2;
    f1=f2;
    f2=f;
}
printf("%lld",f);
return 0;
}
