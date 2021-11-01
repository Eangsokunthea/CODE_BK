#include<bits/stdc++.h>
using namespace std;
//#define MAX 1000005

int a[1000005], s[1000005];
int n , res;

int main() {
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	res = s[0] = a[0];
	for(int i = 1; i < n ; i++) {
		s[i] = s[i-1] < 0 ? a[i] : a[i] + s[i-1];
		res = max(res , s[i]);
	}
	cout << res;
	return 0;
}




















