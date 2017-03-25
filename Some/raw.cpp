#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<dos.h>
#include<math.h>
#include<ctype.h>
#define MAX 10
#define DONG 10
#define DELAY 200
#define DONGM 6
#define DONGB 13
#define DONGC 20
#define DONGR 20
int DONG0=DONGR,DONG1=DONGR,DONG2=DONGR,DONG3=DONGR,DONG4=DONGR,DONG5=DONGR,DONG6=DONGR,DONG7=DONGR,DONG8=DONGR,DONG9=DONGR;
int m0[MAX],m1[MAX],m2[MAX],m3[MAX],m4[MAX],m5[MAX],m6[MAX],m7[MAX],m8[MAX],m9[MAX];
int i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
int a[MAX],b[MAX],c[MAX],A[MAX];
int cot=(80-5*MAX)/2;
void menutanggiam(char* cl)
{
	char c;
	int i,j;
	///////////////////thao tac di chuyen chuot/////////////////////////////////////////////////
	i=1,j=24;
	gotoxy(1,24);printf("Xep tang dan.");
	gotoxy(1,25);printf("Xep giam dan.");
	do
	{
		gotoxy(i,j);
		switch(j)
		{
			case 24:textcolor(WHITE+BLINK);cprintf("Xep tang dan.");break;
			case 25:textcolor(WHITE+BLINK);cprintf("Xep giam dan.");break;
		}
		c=getch();
		if(c==0||c==13)
		{
			if(c==0) c=getch();
			if(c==72)
			{
				if(j==25)
				{
					gotoxy(1,25);textcolor(11);cprintf("Xep giam dan.");
					j--;
				}
			}
			if(c==80)
			{
				if(j==24)
				{
					gotoxy(1,24);textcolor(11);cprintf("Xep tang dan.");
					j++;
				}
			}
			if(c==13)
			{
				if(j==24)
				{
				    *cl='T';
				    gotoxy(1,24);textcolor(11);cprintf("             ");
				    gotoxy(1,25);cprintf("Dang sap tang dan.");
				}
				if(j==25)
				{
				    *cl='G';
				    gotoxy(1,24);textcolor(11);cprintf("             ");
				    gotoxy(1,25);cprintf("Dang sap giam dan.");
				}
				break;
			}
		}
		if(c==27)
		{
		   *cl=27;break;
		}
	}while(c!=13&&c!=27);
}
	///////////////////////////////////////////////////////////////////////////////////////////////////////
