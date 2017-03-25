#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
int A[]={1,2,3};
int kq[]={0,0,0};
int n;
void Inkq()
{
int i;
printf(" kq:");
for(i=0;i<n;i++)
printf(" %d", kq[i]);
printf(" \n");
}
int UCV(int ai, int kq[], int k, int n)
{
int i;
for(i=0;i<k-1; i++)
{
if(kq[i]==ai) return 0;
}
return 1;
}
void hienthihv(int A[], int kq[], int k, int n)
{
int i;
for(i=0;i<n;i++)
{
if(UCV(A[i],kq,k,n)==1)
{
kq[k-1] = A[i];
if(k==n) Inkq();
else hienthihv(A, kq, k+1, n);
}
}
}
int main()
{
n=3;
hienthihv(A,kq,1,n);
getch();
return 1;
}
