#include<stdio.h>
#include<string.h>
int main()
{
    char ten[1024];
    char response[1024] = "OK Em.mp3";
    strcpy(ten,response+3);
    printf("%s",ten);
    return 0;
}
