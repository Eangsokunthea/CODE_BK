#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

typedef std::pair<int, int> pair;

bool sortByVal(const pair &a, const pair &b) { 
	if (a.second != b.second){
		return a.second > b.second;
	}
	return a.first > b.first;
} 

int main() {
	printf("HOTEN : EANG SOKUNTHEA\n");
	printf("MSSV : 20180280\n");
	int a, b;
	std::map<int, int> map;
	while ( std::cin >> a >> b) map.insert(std::pair<int, int>(a,b));
	std::vector<pair> vec;
	std::copy(map.begin(), map.end(), std::back_inserter<std::vector<pair>>(vec));
	std::sort(vec.begin(), vec.end(), sortByVal);
	for (auto const &pair: vec) {
		std::cout << pair.first << " "<< pair.second << std::endl;
	}
	
}


