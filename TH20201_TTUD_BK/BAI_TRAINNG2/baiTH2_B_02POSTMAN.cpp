/*input
7 1
9400000 10000000
9500000 10000000
9600000 10000000
9700000 10000000
9800000 10000000
9900000 10000000
10000000 10000000
output
1358000000000000

input
4 10
-7 5
-2 3
5 7
9 5
output
42
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n, max;
	cin >> n >> max;
	int u[n], v[n];
	// nhap vao du lieu cua khach hang
	for (int i=0; i<n ; i++){
		cin >> u[i] >> v[i];
	}
	
	//	sort list 
	for (int i=0; i<n-1 ;i++) {
		for(int j=i+1 ; j<n ; j++) {
			if ( u[i] > u[j]) {
				int tmpu = u[i];
				int tmpv = v[i];
				u[i] = u[j];
				v[i] = v[j];
				u[j]=tmpu;
				v[j] = tmpv;
			}
		}
	}
	
	// thuat toan 
	int diChuyen = 0;.
	for (int i = n-1; i >= 0 ; i--) {
		int traHang = v[i];

		if (v[i] > max) {
			diChuyen = u[i] * 2 * (v[i]/max);
			v[i] = v[i]%max; 
		}
		
		if (v[i] < max && u[i] > 0) {
			diChuyen += abs(u[i]) * 2;
			v[i-1] -= max - v[i];
		} else if (v[i] < max && u[i] < 0) {
			diChuyen += abs(u[i-1]) * 2;
			v[i-1] -= max - v[i];
		}
		
	}
	
	cout << endl << diChuyen;
} 
