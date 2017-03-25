#include<stdio.h>
#include<string.h>
int main()
{
    char s[100];
    gets(s);
	int chu=0,so=0,khac=0,space=0,i=0;
	while (s[i]!=NULL)
	{
        if (('0'<=s[i]) and (s[i]<='9')) so=so+1;
	    else
        if (s[i]==32) space=space+1;
        else
        if ((('a'<=s[i]) and (s[i]<='z')) || (('A'<=s[i]) and (s[i]<='Z'))) chu=chu+1;
        else
        khac=khac+1;
	    i++;
	}
    printf("%d %d %d %d",chu,space,so,khac);
	return 0;
}
