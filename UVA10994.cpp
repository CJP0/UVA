#include<iostream>
using namespace std;
long long sumf(int a) {
	long long sum = 0;
	while (a) {
		sum += (a % 10)*(a % 10 + 1) / 2;
		sum += 45LL * (a /= 10);
	}
	return sum;
}
int main() {
	int a, b;
	while (cin >> a >> b) {
		if (a < 0) break;
		cout << sumf(b) - sumf(a - 1) << endl;
	}
}