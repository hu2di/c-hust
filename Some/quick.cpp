#include<stdio.h>
#include<conio.h>
void hoanvi(int &a,int &b)
{
int temp = a;
a = b;
b = temp;
}
void quick_sort(int mang[],int left,int right)
{
int i = left;
int j = right;
int k = (left+right)/2;
while(i<=j)
{
while(mang[i]<mang[k])i++;
while(mang[j]>mang[k])j--;
hoanvi(mang[i],mang[j]);
i++;
j--;
}
if(i>=j) hoanvi(mang[j],mang[k]);
if(j>left) quick_sort(mang,left,j);
if(i<right) quick_sort(mang,i,right);
}
int main()
{
int mang[10] = {42,23,74,11,65,58,94,36,99,87};
quick_sort(mang,0,9);
for(int i = 0;i<10;i++)
{
printf("%d ",mang[i]);
}
getch();
return 0;
}
