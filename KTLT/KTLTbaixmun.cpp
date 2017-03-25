#include<stdio.h>
int n;
void nhap(float *a,int *n);
float value(float *a,int n);
int main(){
    float a[10];
    nhap(a,&n);
    printf("Gia tri da thuc: ",value(a,n));
    return 0;
}

void nhap(float *a,int *n){
    int i;
    do
    {
    printf("\n\nNhap bac cua da thuc: ");
    scanf("%d\n",*n);
    }   while(*n>100);
    for(i=*n;i>=0;i--)
    {
        printf("\nNhap a%d=",i);
        scanf("%f",&a[i]);
    }
    while(a[*n]==0)
        *n=*n-1;
}

float value(float *a,int n)
{
    float s,x;
    int i=0;
    printf("\nTinh gia tri da thuc tai x=  ");
    scanf("%f",&x);
    s=a[n]*x+a[n-1];
    for(i=2;i<=n;i++)
    {
        s=s*x+a[n-i];
    }
    return s;
}
