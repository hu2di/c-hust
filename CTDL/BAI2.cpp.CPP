#include <conio.h>
#include <stdio.h>
FILE *f1;
int m,n,a[100][100];
/************************/
void nhap(){
int i,j;
f1=fopen("input2.txt","rt");
fscanf(f1,"%d",&m);
fscanf(f1,"%d",&n);
for (i=0;i<m;i++) {
for (j=0;j<n;j++) {fscanf(f1,"%d",&a[i][j]); printf("%d  ",a[i][j]);} printf("\n"); }
fclose(f1);
}
/************************/
int hang(){
int i,j,tg,max;
max=0;
for (i=0;i<m;i++)
	{
	if (a[i][0]==1) tg=1; else tg=0;  if (max<tg) max=tg;
	for (j=1;j<n;j++)
		{
		if (a[i][j]==1) tg=tg+1;
		if (a[i][j]==0) tg=0;
		if (max<tg) max=tg;
		}
	}
return max;
}
/***********************/
int cot(){
int i,j,tg,max;
max=0;
for (j=0;j<n;j++)
	{
	if (a[0][j]==1) tg=1; else tg=0;   if (max<tg) max=tg;
	for (i=1;i<m;i++)
		{
		if (a[i][j]==1) tg++;
		else tg=0;
		if (max<tg) max=tg;
		}
	}
return max;
}
/***********************/
int main(){
int a,b;
nhap();
a=hang();
b=cot();

if (a>b) printf("Doan chua so 1 dai nhat la %d",a);else printf("Doan chua so 1 dai nhat la %d",b);
getch();
}
