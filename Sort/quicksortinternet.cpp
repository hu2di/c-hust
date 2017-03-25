#include<stdio.h>
#include<stdlib.h>
#include<time.h>      // thu vien de khoi tao tham so cho ham rand()
#define swap(type, a, b) {type temp = a; a = b; b = temp; } // hang hoan vi

void quickSort(int *a, int l, int r)
{
    srand(time(NULL));  //khoi tao tham so ham rand()
    int key = a[l + rand() % (r-l+1)];  //lay khoa la gia tri ngau nhien tu a[l] -> a[r]
    //int key = a[(l+r)/2];
    int i = l, j = r;
    printf("\n\nl = %d   r = %d    select: key = %d  (random) ",l, r, key);

    while(i <= j)
    {
        //printf("\n");
        printf("\n\n\ti : %d", i);
        while (a[i] < key) { i++; printf(" -> %d",i); }
        printf("\n\tj : %d", j);
        while (a[j] > key) { j--; printf(" -> %d",j); }
        if(i <= j)
        {
            if (i < j)
            {
                swap(int, a[i], a[j]);  // doi cho 2 phan tu kieu int a[i], a[j].
                printf("\n\tswap(a[%d], a[%d])  swap(%d, %d)", i, j, a[i], a[j]);
            }
            i++;
            j--;
            printf("\n\tarr[] : ");
            for (int i=0; i<8; i++)
                printf ("%d ", a[i]);
        }
    }
    //bay gio ta co 1 mang : a[l]....a[j]..a[i]...a[r]
    if (l < j) quickSort(a, l, j);   // lam lai voi mang a[l]....a[j]
    if (i < r) quickSort(a, i, r); // lam lai voi mang a[i]....a[r]
}

int main ()
{
    int i, arr[] = { 2, 8, 7, 1, 3, 5, 6, 4  };
    int n = 8;
    printf("\n\nArray befor sort: ");
    for (i=0; i<n; i++)
        printf ("%d ", arr[i]);

    quickSort(arr, 0, n-1);

    printf("\n\nArray after sort: ");
    for (i=0; i<n; i++)
        printf ("%d ", arr[i]);
}
