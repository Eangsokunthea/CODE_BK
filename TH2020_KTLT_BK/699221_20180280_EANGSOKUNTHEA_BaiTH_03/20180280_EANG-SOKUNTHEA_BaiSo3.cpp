/*HoTen: EANG SOKUNTHEA
  MSSV: 20180280*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 100  

int n, c[MAX][MAX]; //# s? th�nh ph? v� ma tr?n chi ph�
int cmin = INT_MAX; //# chi ph� di l?i nh? nh?t gi?a hai th�nh ph? kh�c nhau
int best = INT_MAX; //# t?ng chi ph� nh? nh?t c?n t�m, ban d?u d?t b?ng gi� tr? v� c�ng l?n INT_MAX = 2^31-1
int curr; //# t?ng chi ph� t?i th?i di?m hi?n t?i
int mark[MAX]; //# d�nh d?u nh?ng th�nh ph? d� di
int x[MAX]; //# luu gi? c�c th�nh ph? d� di

//# �?c d? li?u v�o
void input(){
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            cin >> c[i][j];
            if (c[i][j] > 0) cmin = min(cmin, c[i][j]);
        }
}

//# Thu?t to�n quay lui
void TRY(int k){
    for(int i = 2; i <= n; i++){
        if(mark[i] == 0)
        {
        	x[k] = i;
        	mark[i] = 1;
        	TRY(k+1);
        	mark[i] = 0;
		}
			
	}
	int curr = 0;
	if(k>n){
		for(int i=1; i<=n-1; i++){
			curr = curr + c[x[i]][x[i+1]];
		}
		curr = curr + c[x[n]][x[1]];
		best = min(best, curr);
	}
}

int main() {
	printf("HoVaTen: EANG SOKUNTHEA\n");
	printf("MSSV: 20180280\n");
    input();
    x[1] = 1;
    TRY(2);
    cout << best;
    return 0;
}
/*Backtracking(k) {
	for([M?i phuong �n ch?n i(thu?c t?p D)]) {
		if ([Ch?p nh?n i]) {
			[Ch?n i cho X[k]];
			if ([Th�nh c�ng]) {
				[�ua ra k?t qu?];
			} else {
				Backtracking(k+1);
				[B? ch?n i cho X[k]];
			}
		}
	}
}*/
