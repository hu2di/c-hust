#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct
{
	char word[30];
	int freq;
}vanban;
char* tachtu(char s[30])
{
   for (int i=0;i<strlen(s);i++)
   {if (isalnum(s[i])==0&& s[i]!='\'')
    	s[i]=' ';
   }
   return s;
}
 main()
 {
 	int sotu=0,flag=0,d=0;
 	vanban *tu;
 	char chu[30];
 	tu=(vanban*)malloc(1000*sizeof(vanban));
 	FILE *fread, *fwrite,*fm;
 	fread=fopen("input.txt","r");
 	if(fread==NULL)
     {
      printf("khong mo duoc tep nay ");
      getch();
      exit(-1);
     }

  	fm=fopen("medium.txt","w");
 	while (feof(fread)==0)
 	{
 		fscanf(fread,"%s",chu);
 		fprintf(fm,"%s ",tachtu(chu));

 	}
 	fclose(fread);
 	fclose(fm);
  fm=fopen("medium.txt","r");
  fwrite=fopen("output.txt","w");
  while(!feof(fm))
  {
   fscanf(fm,"%s",chu);
   for(int i=0;i<sotu; i++)
   {if(strcmp(chu,tu[i].word)==0)
    {
    	tu[i].freq++;
    	flag=1;
    	break;

    }
   }
   if(flag==1){flag=0;}
   else {
   	strcpy(tu[sotu].word,chu);
   	tu[sotu].freq++;
   	sotu++;
   	 }
   }

   for(int i=0;i<sotu;i++)
   {
   	    printf("\n%-20s%d",tu[i].word,tu[i].freq);
	   fprintf(fwrite,"\n%-20s%d",tu[i].word,tu[i].freq);
   }

}
