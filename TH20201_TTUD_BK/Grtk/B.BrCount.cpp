/*
Ghi s? c?ch kh?c nhau kh?i ph?c d?y ngo?c d?ng, ch? c?n in ra s? du c?a
s? c?ch khi chia cho 1000000007
10
4 4 1 6 3 2 1 2 5 7
--> 1 3

(??(??))
--> 5
*/
#include<bits/stdc++.h>
using namespace std;
long long f[1005][1005], mod = 1e9 + 7;
string s;
int solve() {
	cin >> s;
	int n = s.length();
	s = ' ' + s;
	f[0][0] = 1;
	for(int i = 1; i <= n; i ++)
		for(int j = 0; j <= n; j ++) {
			if(s[i] == '(' && j) f[i][j] = (f[i][j] + f[i - 1][j - 1]) % mod;
			else if(s[i] == ')') f[i][j] = (f[i][j] + f[i - 1][j + 1]) % mod;
			else if(s[i] == '?') {
				f[i][j] = (f[i][j] + f[i - 1][j + 1]) % mod;
				if(j) f[i][j] = (f[i][j] + f[i - 1][j - 1]) % mod;
			}
		}
	cout << f[n][0];
}
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
