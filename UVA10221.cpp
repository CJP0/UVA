#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
using namespace std;
int main() {
	const double pi = acos(-1);
	string str;
	double s, a;
	while (cin >> s >> a >> str) {
		s += 6440;
		if (str == "min")
			a /= 60;
		if (a > 180)
			a = 360 - a;
		printf("%.6lf ", s * a * pi / 180);
		printf("%.6lf\n", 2 * sqrt(s * s - pow(s * cos(a / 360 * pi), 2)));
	}
}