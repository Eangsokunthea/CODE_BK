#include <iostream>
#include <stdio.h>
using namespace std;
struct node {
	int L;
	int R;
} ceil[100+10];
int main() {
	int n;
	while(cin >> n) {
		bool is = true;
		int first = 0;
		for(int i = 1; i <= n; i++) {
			cin >> ceil[i].L >> ceil[i].R;
			if(ceil[i].L == 0 && is) {
				is = false;
				first = i;
			}
		}
		//solve()
		int k = first;
		bool isfind;
		while(ceil[k].R != first) {
			isfind = false;
			if(ceil[k].R != 0) {
				k = ceil[k].R;
				continue;
			} else {
				for(int i = 1; i <= n; i++) { //find l
					if(i == first) continue;
					if(ceil[i].L == 0) {
						ceil[i].L = k;
						ceil[k].R = i;
						k = i;
						isfind = true;
						break;
					}
				}
			}
			if(!isfind) {
				break;
			}
		}
		//print()
		for(int i = 1; i <= n; i++) {
			cout << ceil[i].L <<" " << ceil[i].R << endl;
		}
		//over
	}
}
