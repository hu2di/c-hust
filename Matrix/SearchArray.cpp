#include<stdio.h>
int main()
{
    int n;
    printf("Nhap n: ");
    scanf("%d",&n);
    int a[n];
    printf("Nhap day: ");
    for(int i=1;i<=n;i++)
    scanf("%d",&a[i]);
    printf("Nhap vi tri: ");
    int i;
    scanf("%d",&i);
    int j;
    scanf("%d",&j);
    int min=a[i];
    for (int d=i;d<=j;d++)
    if (a[d]<min) min=a[d];
    printf("Result: %d",min);
	return 0;
}

