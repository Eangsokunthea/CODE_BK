/*ok --> DevC++ have problem some code,,,
		Result:
		3 3
		1 3 721
		2 3 5 11
		3 1 985
*/
#include<iostream>
#include<map>
#include<time.h>
using namespace std;

int main() {
	printf("HoVaTen: EANG SOKUNTHEA\n");
    printf("MSSV: 20180280\n");
	
	srand((int)time(0));
    
	const int MAXXX = 1000;
	int m, n;
	n = rand() % 10 + 1;

	m = rand() % (n*(n-1));

	map <pair<int, int>, int> E;

	int u, v, w;

	while (E.size() < m)
	{
		u = (rand() % n)+1;
		v = (rand() % n)+1;
		if (u == v) continue;
		w = rand() % MAXXX;
		E[make_pair(u, v)] = w;
	}

	cout << n << " " << m << endl;

	for (auto it : E)
	{
		cout << it.first.first << " " << it.first.second << " " << it.second << endl;
	}

	return 0;
}
