/*HoTen: EANG SOKUNTHEA
  MSSV: 20180280*/
#include <iostream>
using namespace std;

int n;
int X[100], Y[100]; //# Luu to? d? c�c bu?c di chuy?n c?a qu�n m�
int mark[100][100]; //# ��nh d?u v? tr� c�c � m� qu�n m� di qua
//# M?ng hx, hy m� t? 8 v? tr� qu�n m� c� th? di chuy?n k? t? v? tr� hi?n t?i
const int hx[] = {1, 1, 2, 2, -1, -1, -2, -2}; 
const int hy[] = {2,-2, 1,-1,  2, -2,  1, -1};
//# In ra d�y c�c di chuy?n t�m du?c
void print_sol(){
    for (int j = 1; j <= n * n; ++j)
        printf("(%d %d)\n", X[j], Y[j]);
    exit(0);
}
int isOk(int n){
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; i++)
			if(!mark[i][j]) return 0;			
	return 1;
}
//# Thu?t to�n quay lui
void TRY(int k){
    for(int i = 0; i < 8; i++){
        int xx = X[k-1] + hx[i];
        int yy = Y[k-1] + hy[i];
        
        if(!mark[xx][yy] && xx > 0 && yy > 0 && xx <= n && yy <= n){
        	mark[xx][yy] = 1;
        	X[k] = xx;
        	Y[k] = yy;
        	if(k == n*n){
        		print_sol();
			} else {				
				TRY(k+1);
				mark[xx][yy] = 0;
			}        			
		}
        
    }
}
int main(){
    cin >> n;
    mark[1][1] = 1;
    X[1] = Y[1] = 1;
    TRY(2);
   	
    return 0;
}
///*HoVaTen: EANG SOKUNTHEA
//  MSSV: 20180280*/
//#include <iostream>
//using namespace std;
//
//int n;
//int X[100], Y[100]; //# Luu t?a d? c�c bu?c di chuy?n c?a qu�n m�
//int mark[100][100];//# ��nh d?u v? tr� c�c � m� qu�n m� d� di chuy?n qua
//
////# M?ng hx, hy m� t? 8 v? tr� qu�n m� c� th? di chuy?n k? t? v? tr� hi?n t?i
//const int hx[] = {1, 1, 2, 2, -1, -1, -2, -2}; 
//const int hy[] = {2, -2, 1, -1, 2, -2, 1, -1};
//
////# In ra d�y c�c di chuy?n t�m du?c
//void print_sol(){
//    for (int j = 1; j <= n * n; ++j)
//        printf("(%d %d)\n",X[j],Y[j]);
//    exit(0);
//}
//
////# Thu?t to�n quay lui
//void TRY(int k){
//	mark[X[k-1]][Y[k-1]] = k;
//	k++;
//	for(int i=0; i<8; i++){
//		if(k == n * n + 2)
//		{
//			print_sol();	
//		}
//	int xx = X[k-1] + hx[i];
// 	int yy = Y[k-1] + hy[i];
//	if(xx > 0 && xx <= n && yy > 0 && yy <= n && mark[xx][yy] == 0){
//		X[k-1] = xx;
//		Y[k-1] = yy;
//		TRY(k);
//	}
//}
//	k--;
//	mark[X[k-1]][Y[k-1]] = 0;
//}
//
//main(){
//	printf("HoVaTen: EANG SOKUNTHEA\n");
//	printf("MSSV: 20180280\n");
//    cin >> n;
//    mark[1][1] = 1;
//    X[1] = Y[1] = 1;
//    TRY(2); 
//    return 0;
//}
/*
#include<iostream>
#include<stdio.h>
#define MAX 8
using namespace std;
 
int A[MAX][MAX] = { 0 };//Kh?i t?o m?ng gi� tr? 0
int X[8] = { -2,-2,-1,-1, 1, 1, 2, 2};
int Y[8] = { -1, 1,-2, 2,-2, 2,-1, 1};
int dem = 0;//S? bu?c di	
int n;
 
void xuat() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%2d ", A[i][j]);
        cout << endl;
    }
    cout << endl;
}
 
void diChuyen(int x, int y) {
    ++dem;//Tang gi� tr? bu?c di
    A[x][y] = dem;//��nh d?u d� di
    for (int i = 0; i < 8; i++)    {
        //Ki?m tra xem m� d� di h?t b�n c? chua
        if (dem == n * n) {
            cout << "Cac buoc di la: \n";
            xuat();
            exit(0);//k?t th�c chuong tr�nh
        }
        //N?u chua di h?t b�n c? th� t?o bu?c di m?i
        int u = x + X[i];//t?o m?t v? tr� x m?i
        int v = y + Y[i];//t?o m?t v?i tr� y m?i
        //N?u h?p l? th� ti?n h�nh di chuy?n
        if (u >= 0 && u < n&&v >= 0 && v < n&& A[u][v] == 0)
            diChuyen(u, v);
    }
    //N?u kh�ng t�m du?c bu?c di th� ta ph?i tr? l?i c�c gi� tr? ban d?u
    --dem;
    A[x][y] = 0;
}
int main() {
    cout << "Nhap n: ";
    cin >> n;
    int a, b;
    cout << "Nhap vi tri ban dau.\nx: ";
    cin>>a;
    cout << "y: ";
    cin >> b;
    diChuyen(a, b);
    //N?u kh�ng t�m du?c bu?c di th� s? th�ng b�o
    cout << "Khong tim thay duong di.";
}*/
/*
#include <iostream>
#include <iomanip>
#include <fstream>
#include <conio.h>

using namespace std;

#define MAX 60

struct nuocDi
 {
 char n; //S? � c� th? di ti?p
 char x, y; //V? tr�
 };

int danhDau[MAX + 1][MAX + 1];
int kichThuoc;

char dx[] = {-2, -2, -1, -1,  1,  1,  2,  2};
char dy[] = { 1, -1,  2, -2,  2, -2,  1, -1};

nuocDi tam;

int thoat = 0;

void xuat()
 {
 int i, j;
 for (i = 1;  i<= kichThuoc; i++)
 {
 for (j = 1; j <= kichThuoc; j++)
 cout << setw(3) << danhDau[i][j] << " ";
 cout<<endl;
 }
 thoat = 1;
 }

int tinhSoNuocDi(int x, int y)
 {
 int i, j, n = 0;
 for (int k = 0; k < 8 ; k++)
 {
 i = x + dx[k];
 j = y + dy[k];
 if (i>=1 && i <= kichThuoc && j >=1 && j <= kichThuoc && danhDau[i][j] == 0)
 n++;
 }
 return n;
 }

void diTuan(char x, char y, int buoc)
 {
 if (buoc == kichThuoc * kichThuoc)
 xuat();
 else
 {
 char i, j, soNuocDi = 0;
 nuocDi luaChon[8];

for (char k = 0; k < 8 ; k++)
 {
 i = x + dx[k];
 j = y + dy[k];
 if (i>=1 && i <= kichThuoc && j >= 1 && j <= kichThuoc && danhDau[i][j] == 0)
 {
 tam.n = tinhSoNuocDi(i, j);
 tam.x = i;
 tam.y = j;
 luaChon[soNuocDi++] = tam;
 }
 }

if (soNuocDi > 0)
 {
 //S?p x?p c�c nu?c di tang d?n theo s? � c� th? di ti?p
 for (char i = 0; i < soNuocDi - 1; i++)
 for (char j = i + 1; j < soNuocDi; j++)
 if (luaChon[i].n > luaChon[j].n)
 {
 tam = luaChon[i];
 luaChon[i] = luaChon[j];
 luaChon[j] = tam;
 };

for (char i = 0; i < soNuocDi && !thoat; i++)
 {
 danhDau[luaChon[i].x][luaChon[i].y] = buoc + 1;
 diTuan(luaChon[i].x, luaChon[i].y, buoc + 1);
 danhDau[luaChon[i].x][luaChon[i].y] = 0;
 }
 }
 }
 }

int main()
 {
 int x, y;
cout << "Nhap kich thuoc ban co: ";
cin >> kichThuoc;
cout << "Vi tri xuat phat:" << endl;
cout << "   dong = "; cin >> x;
cout << "   cot  = "; cin >> y;
//memset(danhDau[0], 0, sizeof(danhDau));
danhDau[x][y] = 1;
diTuan(x, y, 1);
getch();
return 0;
}*/
