#include <bits/stdc++.h>
using namespace std;

int main(){
	printf("HoVaTen: EANG SOKUNTHEA\n");
    printf("MSSV: 20180280\n");
    
	bool found = false;
    int n;
    cin >> n;
    while(n--){
        int a;
        cin >> a;
        if ((a % 4 == 0 && a % 100 != 0) || (a % 100 == 0))
            found = true;
    }
    if (found) cout << "Yes";
    else cout << "No";
}
