#include<iostream>
#include<math.h>
using namespace std;
#define PI 3.14159265
class DFT_Coeff {
   public:
   double real, img;
   DFT_Coeff() {
      real = 0.0;
      img = 0.0;
   }
};
int main(int argc, char **argv) {
   int M= 10;
   cout << "Enter the coefficient of simple linear function:\n";
   cout << "ax + by = c\n";
   double a, b, c;
   cin >> a >> b >> c;
   double function[M];
   for (int i = 0; i < M; i++) {
      function[i] = (((a * (double) i) + (b * (double) i)) - c);
      //System.out.print( " "+function[i] + " ");
   }
   cout << "Enter the max K value: ";
   int k;
   cin >> k;
   double cosine[M];
   double sine[M];
   for (int i = 0; i < M; i++) {
      cosine[i] = cos((2 * i * k * PI) / M);
      sine[i] = sin((2 * i * k * PI) / M);
   }
   DFT_Coeff dft_value[k];
   cout << "The coefficients are: ";
   for (int j = 0; j < k; j++) {
      for (int i = 0; i < M; i++) {
         dft_value[j].real += function[i] * cosine[i];
         dft_value[j].img += function[i] * sine[i];
      }
      cout << "(" << dft_value[j].real << ") - " << "(" << dft_value[j].img <<" i)\n";
   }
}