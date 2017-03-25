#include<time.h>
#include<stdio.h>
void delay(int miliseconds)
{
     if(miliseconds <= 0)
     {
         return;
     }
     clock_t start, finish;
     start = clock();
     finish = start;
     while(finish - start < miliseconds)
     {
         finish = clock();
     }
}

int main()
{
    printf("Huy");
    delay(3000);
    printf("Hung");
    return 0;
}
