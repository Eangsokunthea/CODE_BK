/*Write the length of the longest subsequence found???
10
7 2 3 7 5 4 2 1 9 6
output: 4
*/
#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	cin >> n;
	vector<int> f(n+5,2e9);

	for (int i = 1,x; i <= n; ++i) {
        cin >> x;
        *lower_bound(f.begin(),f.end(),x) = x;
	}
    cout << lower_bound(f.begin(), f.end(), 2e9) - f.begin();
    return 0;
}


