// No Ok

#include<bits/stdc++.h>
using namespace std;

int long long a[1000000007];
int long long s = 0, m = 1000000007; 
int long long n;

int main() {
	cin >> n;
	for(int i =0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < n; i++) {
		s += a[i];
	}
	
	cout << s;	
	return 0;
}
