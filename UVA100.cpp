#include<iostream>
#define swap(x, y, z) (z)=(x), (x)=(y), (y)=(z)
using namespace std;
int record[1000000] = { 0 };
void creatTable(void) {
	long long temp;
	int counter;
	for (int i = 1; i < 1000000; ++i) {
		temp = i;
		counter = 1;
		while (temp != 1) {
			if (temp < 1000000 && record[temp]) {
				counter += record[temp] - 1;
				break;
			}
			if (temp % 2) 
				temp = 3 * temp + 1;
			else
				temp /= 2;
			++counter;
		}
		record[i] = counter;
	}
}
int findMax(int a, int b) {
	int ans = 0;
	for (int i = a; i <= b; ++i) {
		if (ans < record[i])
			ans = record[i];
	}
	return ans;
}
int main() {
	int i, j, temp;
	creatTable();
	while (cin >> i >> j) {
		cout << i << ' ' << j << ' ';
		if (i > j) swap(i, j, temp);
		cout << findMax(i, j) << endl;
	}
}