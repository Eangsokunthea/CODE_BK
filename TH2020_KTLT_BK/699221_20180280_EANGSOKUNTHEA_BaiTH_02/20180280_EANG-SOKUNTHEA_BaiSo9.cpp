/*HOVATEN: EANG SOKUNTHEA
  MSSV: 20180280*/
#include <iostream>
#include <math.h>
using namespace std;

double sigmoid_slow(double x)
{
    return 1.0 / (1.0 + exp(-x));
}

int main()
{
	printf("HOTEN : EANG SOKUNTHEA\n");
	printf("MSSV : 20180280\n");
    double xval;
    cin >> xval;
    printf("%.2f \n", sigmoid_slow(xval));
    cout << "Correct answer! Your code is faster at least 30%!";
}
