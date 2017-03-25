#include <windows.h>
#include <stdio.h>
#include <conio.h>
int i,j,x=0;char q;

void intrangdong(int a){
	int j;
	for (j=0;j<a;j++)printf(" ");}
	
void xoatrang(){
	int j;
	for(j=0;j<25;j++)intrangdong(80);}


void c(WORD color)
{ 
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0; wAttributes |= color;
    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void T2(){q=getch(); x=1;}
int main(){
	system("color fa");
	HANDLE h1; DWORD Id;
	int a,b;char y='\3';
	h1=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)T2,NULL,0,&Id);

while(x!=1){Sleep(50);
	for(i=0;i<5;i++){for(j=0;j<67;j++){c(10);printf("%c",y);}printf("\n");}
	a=0;b=0;
	for(i=0;i<5;i++){
		for(j=0;j<11-a;j++){c(10);printf("%c",y);}
		for(j=11-a;j<21+b;j++){c(12);printf("%c",y);}
		for(j=21+b;j<46-b;j++){c(10);printf("%c",y);}
		for(j=46-b;j<56+a;j++){c(12);printf("%c",y);}
		for(j=56+a;j<67;j++){c(10);printf("%c",y);}
		printf("\n");a++;b+=2;}
		a=0;
	for(i=0;i<4;i++){
		for(j=0;j<6;j++){c(10);printf("%c",y);}
		for(j=6;j<30+a;j++){c(12);printf("%c",y);}
		for(j=30+a;j<37-a;j++){c(10);printf("%c",y);}
		for(j=37-a;j<61;j++){c(12);printf("%c",y);}
		for(j=61;j<67;j++){c(10);printf("%c",y);}
		printf("\n");a++;}
	a=0;
	for(i=0;i<6;i++){
		for(j=0;j<6+a;j++){c(10);printf("%c",y);}
		for(j=6+a;j<61-a;j++){c(12);printf("%c",y);}
		for(j=61-a;j<67;j++){c(10);printf("%c",y);}
		printf("\n");a++;}
		a=0;
	for(i=0;i<10;i++){
		for(j=0;j<12+a;j++){c(10);printf("%c",y);}
		for(j=12+a;j<55-a;j++){c(12);printf("%c",y);}
		for(j=55-a;j<67;j++){c(10);printf("%c",y);}
		printf("\n");a+=2;}a=0;
	for(i=0;i<3;i++){
		for(j=0;j<31+a;j++){c(10);printf("%c",y);}
		for(j=31+a;j<36-a;j++){c(12);printf("%c",y);}
		for(j=36-a;j<67;j++){c(10);printf("%c",y);}
		printf("\n");a++;}
	for(i=0;i<5;i++){for(j=0;j<67;j++){c(10);printf("%c",y);}printf("\n");}}
	return 0;}
		



