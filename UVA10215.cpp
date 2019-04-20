#include<iostream>
#include<cstdio>
#include<cmath>
#define eps 1e-8
using namespace std;
int main() {
	double w, l, x;
	while (cin >> w >> l) {
		x = (l + w - sqrt(w*w - w * l + l * l)) / 6.0;
		w = w < l ? w : l;
		printf("%.3lf 0.000 %.3lf\n", x + eps, w / 2.0 + eps);
	}
}