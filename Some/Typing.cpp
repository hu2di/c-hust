#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
#define BELL 7
#define TRUE 1
#define XSTART 10
#define XSPACE 6
#define LINE1 9
#define LINE2 18
typedef struct{
char ch;
unsigned y,x;
unsigned cost;
} Alphatab;
Alphatab letter[26] =
{
    {'Q',22,3,0},{'W',22,9,0},{'E',22,15,0},{'R',22,21,0},{'T',22,27,0},{'Y',22,33,0},
    {'U',22,39,0},{'I',22,45,0},{'O',22,51,0},{'P',22,57,0},{'A',23,8,0},{'S',23,14,0},
    {'D',23,20,0},{'F',23,26,0},{'G',23,32,0},{'H',23,38,0},{'J',23,44,0},{'K',23,50,0},
    {'L',23,56,0},{'Z',24,13,0},{'X',24,19,0},{'C',24,25,0},{'V',24,31,0},{'B',24,37,0},{'N',24,43,0},{'M',24,49,0}
};
char buff[1];
void Drawtable();
int Getrandom(int min, int max);
int Choozenletter();
void Shoot(int y,int pos,int hit);
void Printletter(int ypos,int i,int delayt);
void Blast (int i);
void Back(int yr,int pos);
void Ttgame(int level, int delayt);
int main()
{
    const unsigned dl[5] = {160,120,90,60,30};
    int ch,d;
    do
    {
        _setcursortype(_NORMALCURSOR);
        textattr(30);
        clrscr();
        gotoxy (26,10); printf("Chuong trinh tap danh may");
        gotoxy (10,25); printf("Touch v1.0");
        gotoxy(32,12); printf("1.Chon muc choi");
        gotoxy(32,14); printf("2.Thoat");
        ch = getch();
        switch (ch)
        {
            case '1':
            gotoxy(30,20); printf("Level (1..5):");
            scanf("%d",&d);
            if ((d>0)&&(d<6))
            {
                Drawtable();
                Ttgame(d,dl[d-1]);
            }
            break;
            case '2':
            ch=27;
            break;
        }
    }
	while (ch!=27)
}
void Drawtable()
{
    int i;
    textbackground(BLUE);
    textcolor(WHITE);
    window(1,1,80,25);
    clrscr();
    for (i=0;i<=LINE1;++i)
    {
        gotoxy(letter[i].x+XSTART,letter[i].y);
        sprintf(buff,"%c",letter[i].ch);
        cputs(buff);
    }
    for (i=LINE1+1;i<=LINE2;++i)
    {
        gotoxy(letter[i].x+XSTART,letter[i].y);
        sprintf(buff,"%c",letter[i].ch);
        cputs(buff);
    }
    for (i=LINE2+1;i<=25;++i)
    {
        gotoxy(letter[i].x+XSTART,letter[i].y);
        sprintf(buff,"%c",letter[i].ch);
        cputs(buff);
    }
}

int Getrandom(int min, int max)
{
    return(random(max-min)+min);
}

int Choozenletter()
{
    int choice;
    int i, subscript=0,maxcost=0,num=0;
    int flag=0;
    for (i=0;i<=25;++i)
    if (letter[i].cost>maxcost)
    {
        subscript=i;
        maxcost=letter[i].cost;
        num++;
    }
    if (maxcost==0&&num==0)
    choice=Getrandom(0,26);
    else
    if (subscript==25)
    choice=Getrandom(22,26);
    else choice=Getrandom(subscript-1,subscript+1);
    textbackground(RED);
    textcolor(WHITE);
    gotoxy(XSTART+letter[choice].x,letter[choice].y);
    sprintf(buff,"%c",letter[choice].ch);
    cputs(buff);
    return choice;
}

