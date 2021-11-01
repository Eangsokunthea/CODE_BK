/*
	HoTen: EANG SOKUNTHEA
	MSSV: 20180280
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print_vector(const vector<int> &a) {
    for (int v : a) cout << v << ' ';
    cout << endl;
}

void delete_even(vector<int> &a) {
    for (auto i = a.begin(); i != a.end(); ++i) {
        if (*i % 2 == 0) {
            a.erase(i);
            i--;
        }
    }

}

void sort_decrease(vector<int> &a) {
    sort(a.begin(), a.end(), greater<int>()); 
}

vector<int> merge_vectors(const vector<int> &a, const vector<int> &b) {
  // c is the output vector
	// it will store the merged vector obtained by merging a and b
	vector<int> c;

	int i, j, n, m;
	i = j = 0;
	n = a.size();
	m = b.size();

	// traverse each elemenst of a and b
	while (i < n && j < m) {

		// comparing a[i] and b[j]
		// if a[i] is smaller than b[j]
		// push a[i] to c and increment i
		// if a[i] is less than b[j]
		// push b[j] to c and increment j
		if (a[i] <= b[j]) {
			c.push_back(a[i]);
			++i;
		}
		else {
			c.push_back(b[j]);
			++j;
		}

	}

	// push the elements left in a to c
	while (i < n) {
		c.push_back(a[i]);
		++i;
	}

	// push the elements left in b to c
	while (j < m) {
		c.push_back(b[j]);
		++j;
	}
	sort(c.begin(), c.end(), greater<int>());
	return c;

	
}

int main() {
	printf("HoTen: EANG SOKUNTHEA\n");
	printf("MSSV: 20180280\n");
    int m, n, u;
    std::vector<int> a, b;
    
    std::cin >> m >> n;
    for(int i = 0; i < m; i++){
        std:: cin >> u;
        a.push_back(u);
    }
    for(int i = 0; i < n; i++){
        std:: cin >> u;
        b.push_back(u);
    }

    delete_even(a);
    cout << "Odd elements of a: ";
    print_vector(a);

    delete_even(b);
    cout << "Odd elements of b: ";
    print_vector(b);

    sort_decrease(a);
    cout << "Decreasingly sorted a: ";
    print_vector(a);

    sort_decrease(b);
    cout << "Decreasingly sorted b: ";
    print_vector(b);

    vector<int> c = merge_vectors(a, b);
    cout << "Decreasingly sorted c: ";
	print_vector(c);
	
    
    	
    return 0;
}
