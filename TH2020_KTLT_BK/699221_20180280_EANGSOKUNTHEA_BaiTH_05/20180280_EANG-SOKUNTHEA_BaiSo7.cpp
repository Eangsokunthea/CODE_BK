#include <iostream>
#include<algorithm>
using namespace std;

int main() {
	printf("HoVaTen: EANG SOKUNTHEA\n");
    printf("MSSV: 20180280\n");
    int n;
    cin >> n;
    int ans = 0, sum = 0;
    while (n--) {
        int k, t;
        cin >> k >> t;
        while (k--) {
            int a;
            cin >> a;
            sum += t * a;
            ans = max(ans, -sum);
        }
    }
    cout << ans;
}
