#include<bits/stdc++.h>
#include<math.h>
using namespace std;



int main() {
	cout << "HoTen: EANG SOKUNTHEA\n" ;
	cout << "MSSV: 20180280\n";
	
	double sum = 0;
	double HeSDT[2][15];
	double BacDT[2];
	double GTX[2];
	char TDT[2];
	int num = 1;	
	
	while(num) { 
	cout << "\n\n\t********************************************\n" << endl;
	cout << "\t **      1. Nhap cac da thuc         	**\n" << endl;
	cout << "\t **      2. In danh sach da thuc     	**\n" << endl;
	cout << "\t **      0. Thoat                  	**\n" << endl;
	cout << "\t********************************************\n" << endl;
	cout << "\t **     Nhap lua chon cua ban       **\n" << endl;
	
	start:
		
	cin >> num;
	
	switch(num) {
		
		case 1:
		 	cout << "\nNhap da thuc thu 1: \n";
			cout << "Nhap Ten da thuc: " ;
			cin >> TDT[0];
				
			cout << "Nhap Bac : " ;
			cin >> BacDT[0];
			
			cout << "Nhap X : " ;
			cin >> GTX[0];
		
		    for (int i=0; i<BacDT[0]; i++) {
		        
		        cout << "\nHe so bac " << i+1 << ":";
		        cin >> HeSDT[0][i];
		        
		    }
		    
		    cout << "\nNhap da thuc thu 2: \n";
			cout << "Nhap Ten da thuc: " ;
			cin >> TDT[1];
		    
		    cout << "Nhap Bac : " ;
			cin >> BacDT[1];
			
			cout << "Nhap X : " ;
			cin >> GTX[1];
		
		    for (int i=0; i<BacDT[1]; i++) {
		        
		        cout << "\nHe so bac " << i+1 << ":";
		        cin >>  HeSDT[1][i] ;
		        
		    }
		    cout << endl;
			
			break;
			
		case 2:
			cout << "\n\tBan da chon xuat Ds da thuc, Gia tri da thuc!\n" << endl;
			cout << "\t_____________________________________________\n" << endl; 
			cout << "Da Thuc: " << TDT[0] << "(x) = ";
			for(int i = 0; i < BacDT[0]; i++) {
				sum = sum + HeSDT[0][i] * pow(GTX[0],i+1);
				cout << HeSDT[0][i] << "x^" << i+1; 
				if(HeSDT[0][i] > 0)
					cout << " + ";
			}
			cout << "\nGia Tri Da Thuc: " << TDT[0] << "(" << GTX[0] << ")"  << " = " << sum << endl;
			
			
			cout << "\nDa Thuc: " << TDT[1] << "(x) = ";
			for(int i = 0; i < BacDT[0]; i++) {
				sum = sum + HeSDT[1][i] * pow(GTX[1], i+1);
				cout << HeSDT[1][i] << "x^" << i+1;
				if(HeSDT[1][i] > 0 && i < BacDT[1] - 1)
					cout << " + ";
			}
			cout << "\nGia Tri Da Thuc: " << TDT[1] << "(" << GTX[1] << ")" << " = "<< sum << endl;
			cout << endl;
			cout << "\n\n\tBam phim bat ky de tiep tuc!\n";
			goto start;
		case 0:
			exit(1);
		default:
			break;
			
		}	
	
	}
	
	return 0;	
	
}
