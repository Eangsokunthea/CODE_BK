#include <iostream>
using namespace std;

int n, M, m[100], v[100];
int x[100], best, sumV, sumM, all[100];//Doi, ALL[100] --> all[100]; 

void init(){
    for (int i = n; i >= 1; --i){
        all[i] = all[i+1] + v[i];
    }
}


void print() {
    cout << best;
}

int process(int i){//,,doi void  --> int 
    if (sumV + all[i] <= best || sumM > M) return 0; 
    if (i > n){
        best = sumV;//error, do khong co dau (;)
        return 0;
        
    }
    process(i+1);
    sumM += m[i];
    sumV += v[i];
    process(i+1);
    sumM -= m[i];
    sumV -= v[i];

}

int main() {
	printf("HoVaTen: EANG SOKUNTHEA\n");
	printf("MSSV: 20180280\n");
    cin >> n >> M;
    for (int i = 1; i <= n; ++i)
        cin >> m[i] >> v[i];
    init();
    process(1);
    print();
    return 0;
}

