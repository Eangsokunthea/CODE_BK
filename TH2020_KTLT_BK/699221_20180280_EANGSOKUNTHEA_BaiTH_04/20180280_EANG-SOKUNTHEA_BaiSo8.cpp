#include <iostream>
#include <map>

using namespace std;

template<class T>
map<T, double> fuzzy_set_union(const map<T, double> &a, const map<T, double> &b) {
	
	map<T, double> c = a;
   	for (auto it : b) {
       auto it2 = c.find(it.first);
       if (it2 == c.end()) {
           c[it.first] = it.second;
       }
       else {
           it2->second = max(it2->second, it.second);
       }
   }
   return c;
}

template<class T>
map<T, double> fuzzy_set_intersection(const map<T, double> &a, const map<T, double> &b) {
	map<T, double> c;
   	for (auto it : a) {
       double v = it.second;
       auto it2 = b.find(it.first);
       if (it2 != b.end()) {
           v = min(v, it2->second);
           c[it.first] = v;
       }
   }
   return c;
}

 template<class T>
 void print_fuzzy_set(const std::map<T, double> &a) {
     cout << "{ ";
     for (const auto &x : a) {
         std::cout << "(" << x.first << ", " << x.second << ") ";
     }
     cout << "}";
     std::cout << std::endl;
 }

 int main() {
 	 printf("HoTen: EANG SOKUNTHEA\n");
	 printf("MSSV: 20180280\n");
     std::map<int, double> a = {{1, 0.2}, {2, 0.5}, {3, 1}, {4, 0.6}, {5, 0.7}};
     std::map<int, double> b = {{1, 0.5}, {2, 0.4}, {4, 0.9}, {5, 0.4}, {6, 1}};
     std::cout << "A = "; print_fuzzy_set(a);
     std::cout << "B = "; print_fuzzy_set(b);
     std::map<int, double> c = fuzzy_set_union(a, b);
     std::map<int, double> d = fuzzy_set_intersection(a, b);
     std::cout << "Union: "; print_fuzzy_set(c);
     std::cout << "Intersection: "; print_fuzzy_set(d);
 }
