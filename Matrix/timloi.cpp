#include<stdio.h>
#include<conio.h>
#include<string.h>
struct sinhvien
{
    char *ten;
    float diem;
};
int main()
{
int i=1,j,k,a;
float d;
int sx[100],z[100];
char t[30];
struct sinhvien sv[100];
//Nhap thong tin sinh vien
printf("Ban hay nhap diem cho sinh vien.\nKet thuc bang cach nhap '0' vao ten sv.\n");
do
{
printf("Nhap ten sinh vien thu [%d]:",i);
fflush(stdin);
gets(sv[i].ten);
printf("Nhap diem cua sinh vien:");
scanf("%f",&sv[i].diem);
i++;
}
while(sv[i].ten != "0");
//Sap xep sinh vien
for(j=0;j<i;j++){
d=sv[j].diem;
for(k=0;k<=j;k++){
if(z[k]=1)continue;
if(d<sv[k].diem){
d=sv[k].diem;
a=k;
}
}
sx[j]=a;//danh so thu tu
}
/*In ra man hinh*/
printf("Bang diem xep tu cao toi thap");
printf("|STT| \t TEN \t \t \t|Diem|\n");
for(j=0;j<i;j++){
printf("|%3d|%30c|%5.1f|\n",j+1,sv[j].ten,sv[j].diem);
}
getch();
}
