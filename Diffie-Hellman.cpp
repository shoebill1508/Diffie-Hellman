#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int prime(int num) {
    int i;
    for (i = 2; i*i <= num; ++i)
        if (num % i == 0)
            return 0;
    return 1;
}

int mod(int base, int expo, int num) {
    int res = 1;
    int i;
    for (i = 1; i <= expo; ++i)
        res = (res * base) % num;
    return res;
}

int main() {
    int p, g, a, b, i, j, r1, r2, k1, k2, k3;
    srand(time(NULL));
    p:
        printf("\nNhap p va g: ");
        scanf("%d %d", &p, &g);

    if (!prime(p) || !prime(g)) {
        printf("\nCac gia tri vua nhap khong phai la nguyen to. Vui long nhap lai !");
        goto p;
    } else {
        srand(time(NULL));
        a = rand() % 50;
        b = rand() % 50;
        printf("\nSo tao ngau nguyen: %d %d", a, b);
        r1 = mod(g, a, p); 
        r2 = mod(g, b, p); 
        printf("\nR1 = %d\nR2 = %d\n", r1, r2);
        k1 = mod(r2, a, p);
        k2 = mod(r1, b, p); 
        printf("\nKhoa bi mat chung duoc tinh boi Alice: %d", k1);
        printf("\nKhoa bi mat chung duoc tinh boi Bob: %d", k2);
        k3 = mod(g, a * b, p);
        printf("\nKiem tra khoa bi mat chung chung: %d", k3); 
    }
getch(); 
}
