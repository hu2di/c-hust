#include<stdio.h>

void nhapMang(int a[], int n) {
    int i;
    printf("\nNHAP MANG:\n");
    for (i = 0; i < n; i++) {
        printf("a[%d] =",i);
        scanf("%d",&a[i]);
    }
}

void xuatMang(int a[], int n) {
    int i;
    printf("\nXUAT MANG: ");
    for (i = 0; i < n; i++) {
        printf("%d     ", a[i]);
    }
}

int nguyenTo(int so) {
    if (so==1) return 0;
    int i;
    for (i=2; i<so; i++) {
        if ((so%i)==0) return 0;
    }
    return 1;
}

int viTriNguyenToCuoiCung(int a[], int n) {
    int i;
    for ( i = n-1; i >=0; i--) {
        if (nguyenTo(a[i]) == 1) return i;
    }
    return -1;
}

void chenX(int a[], int *n) {
    int x;
    printf("\nNHAP SO x: ");
    scanf("%d", &x);
    int vitri = viTriNguyenToCuoiCung(a, *n);
    printf("\nVI TRI NTO CUOI CUNG: %d\n", vitri);
    if (vitri == -1) {
        printf("\nKHONG CO SO NGUYEN TO TRONG MANG!");
    } else {
        printf("\nMANG TRUOC KHI CHEN:\n", x);
        xuatMang(a, *n);
        int i;
        for(i = *n; i > vitri; i--) {
            a[i] = a[i-1];
        }
        a[vitri] = x;
        printf("\nMANG SAU KHI CHEN:\n", x);
        *n = *n + 1;
        xuatMang(a, *n);
    }
}

void sapXep(int a[], int n) {
    int i, j, temp;
    for (i = 0; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("\nSAPXEP:\n");
    for (i = 0; i < n; i++) {
        printf("%d    ", a[i]);
    }

}

int main() {
    int n;
    printf("\nNHAP SO PHAN TU: ");
    scanf("%d", &n);
    int a[100];
    nhapMang(a, n);
    xuatMang(a, n);
    chenX(a, &n);
    sapXep(a, n);
}
