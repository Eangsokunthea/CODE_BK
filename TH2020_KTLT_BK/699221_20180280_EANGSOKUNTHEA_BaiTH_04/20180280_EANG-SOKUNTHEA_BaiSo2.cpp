 #include <iostream>
 #include <cmath>
 #include <iomanip>
 #include <utility>
 using namespace std;
 using Point = pair<double, double>;

double area(Point a, Point b, Point c) {
    b.first = b.first - a.first;
    b.second = b.second - a.second;
    
    c.first = c.first - a.first;
    c.second = c.second - a.second;
    
    double temp;
    temp = abs(0.5*(b.first*c.second - c.first*b.second));
    return temp;
}

 int main() {
	printf("HoTen: EANG SOKUNTHEA\n");
	printf("MSSV: 20180280\n");
     cout << setprecision(2) << fixed;
     cout << area({1, 2}, {2.5, 10}, {15, -5.25}) << endl;
     return 0;
 }
