#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    string a[10];
    for(int i=0;i<=4;i++) cin>>a[i];
    int n;
	cout<<"So ten:";
	cin>>n;
	char *strName;
	strName = (char*)malloc(sizeof(char)*100);
	char *kt;
	kt = (char*)malloc(sizeof(char)*100);
	for(int i=1;i<=n;i++)
	{
	    fflush(stdin);
	    gets(strName);
	    if (strlen(strName)>strlen(kt)) strcpy(kt,strName);
	}
	cout<<"Chuoi dai nhat: "<<kt;
	return 0;
}
