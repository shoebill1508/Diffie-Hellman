#include <iostream>
#include <cmath>

using namespace std;

long long int tinhLuyThua(long long int coSo, long long int soMu, long long int modulo) {
   if (soMu == 1)
      return coSo;
   else
      return (((long long int)pow(coSo, soMu)) % modulo);
}

int main() {
   long long int soNguyenTo, sinh, biMatAlice, biMatBob, congKhaiAlice, congKhaiBob, khoaBiMatAlice, khoaBiMatBob;

   soNguyenTo = 23;
   cout << "So nguyen to (P): " << soNguyenTo << endl;
   
   sinh = 5; 
   cout << "Gia tri sinh (G): " << sinh << endl;

   biMatAlice = 6;
   cout << "Khoa bi mat cua Alice (a): " << biMatAlice << endl;

   congKhaiAlice = tinhLuyThua(sinh, biMatAlice, soNguyenTo); 

   biMatBob = 15; 
   cout << "Khoa bi mat cua Bob (b): " << biMatBob << endl;

   congKhaiBob = tinhLuyThua(sinh, biMatBob, soNguyenTo); 

   khoaBiMatAlice = tinhLuyThua(congKhaiBob, biMatAlice, soNguyenTo); 
   khoaBiMatBob = tinhLuyThua(congKhaiAlice, biMatBob, soNguyenTo); 

   cout << "Khoa bi mat cua Alice: " << khoaBiMatAlice << endl;
   cout << "Khoa bi mat cua Bob: " << khoaBiMatBob << endl;

   return 0;
}