void doicho(int i,int j)     ///////// 2 vi tri cung do cao
{
	int xi=cot+2+i*5;
	int yi=DONG+1;
	int xj=cot+2+j*5;
	int yj=DONG+1;
	int xdest=xj;
	int k;
	textcolor(YELLOW);
	for(k=0;k<2;k++)
	{
		gotoxy(xi,yi--);cprintf("  ");
		gotoxy(xi,yi);cprintf("%2d",a[i]);
		/////////////////////////////////
		gotoxy(xj,yj++);cprintf("  ");
		gotoxy(xj,yj);cprintf("%2d",a[j]);
		delay(DELAY);
	}
	while(xi<xdest)
	{
		gotoxy(xi++,yi);cprintf("  ");
		gotoxy(xi,yi);cprintf("%2d",a[i]);
		////////////////////////////////
		gotoxy(xj--,yj);cprintf("  ");
		gotoxy(xj,yj);cprintf("%2d",a[j]);
		delay(DELAY);
	}
	for(k=0;k<2;k++)
	{
		gotoxy(xi,yi++);cprintf("  ");
		gotoxy(xi,yi);cprintf("%2d",a[i]);
		/////////////////////////////////
		gotoxy(xj,yj--);cprintf("  ");
		gotoxy(xj,yj);cprintf("%2d",a[j]);
		delay(DELAY);
	}
	xdest=a[i];
	a[i]=a[j];
	a[j]=xdest;
}
void in_bien_i(int i,int d,char c)
{
	gotoxy(cot+(i-1)*5+1,d-3);textcolor(BLACK);cprintf(" ");
	gotoxy(cot+(i)*5+1,d-3);textcolor(WHITE+BLINK);cprintf("%c",c);////  mui ten chi xuong.
}
void xoa_bien_i(int i,int d)
{
	gotoxy(cot+(i)*5+1,d-3);textcolor(BLACK);cprintf(" ");
}
void in_bien_j(int j,int d,char c)
{
	gotoxy(cot+(j-1)*5+1,d+5);textcolor(BLACK);cprintf(" ");
	gotoxy(cot+(j)*5+1,d+5);textcolor(WHITE+BLINK);cprintf("%c",c);////  mui ten chi len.
}
void xoa_bien_j(int j,int d)
{
	gotoxy(cot+(j)*5+1,d+5);textcolor(BLACK);cprintf(" ");
}
void giaodien(char *s,int dong)/////dong chi chieu cao
{
	char khung='|';
	int i,j;
	/////xoa man hinh////
	textmode(C80);
	textattr(14);
	clrscr();
	/////////////
	///in dong tieu de//
	gotoxy((80-strlen(s))/2,2);cprintf("%s",s);
	/////khoi tao mang can sap ngau nhien//
	randomize();
	for(i=0;i<MAX;i++)
	{
		a[i]=random(100);
	}
	/////in ra man hinh////
	textcolor(WHITE);
	for(i=0;i<3;i++)
	{
		gotoxy(cot,dong+i);cprintf("%c",khung);
	}
	for(j=0;j<MAX;j++)
	{
		textcolor(WHITE);
		textcolor(YELLOW);
		gotoxy(cot+j*5+2,dong+1);cprintf("%2d",a[j]);
		textcolor(WHITE);
		for(i=0;i<3;i++)
		{
			gotoxy(cot+(j+1)*5,dong+i);cprintf("%c",khung);
		}
	}
	for(i=0;i<3;i++)
	{
		gotoxy(cot+MAX*5,dong+i);cprintf("%c",khung);
	}
	////in cau thong bao thuc hien
	textcolor(11);
	gotoxy(1,dong-4);cprintf("Bien i");
	gotoxy(1,dong+6);cprintf("Bien j");
}
////////////////ham dung rieng cho insertion sort//
void rangoaidoi(int i,int d,int *x)
{
    int xi=cot+2+i*5;                                         /////chuyen a[i] ra ngoai de cho
	int yi=d+1;                                               ///cho tim cho chen vao mang a
	int k;                                                   /// luu a[i] vao x.
	for(k=0;k<2;k++)
	{
		gotoxy(xi,yi++);textcolor(GREEN);cprintf("  ");
		gotoxy(xi,yi);cprintf("%2d",a[i]);
		delay(DELAY);
	}
	for(k=0;k<3;k++)
	{
		gotoxy(xi++,yi);textcolor(GREEN);cprintf("  ");
		gotoxy(xi,yi);cprintf("%2d",a[i]);
		delay(DELAY);
	}
	*x=a[i];
	a[i]=-1;
}
void chenvao(int i,int j,int d,int x)
{
	int xj=cot+2+5*j;
	int yi=d+3;
	int xi=cot+2+i*5+3;
	int k;
	gotoxy(xi,yi);cprintf("  ");
	while(xi>xj)
	{
		gotoxy(xi--,yi);textcolor(YELLOW);cprintf("  ");
		gotoxy(xi,yi);cprintf("%2d",x);
		delay(100);
	}
	for(k=0;k<2;k++)
	{
		gotoxy(xi,yi--);cprintf("  ");
		gotoxy(xi,yi);cprintf("%2d",x);
		delay(100);
	}
	a[j]=x;
}
void doi(int i,int j)     ///////// 2 vi tri cung do cao
{
	int xi=cot+2+i*5;
	int yi=DONG+1;
	int xj=cot+2+j*5;
	int yj=DONG+1;
	int xdest=xj;
	int k;
	textcolor(YELLOW);
	for(k=0;k<2;k++)
	{
		gotoxy(xi,yi--);cprintf("  ");
		gotoxy(xi,yi);cprintf("%2d",a[i]);
		/////////////////////////////////
		gotoxy(xj,yj++);cprintf("  ");
		gotoxy(xj,yj);cprintf("  ");
		delay(DELAY-40);
	}
	while(xi<xdest)
	{
		gotoxy(xi++,yi);cprintf("  ");
		gotoxy(xi,yi);cprintf("%2d",a[i]);
		////////////////////////////////
		gotoxy(xj--,yj);cprintf("  ");
		gotoxy(xj,yj);cprintf("  ");
		delay(DELAY-40);
	}
	for(k=0;k<2;k++)
	{
		gotoxy(xi,yi++);cprintf("  ");
		gotoxy(xi,yi);cprintf("%2d",a[i]);
		/////////////////////////////////
		gotoxy(xj,yj--);cprintf("  ");
		gotoxy(xj,yj);cprintf("  ");
		delay(DELAY-40);
	}
	xdest=a[i];
	a[i]=a[j];
	a[j]=xdest;
}
///////////////////////////////////////SELECTION SORT//////////////////////////////////////////////
void selectionsort()
{
	char cl;
	char tieude[]="MINH HOA PHUONG PHAP SELECTION SORT";
	int i,j,min,max;
	giaodien(tieude,DONG);
	textcolor(11);
	gotoxy(1,DONG-4);cprintf("      ");
	gotoxy(1,DONG+6);cprintf("bien i");
	//////////////////thao tac di chuyen chuot////////////////////////////////////////////////
	menutanggiam(&cl);
	if(cl!=27){
	switch(cl)
	     {  case'T':gotoxy(1,25);clreol();printf("Dang sap tang");
		    for(i=0;i<MAX-1;i++)
		     {   in_bien_j(i,DONG,24);
			 min=i;
			 for(j=i+1;j<MAX;j++)
			     if(a[j]<a[min])
			       min=j;
			      doicho(i,min);
		      }
		 break;
		 case'G':gotoxy(1,25);clreol();printf("Dang sap giam");
		     for(i=0;i<MAX-1;i++)
		      {  in_bien_j(i,DONG,24);
			max=i;
			for(j=i+1;j<MAX;j++)
			    if(a[j]>a[max])
				max=j;
				doicho(i,max);
		      }
		  break;
	     }
	     xoa_bien_j(MAX-1,DONG);
	     gotoxy(30,18);clreol();textcolor(RED);cprintf("FINISHED !");
	     gotoxy(1,25);clreol();gotoxy(25,25);textcolor(WHITE);cprintf("PRESS ESC TO EXIT, ANYKEY TO CONTINUE");
	}    gotoxy(25,25);textcolor(WHITE);cprintf("PRESS ESC TO EXIT, ANYKEY TO CONTINUE");
}
////////////////////////////////////INSERTION SORT//////////////////////////////////////////
void insertionsort()
{
	char cl;
	char tieude[]="MINH HOA PHUONG PHAP INSERTION SORT";
	int i,j,pos,x;
	giaodien(tieude,DONG);
	textcolor(11);
	gotoxy(1,DONG-4);cprintf("      ");
	gotoxy(1,DONG+6);cprintf("Bien i");
	///////////////////thao tac di chuyen chuot/////////////////////////////////////////////////
	menutanggiam(&cl);
	///////////////////////////////////////////////////////////////////////////////////////////////////////
	if(cl!=27){
	switch(cl)
	{
		case'T':gotoxy(1,25);clreol();printf("Dang sap tang");
		       for(i=1;i<MAX;i++)
		       {
			      in_bien_j(i,DONG,24);
		  pos=i-1;
			  rangoaidoi(i,DONG,&x);delay(200);
			  while(pos>=0&&a[pos]>x)
			  {
				  doi(pos,pos+1);
				  pos--;
			  }
			  chenvao(i,pos+1,DONG,x);

		       }
	       break;
		case'G':gotoxy(1,25);clreol();printf("Dang sap giam");
		       for(i=1;i<MAX;i++)
		       {
			      in_bien_j(i,DONG,24);
		  pos=i-1;
			  rangoaidoi(i,DONG,&x);delay(200);
			  while(pos>=0&&a[pos]<x)
			  {
				  doi(pos,pos+1);
				  pos--;
			  }
			  chenvao(i,pos+1,DONG,x);

		       }
		       break;
	}
	xoa_bien_j(MAX-1,DONG);/////xoa bien j cuoi cung
	gotoxy(30,18);clreol();textcolor(RED);cprintf("FINISHED !");
	gotoxy(1,25);clreol();gotoxy(25,25);textcolor(WHITE);cprintf("PRESS ESC TO EXIT,ANYKEY TO CONTINUE");
	}gotoxy(25,25);textcolor(WHITE);cprintf("PRESS ESC TO EXIT,ANYKEY TO CONTINUE");
}
///////////////////////////////////INTERCHANGE SORT///////////////////////////////////////
void interchangesort()
  {
	char cl;
	char tieude[]="MINH HOA PHUONG PHAP INTERCHANGE SORT";
	int i,j;
	giaodien(tieude,DONG);
	textcolor(11);
	gotoxy(1,DONG-4);cprintf("      ");
	gotoxy(1,DONG+6);cprintf("Bien i");
	///////////////////////////////////////////////////////////////////////
	menutanggiam(&cl);
	///////////////////////////////////////////////////////////////////////
	if(cl!=27){
	switch(cl)
	{
		 case'T':gotoxy(1,25);clreol();printf("Dang sap tang");
			{
			 for(i=0;i<MAX-1;i++)
			      for(j=i+1;j<MAX;j++)
				  if(a[j]<a[i])
				     doicho(j,i);
			 }
		 break;
		 case'G':gotoxy(1,25);clreol();printf("Dang sap giam");
			 {
			  for(i=0;i<MAX-1;i++)
			       for(j=i+1;j<MAX;j++)
				   if(a[j]>a[i])
				      doicho(j,i);
			 }
		 break;
	}
	xoa_bien_j(MAX-1,DONG);//xoa bien j cuoi cung
	gotoxy(30,18);clreol();textcolor(RED);cprintf("FINISHED !");
	gotoxy(1,25);clreol();gotoxy(25,25);textcolor(WHITE);cprintf("PRESS ESC TO EXIT, ANYKEY TO CONTINUE");
       }gotoxy(25,25);textcolor(WHITE);cprintf("PRESS ESC TO EXIT, ANYKEY TO CONTINUE");
  }
