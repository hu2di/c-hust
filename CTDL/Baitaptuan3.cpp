#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
using namespace std;
//--------------
int count=0;
int n,Stop;
char P[10];
//--------------
void Swap(char &a, char &b)
{
char tg = a;
a = b;
b = tg;
}
//---------------
void sapxep(char a[])
{
for(int i = 0 ; i < n-1; i++)
for(int j = i + 1; j < n; j++)
{
if(a[i]>a[j])
Swap(a[i],a[j]);
}
}
//------------
void Next_Hoanvi() //Tim hoan vi ke tiep
{
int j,k,l,r;
j = n - 2;
while (j>=0 && P[j]>= P[j+1]) j--;
if (j == -1)
Stop = 0;
else
{
k = n - 1;
while (P[j] >= P[k]) k--;
Swap(P[j], P[k]);
l = j + 1;
r = n - 1;
while (l < r)
{
Swap(P[l], P[r]);
l++;
r--;
}
}// end else
}
void Hoanvi()
{
Stop = 1;
while ( Stop)
{
count++;
cout<<endl<<P;
Next_Hoanvi();
}
}

int main()
{
cin.ignore(0);
cin.getline(P,10);
n = strlen(P);
sapxep(P);
Hoanvi();
cout<<endl<<count;
getch();
return 0;

}

