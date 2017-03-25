#include <conio.h>
#include <malloc.h>
#include <string.h>
#include<stdio.h>
void input (char str[]);
void output (char str[]);
void kt (char str[]);

int main ()
{
char *str;
str=(char*)malloc(100*sizeof(char));//do dai chuoi
if(str==NULL)//dieu kien
{
printf("Khong du bo nho cap phat!");
exit(1);
}
input(str);
output(str);
kt(str);
getch();
}
void input (char str[])
{
printf ("\nNhap chuoi: ");
fflush(stdin);
gets(str);
}
void output (char str[])
{
puts (str);
}
void kt (char str[])
{
char st;
char *vitri; char *chuoi=str;
int dem=0;
printf ("\nNhap chuoi can kiem tra: ");
fflush(stdin);
scanf("%c",&st);
do
{
vitri= strchr(chuoi,st);
if (vitri!=NULL)
{
dem++;
printf ("\nChuoi '%c' ==> xuat hien tu vi tri thu %d trong chuoi <%s> ",st,vitri-str,str);
}
chuoi=vitri+1;
}
while (vitri!=NULL);
if(dem!=0) printf("\nki tu '%c' xuat hien %d lan trong chuoi vua nhap.\n", st, dem);
else printf("\nKi tu '%c' ko xuat hien trong chuoi vua nhap.\n",st);
}
