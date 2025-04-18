#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int nguyenTo(int so) {
    int i;
    for (i = 2; i * i <= so; ++i)
        if (so % i == 0)
            return 0;
    return 1;
}

int luyThuaMod(int coSo, int soMu, int modulo) {
    int ketQua = 1;
    int i;
    for (i = 1; i <= soMu; ++i)
        ketQua = (ketQua * coSo) % modulo;
    return ketQua;
}

int main() {
    int p, g, a, b, r1, r2, khoaAlice, khoaBob, kiemTra;
    srand(time(NULL));
    
    nhap:
        printf("\nNhap p va g: ");
        scanf("%d %d", &p, &g);

    if (!nguyenTo(p) || !nguyenTo(g)) {
        printf("\nGia tri vua nhap khong phai la so nguyen to. Vui long nhap lai!");
        goto nhap;
    } else {
        srand(time(NULL));
        a = rand() % 50;
        b = rand() % 50;
        printf("\nSo bi mat ngau nhien cua Alice va Bob: %d %d", a, b);

        r1 = luyThuaMod(g, a, p); 
        r2 = luyThuaMod(g, b, p); 

        printf("\nGia tri R1 (Alice gui Bob): %d", r1);
        printf("\nGia tri R2 (Bob gui Alice): %d", r2);

        khoaAlice = luyThuaMod(r2, a, p); 
        khoaBob = luyThuaMod(r1, b, p); 

        printf("\nKhoa bi mat chung tinh boi Alice: %d", khoaAlice);
        printf("\nKhoa bi mat chung tinh boi Bob: %d", khoaBob);

        kiemTra = luyThuaMod(g, a * b, p);
        printf("\nKiem tra khoa bi mat chung bang g^(a*b) mod p: %d", kiemTra);
    }

    getch(); 
    return 0;
}
