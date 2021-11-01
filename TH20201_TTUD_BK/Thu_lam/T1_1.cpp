#include<bits/stdc++.h>

using namespace std;

int a = 1000005,b = 1000005;

void input() {
	cin >> a >> b;
}

int sum(int a, int b) {
	return a + b;	
}

int main() {
	input();
	cout << sum(a,b);
}
