#include<stdio.h>
#include <conio.h>
#include <math.h>
int NgTo( long long n)
{
if(n<2) return 0;
if(n==2) return 1;
long long i=2;
long long k= (long long)sqrt(n);
while ((i<=k) && (n%i!=0)) i++;
if(n%i!=0) return 1;
else return 0;
}
int main()
{
long long n,i,m,p,q;
printf("Nhap so nguyen duong:");
scanf("%lld",&n);

if((n%2!=0)&&(n>2)) printf("%lld khong la tong cua 2 so nguyen to",n); else
{
m= n/2;
for(i=3;i<=m;i=i+2)
if(NgTo(n-i)&&NgTo(i))
{
p=i;
q= n-i;
printf("%lld la so ma tong la 2 so nguyen to p= %lld va q= %lld \n",n,p,q);
break;
}
else continue;
}

getch();
}