///////////////////////////////////BUBLE SORT////////////////////////////////////////////////////////////////////////////////
void bublesort()
{
	    char cl;
	    char tieude[]="MINH HOA PHUONG PHAP BUBLE SORT";
	    int i,j;
	    giaodien(tieude,DONG);
	    textcolor(11);
	    gotoxy(1,DONG-4);printf("      ");
	    gotoxy(1,DONG+6);printf("Bien i");
	    /////////////////////////////////////////////////////////////////////////////////////////
	    menutanggiam(&cl);
	    ///////////////////////////////////////////////////////////////////////////////////////////////
	    if(cl!=27){
	    switch(cl)
	    {
		   case'T':gotoxy(1,25);clreol();printf("Dang sap tang");
			  {
			   for(i=0;i<MAX-1;i++)
				for(j=MAX-1;j>i;j--)
				    if(a[j]<a[j-1])
				       doicho(j-1,j);
			  }
		   break;
		   case'G':gotoxy(1,25);clreol();printf("Dang sap giam");
			  {
			   for(i=0;i<MAX;i++)
				for(j=MAX-1;j>i;j--)
				    if(a[j]>a[i])
				       doicho(j-1,j);
			  }
		   break;
	    }
	gotoxy(30,18);clreol();textcolor(RED);cprintf("FINISHED !");
	gotoxy(1,25);clreol();gotoxy(25,25);textcolor(WHITE);cprintf("PRESS ESC TO EXIT, ANYKEY TO CONTINUE");
       }gotoxy(25,25);textcolor(WHITE);cprintf("PRESS ESC TO EXIT, ANYKEY TO CONTINUE");
}
///////////////////////////////////HEAP SORT////////////////////////////////////////////////////////////////////////
/*void Shift(int a[], int r)
{
  int x,i,j;
  i=1;j=2*i;//(phan tu lien doi)
  x=a[i];
  while (j<=r)
  {  if(j<r)
	if(a[j]<a[j+1])
	   j=j+1;
	   if(a[j]<x) exit();
	   else
	   { a[i]=a[j];
	     i=j;
	     j=2*i;
	     a[i]=x;
	   }
    }
}
void CreateHeap(int a[],int N)
{  int l;
   l=N/2;
   while (l>0) do
   {
       Shift(a,l,N);
       l=l-1;
   }
}
void heapsort()
{
	 char cl;
	 char tieude[]="MINH HOA PHUONG PHAP HEAP SORT";
	 int r;
	 giaodien(tieude,DONG);
	 textcolor(11);
	 gotoxy(1,DONG-4);printf("      ");
	 gotoxy(1,DONG+6);printf("Bien i");
	 //////////////////////////////////////////////////////////////////////////////////////////////////////////
	 menutanggiam(&cl);
	 /////////////////////////////////////////////////////////////////////////////////////////////////////////
	 if(cl!=27){
	 switch(cl)
	 {
		   case'T':gotoxy(1,25);clreol();printf("Dang sap tang");
			  CreateHeap(a,N)
			  r=N-1;
			  while(r>0) do
			  {   doicho(a[l],a[r]);
			      r=r-l;
			      Shift(a,l,r);
			  }
		   break;
		  // case'G':gotoxy(1,25);clreol();printf("Dang sap giam");

		 //  break;
	 }
      gotoxy(30,18);clreol();textcolor(RED);cprintf("FINISHED !");
      gotoxy(1,25);clreol();gotoxy(25,25);textcolor(WHITE);cprintf("PRESS ESC TO EXIT, ANYKEY TO CONTINUE");
     }gotoxy(25,25);textcolor(WHILE);cprintf("PRESS ESC TO EXIT, ANYKEY TO CONTINUE");
} */

