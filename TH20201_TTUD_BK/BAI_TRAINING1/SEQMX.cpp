#include <iostream>
using namespace std;
#include <math.h>

int main(){
	int long long n;
	cin >> n;
	int long long a[n], s=0, m = 1000000007;
	for (int i = 0; i < n; ++i)
	{
	    cin >> a[i];
	}
2 
	for (int i=0; i< n; ++i){
		s += a[i];
	}

	cout << float(s % m)/(n-1);
}
