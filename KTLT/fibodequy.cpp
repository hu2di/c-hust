#include<stdio.h>
unsigned long long fibo(int n);
int main()
{
int n;
scanf("%d",&n);
printf("%llu",fibo(n));
return 0;
}
unsigned long long fibo(int n)
{
if (n==1) return 1;
else
if (n==2) return 1;
else
return fibo(n-1)+fibo(n-2);
}