///////////////////////////////////QUICK SORT//////////////////////////////////////////////////////////////////////
void quicktang(int l,int r)
{
	int i,j;
	int x;
	x=a[(l+r)/2];
	i=l;j=r;
	gotoxy(30,18);textcolor(WHITE+BLINK);cprintf("Quick sort doan:l=%2d,r=%2d,X=%2d",l+1,r+1,x);
	for(int k=0;k<=2;k++)
	{
	gotoxy(cot+l*5,DONG+k);textcolor(RED+BLINK);cprintf("|");
	gotoxy(cot+(r+1)*5,DONG+k);textcolor(RED+BLINK);cprintf("|");
	}
	do
	{
		while(a[i]<x)
		{
			in_bien_j(i,DONG,24);in_bien_j(j,DONG,24);
			delay(DELAY);
			i++;
			xoa_bien_j(i-1,DONG);delay(DELAY);
		}
		while(a[j]>x)
		{
			in_bien_j(j,DONG,24);in_bien_j(i,DONG,24);
			delay(DELAY);
			j--;
			xoa_bien_j(j+1,DONG);delay(DELAY);
		}
		if(i<=j)
		{
			in_bien_j(i,DONG,24);in_bien_j(j,DONG,24);
			doicho(i,j);
			i++;
			j--;
			xoa_bien_j(i-1,DONG);xoa_bien_j(j+1,DONG);
		}
	}while(i<j);
	for( k=0;k<=2;k++)
	{
	gotoxy(cot+l*5,DONG+k);textcolor(WHITE);cprintf("|");
	gotoxy(cot+(r+1)*5,DONG+k);textcolor(WHITE);cprintf("|");
	}
	if(l<j) quicktang(l,j);
	if(r>i) quicktang(i,r);
}
void quickgiam(int l,int r)
{
	int i,j;
	int x;
	x=a[(l+r)/2];
	i=l;j=r;
	gotoxy(30,18);textcolor(WHITE+BLINK);cprintf("Quick sort doan:l=%2d,r=%2d,X=%2d",l+1,r+1,x);
	for(int k=0;k<=2;k++)
	{
	gotoxy(cot+l*5,DONG+k);textcolor(RED+BLINK);cprintf("|");
	gotoxy(cot+(r+1)*5,DONG+k);textcolor(RED+BLINK);cprintf("|");
	}
	do
	{
		while(a[i]>x)
		{
			in_bien_j(i,DONG,24);in_bien_j(j,DONG,24);
			delay(DELAY);
			i++;
			xoa_bien_j(i-1,DONG);delay(DELAY);
		}
		while(a[j]<x)
		{
			in_bien_j(j,DONG,24);in_bien_j(i,DONG,24);
			delay(DELAY);
			j--;
			xoa_bien_j(j+1,DONG);delay(DELAY);
		}
		if(i<=j)
		{
			in_bien_j(i,DONG,24);in_bien_j(j,DONG,24);
			doicho(i,j);
			i++;j--;
			xoa_bien_j(i-1,DONG);xoa_bien_j(j+1,DONG);
		}
	}while(i<j);
	for( k=0;k<=2;k++)
	{
	gotoxy(cot+l*5,DONG+k);textcolor(WHITE);cprintf("|");
	gotoxy(cot+(r+1)*5,DONG+k);textcolor(WHITE);cprintf("|");
	}
	if(l<j) quickgiam(l,j);
	if(r>i) quickgiam(i,r);
}
///////////////////////////////////////////////////////////////////////////////
void quicksort()
{
	char c,cl;
	char tieude[]="MINH HOA PHUONG PHAP QUICK SORT";
	int i,j;
	giaodien(tieude,DONG);
	textcolor(11);
	gotoxy(1,DONG-4);cprintf("      ");
	gotoxy(1,DONG+6);cprintf("Bien i:-->");gotoxy(70,DONG+6);cprintf("<--j bien");
	///////////////////thao tac di chuyen chuot/////////////////////////////////////////////////
	menutanggiam(&cl);
	///////////////////////////////////////////////////////////////////////////////////////////////////////
	if(cl!=27){
	switch(cl)
	{
		case'T':gotoxy(1,25);clreol();printf("Dang sap tang");
		   quicktang(0,MAX-1);
	       break;
		case'G':gotoxy(1,25);clreol();printf("Dang sap giam");
	       quickgiam(0,MAX-1);
		       break;
	}
	gotoxy(30,18);clreol();textcolor(RED);cprintf("FINISHED !");
	gotoxy(1,25);clreol();gotoxy(25,25);textcolor(WHITE);cprintf("PRESS ESC TO EXIT,ANYKEY TO CONTINUE");
	}gotoxy(25,25);textcolor(WHITE);cprintf("PRESS ESC TO EXIT,ANYKEY TO CONTINUE");
}
void menu()
{
	clrscr();
	char n[]="CHUONG TRINH MINH HOA CAC GIAI THUAT SORT BANG TURBO C",z[]="*** cua Tauit_dnmd ***";
	textcolor(11);
	gotoxy((80-strlen(n))/2,2);cprintf("%s",n);
	gotoxy((80-strlen(z))/2,3);cprintf("%s",z);
	textcolor(YELLOW);
	gotoxy(10,10);
	cprintf("______________________________________________");gotoxy(10,11);
	cprintf("_____________________MENU_____________________");gotoxy(10,12);
	cprintf("*              1.SELECTION SORT              * ");gotoxy(10,13);
	cprintf("*              2.INTERCHANGE SORT            * ");gotoxy(10,14);
	cprintf("*              3.INSERTION SORT              * ");gotoxy(10,15);
	cprintf("*              4.BUBLE SORT                  * ");gotoxy(10,16);
	cprintf("*              5.QUICK SORT                  * ");gotoxy(10,17);
	cprintf("*              6.MERGE SORT                  * ");gotoxy(10,18);
	cprintf("*              7.HEAP SORT                   * ");gotoxy(10,19);
	cprintf("*____________________________________________* ");
   }
