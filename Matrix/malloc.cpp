#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *f;
    f=fopen("out.txt","w");
    long n;
    int *a;
    a = (int*)malloc(sizeof(int)*1000000);
	printf("n = ");
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
	    a[i]=rand()%1000;
	    fprintf(f,"A[%d] = %d",i,a[i]);
        fprintf(f,"\n");
	}
	fclose(f);
	return 0;
}
