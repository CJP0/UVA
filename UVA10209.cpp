#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main() {
	const double PI = acos(-1);
	double a, x, y, z;
	while (cin >> a) {
		z = a * a * (1.0 - PI / 6.0 - 0.25 * sqrt(3.0));
		y = a * a - 0.25 * PI * a * a - 2.0 * z;
		x = a * a - 4 * y - 4 * z;
		printf("%.3lf %.3lf %.3lf\n", x, 4.0 * y, 4.0 * z);
	}
}