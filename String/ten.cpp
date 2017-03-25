#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int h;
    srand(unsigned(time(NULL)));
    while(1){
        system("cls");
        h = rand()%(122-97+1)+97;
        printf("\n%c",(char)h);
        h = rand()%(122-97+1)+97;
        printf("%c",(char)h);
        h = rand()%(122-97+1)+97;
        printf("%c\n",(char)h);
        system("pause");
    }
    return 0;
}
