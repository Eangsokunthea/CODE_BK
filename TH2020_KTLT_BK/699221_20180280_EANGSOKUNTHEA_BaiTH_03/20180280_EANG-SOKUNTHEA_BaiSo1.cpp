/*HoTen: EANG SOKUNTHEA
  MSSV: 20180280*/
#include <iostream>
using namespace std;

int lucas(int n) {
    if (n == 0) return 2;
    if (n == 1) return 1;
    return lucas(n-1) + lucas(n-2);
}

int main(){
	printf("HoVaTen: EANG SOKUNTHEA\n");
	printf("MSSV: 20180280\n");
    int n;
    cin >> n;
    cout << lucas(n) << endl;
    return 0;
}
