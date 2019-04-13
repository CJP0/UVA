#include<iostream>
#include<cstdlib>
#include<vector>
#define swap(x, y, z) ((z)=(x), (x)=(y), (y)=(z))
using namespace std;
void sort(vector <int> & arr) {
	int n = arr.size() - 1, temp;
	bool f;
	for (int i = 0; i < n; ++i) {
		f = 1;
		for (int j = 0; j < n - i; ++j) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1], temp);
				f = 0;
			}
		}
		if (f) return;
	}
}
int main() {
	int n, temp, med, counter;
	vector <int> arr;
	while (cin >> n) {
		for (int i = 0; i < n; ++i) {
			cin >> temp;
			arr.push_back(temp);
		}
		sort(arr);
		med = arr[(n - 1) >> 1];
		temp = arr[n >> 1];
		counter = 0;
		for (int i = 0; i < n; ++i) {
			counter += (arr[i] == med || arr[i] == temp);
		}
		cout << med << ' ' << counter << ' ' << temp - med + 1 << endl;
		arr.clear();
	}
}