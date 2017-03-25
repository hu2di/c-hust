#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *f;
    int n,k;
    int *a;
    a=(int*)malloc(sizeof(int)*1000);
    while(1)
    {
    f=fopen("data.txt","w");
    printf("n=");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        a[i]=rand()%9;
        fprintf(f,"%d ",a[i]);
    }
    fclose(f);
    printf("Tiep?1/0?");
    scanf("%d",&k);
    if(!k) break;
    }
}
