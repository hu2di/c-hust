#include<stdio.h>
#include<conio.h>
int ktra(int n)
{
    while (n>=10)
    {
        n = n/10;
    }
    if (n%2 == 0) return 1;
    return 0;
}
int main()
{
    int n = 0;
    int i = 0;
    int a[100];
    printf("So phan tu: ");
    scanf("%d",&n);
    for (i = 0; i < n; i++)
    {
        printf("\nA[%d]=",i+1);
        scanf("%d",&a[i]);
    }
    printf("Xu li:\n");
    for (i = 0; i < n; i++)
    {
        if (ktra(a[i])==1)
        printf("%d\n",a[i]);
    }
    return 0;
}
