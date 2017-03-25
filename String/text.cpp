#include<stdio.h>
#include<string.h>
#include<ctype.h>
char* tachtu(char s[100])
{
   for (int i=0;i<strlen(s);i++)
   {if (isalnum(s[i])==0&& s[i]!='\'')
    	s[i]=' ';
   }
   return s;
}
int main()
{
    char he[100];
    scanf("%s",&he);
	printf("Hello: %s",tachtu(he));

	return 0;
}