void chonlua()
{
	int i,j;
	char c;
	i=27;
	j=12;
	do
	{
		gotoxy(i,j);
		switch(j)
		{
			case 12:textcolor(11+BLINK);cprintf("SELECTION SORT");break;
				case 13:textcolor(11+BLINK);cprintf("INTERCHANGE SORT");break;
				case 14:textcolor(11+BLINK);cprintf("INSERTION SORT");break;
				case 15:textcolor(11+BLINK);cprintf("BUBLE SORT");break;
				case 16:textcolor(11+BLINK);cprintf("QUICK SORT");break;
				case 17:textcolor(11+BLINK);cprintf("MERGE SORT");break;
				case 18:textcolor(11+BLINK);cprintf("HEAP SORT");break;

		}
		c=getch();
		if(c==0||c==13)
		{
			if(c==0) c=getch();
			if(c==72)
			   if(j>12)
		       {
				gotoxy(i,j);
			   switch(j)
			   {
				case 12:textcolor(YELLOW);cprintf("SELECTION SORT");break;
					case 13:textcolor(YELLOW);cprintf("INTERCHANGE SORT");break;
					case 14:textcolor(YELLOW);cprintf("INSERTION SORT");break;
					case 15:textcolor(YELLOW);cprintf("BUBLE SORT");break;
					case 16:textcolor(YELLOW);cprintf("QUICK SORT");break;
					case 17:textcolor(YELLOW);cprintf("MERGE SORT");break;
					case 18:textcolor(YELLOW);cprintf("HEAP SORT");break;

			}
				  j--;
			    }
			if(c==80)
			   if(j<=17)
			   {
		      gotoxy(i,j);
			   switch(j)
			   {
				case 12:textcolor(YELLOW);cprintf("SELECTION SORT");break;
					case 13:textcolor(YELLOW);cprintf("INTERCHANGE SORT");break;
					case 14:textcolor(YELLOW);cprintf("INSERTION SORT");break;
					case 15:textcolor(YELLOW);cprintf("BUBLE SORT");break;
					case 16:textcolor(YELLOW);cprintf("QUICK SORT");break;
					case 17:textcolor(YELLOW);cprintf("MERGE SORT");break;
					case 18:textcolor(YELLOW);cprintf("HEAP SORT");break;

			}
			      j++;
			   }
	    if(c==13)
			{
			  switch(j)
			  {
				case 12:selectionsort();break;
				case 13:interchangesort();break;
				case 14:insertionsort();break;
				case 15:bublesort();break;
				case 16:quicksort();break;
				case 17:
				case 18:
				case 19:getch();break;
			   }
			}
		}
		if(c==27) break;
	}while(c!=13);
}
void main()
{
	char tt;
	do{
		 textmode(C80);
		 textattr(14);
		 clrscr();
		 menu();
		 chonlua();
	     tt=getch();
	}while(tt!=27);
}

