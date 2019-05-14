#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int table[65];
int binarySearch(int arr[], int size, int target) {
	static int mid, R, L;
	R = size - 1;
	L = 0;
	while (L <= R) {
		mid = (L + R) / 2;
		if (arr[mid] == target)
			return mid;
		else if (arr[mid] > target)
			R = mid - 1;
		else if (arr[mid] < target)
			L = mid + 1;
	}
	return -1;
}
int main() {
	int n;
	double temp;
	bool f;
	for (int i = 0; i < 65; ++i) {
		table[i] = i * i * i;
	}
	while (cin >> n && n) {
		f = 1;
		for (int i = 1; i < 61; ++i) {
			temp = binarySearch(table, 65, i * i * i + n);
			if (temp > -1) {
				cout << temp << ' ' << i << endl;
				f = 0;
				break;
			}
		}
		if (f)
			cout << "No solution\n";
	}
}