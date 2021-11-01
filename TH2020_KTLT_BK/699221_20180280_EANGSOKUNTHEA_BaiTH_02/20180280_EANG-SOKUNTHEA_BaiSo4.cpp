/*HOVATEN: EANG SOKUNTHEA
  MSSV: 20180280*/
#include <stdio.h>

int cube(int x) {
    return x * x * x;
}

double cube(double x) {
    return x * x * x;
}

int main() {
    int n;
    double y;
    scanf("%d %lf", &n, &y);
    printf("Int: %d\n", cube(n));
    printf("Double: %.2lf\n", cube(y));
    
    return 0;
}
