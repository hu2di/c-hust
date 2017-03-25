#include<stdio.h>

int main()
{

int n, i, fib1 = 1, fib2 = 1, fib = 2;
printf("\nNhap gia tri so can kiem tra N= : ");
scanf("%d", &n);

while (fib1+fib2 <= n)
{
fib = fib1 + fib2;
fib2 = fib1;
fib1 = fib;
}

if( fib==n) printf("so %d vua nhap la so fibonacci",n);
else printf("so %d vua nhap khong phai la so fibonacci",n);


return 0;
}
