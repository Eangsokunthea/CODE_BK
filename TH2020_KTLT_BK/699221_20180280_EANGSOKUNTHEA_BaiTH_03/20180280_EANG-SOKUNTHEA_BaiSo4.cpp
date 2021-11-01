/*HoTen: EANG SOKUNTHEA
  MSSV: 20180280*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int a[1000], n;
int mem[1000]; //# m?ng ghi nh? l?i gi?i c�c b�i to�n con d� du?c gi?i

void init(){
    memset(mem, -1, sizeof(mem));
}

//# Quy hoach dong, 
//# H�m lis(i) tra ve do dai day con tang dai nhat ket thuc boi a[i]
int lis(int i) {
    if(i == 1) {    	
    	if(a[1] > a[0]){
    		mem[0] = 1;	  		
    		mem[1] = 2;
    		return 2;
		}
		mem[0] = 1;
		mem[1] = 1;
    	return 1;	
	} else {
		for(int j = i-1; j >= 0; j--){
			if(mem[j] != -1){
				if(a[j] < a[i]){
					mem[i] = mem[j] + 1;
					return mem[i];
				} return mem[j];
			}
		}		
	}
    return 1;
}

//# Truy vet loi giai
void trace(int i){
    for(int j = 0; j < i; j++){
        if (a[j] < a[i] && mem[i] == 1 + mem[j]){
            trace(j);
            break;
        }
    }
    cout << a[i] << " ";
}
int main(){
	printf("HoVaTen: EANG SOKUNTHEA\n");
	printf("MSSV: 20180280\n");
    init();
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int res = 1, pos = 0;
    for(int i = 1; i < n; i++){
        if (res < lis(i)){
            res = lis(i);
            pos = i;
        }
    }
    cout << res << endl;
    trace(pos);
    return 0;
}
