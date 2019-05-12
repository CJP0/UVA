#include<iostream>
#include<cstdio>
using namespace std;
int ink[36], record[35];
int sum(int base, int n) {
	static int ans;
	if (!n)
		return ink[0];
	ans = 0;
	while (n) {
		ans += ink[n % base];
		n /= base;
	}
	return ans;
}
int main() {
	int n, n2, temp, casen = 0, min;
	cin >> n;
	while (n--) {
		for (int i = 0; i < 36; ++i) {
			cin >> ink[i];
		}
		cout << "Case " << ++casen << ':' << endl;
		cin >> n2;
		while (n2--) {
			cin >> temp;
			cout << "Cheapest base(s) for number " << temp << ':';
			min = 2147483647;
			for (int i = 2; i < 37; ++i) {
				record[i - 2] = sum(i, temp);
				if (min > record[i - 2])
					min = record[i - 2];
			}
			for (int i = 0; i < 35; ++i) {
				if (record[i] == min)
					cout << ' ' << (i + 2);
			}
			cout << endl;
		}
		if(n)
			cout << endl;
	}
}