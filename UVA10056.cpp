#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main() {
	double p;
	int n, k;
	cin >> n;
	while (cin >> n >> p >> k) {
		if(p)
			p = (pow((1 - p), (k - 1))*p*(1 - (pow((1 - p), pow(n, 50))))) / (1 - pow((1 - p), n));
		printf("%.4lf\n", p);
	}
}