void Printletter(int ypos,int i,int delayt)
{
    textbackground(BLUE);
    textcolor(WHITE);
    gotoxy(XSTART+letter[i].x,ypos - 1);
    sprintf(buff," ");
    cputs(buff);
    gotoxy(XSTART+letter[i].x,ypos );
    printf("%c",letter[i].ch);
    delay(delayt);
}

void Blast(int i)
{
    int j;
    textbackground(BLUE);
    textcolor(WHITE);
    gotoxy(XSTART+letter[i].x,letter[i].y);
    printf("*");
    delay(50);
    gotoxy(XSTART+letter[i].x-3,letter[i].y);
    printf("#.....#");
    delay(50);
    printf("%c",BELL);
    gotoxy(XSTART+letter[i].x-3,letter[i].y);
    printf("       ");
    delay(5);
    gotoxy(XSTART+letter[i].x,letter[i].y);
    printf("%c",letter[i].ch);
    textbackground(BLUE);
    textcolor(WHITE);
    gotoxy(XSTART+letter[i].x,letter[i].y);
    sprintf(buff,"%c",letter[i].ch);
    cputs(buff);
}

void Shoot(int yr, int pos, int hit)
{
    int i,j;
    char rocket='3';
    char bom[]="A/3\A/3\A/3\A/3\A/3\A+";
    textbackground(BLUE);
    textcolor(WHITE);
    for (i=letter[pos].y-1;y>=3;--i)
    {
        gotoxy(XSTART+letter[pos].x,i);
        printf(buff,"%c",rocket);
        cputs(buff);
        delay(5);
        gotoxy(XSTART+letter[pos].x,i);
        printf(buff," ");
        cputs(buff);
        if (i==yr && hit)
        {
            textbackground(BLUE);
            textcolor(RED);
        gotoxy(XSTART+letter[pos].x,yr+1);
        sprintf(buff," ");
        cputs(buff);
        for (j=0;j<strlen(bom);j++)
        {
        gotoxy(XSTART+letter[pos].x,yr);
        sprintf(buff,"%c",bom[j]);
        cputs(buff);
        delay(30);
        }
        gotoxy(XSTART+letter[pos].x,yr);
        sprintf(buff," ");
        cputs(buff);
        }
    }
}

void Back(int yr,int pos)
{
    textbackground(BLUE);
    textcolor(WHITE);
    gotoxy(XSTART+letter[pos].x,letter[pos].y);
    sprintf(buff,"%c",letter[pos].ch);
    cputs(buff);
    if (letter[pos].cost>0) --letter[pos].cost;
}

#define YSTATUS 2
#define XSTATUS 50
#define SCORE XSTATUS+22

void Ttgame(int level,int delayt)
{
    int pressed=0,shutdown=0,keyhit=0,score=0;
    char c;
    int pos,ypos,jc;
    _setcursortype(_NOCURSOR);
    randomize();
    gotoxy(XSTATUS,YSTATUS);
    printf("Level: %d Errors: ",level);
    do
    {
        Start: ;
        pos=Choozenletter();
        ypos=3;
        pressed=0;
        keyhit=0;
        while(1)
        {
            if (kbhit())
            {
                pressed=1;
                c=getch();
                if (c==27) return;
                c=toupper(c);
                if (letter[pos].ch==c)
                    {
                    Shoot(ypos,pos,1);
                    keyhit=1;
                    Back(ypos,pos);
                    if (letter[pos].cost>0) --letter[pos].cost;
                    goto Start;
                    }
            else
            {
                Shoot(ypos,pos,0);
                printf("%c",BELL);
                ++score;
                gotoxy(SCORE,YSTATUS);
                printf ("%d",score);
            }
            }
        if (ypos==letter[pos].y)
        {
            Blast(pos);
            ++letter[pos].cost;
            ++score;
            gotoxy(SCORE,YSTATUS);
            printf("%d",score);
            goto Start;
        }
        ++ypos;
        Printletter(ypos,pos,delayt);
    }
    }while (shutdown==0)
}
