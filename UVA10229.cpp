#include<iostream>
#include<cmath>
using namespace std;
void cpyMatrix(long long a[][2], long long b[][2]) {
	static int i, j;
	for (i = 0; i < 2; ++i) {
		for (j = 0; j < 2; ++j) {
			a[i][j] = b[i][j];
		}
	}
}
void mulMatrix(long long a[][2], long long b[][2], int c) {
	static int i, j, z;
	long long temp[2][2] = { 0, 0, 0, 0 };
	for (i = 0; i < 2; ++i) {
		for (j = 0; j < 2; ++j) {
			for (z = 0; z < 2; ++z) {
				temp[j][i] += a[j][z] * b[i][z];
				temp[j][i] &= (1 << c) - 1;//mod
			}
		}
	}
	cpyMatrix(a, temp);
}
long long fibon(int n, int m) {
	long long a[2][2] = { 1,0,0,1 }, b[2][2] = { 1,1,1,0 };
	while (n) {
		if (n & 1)
			mulMatrix(a, b, m);
		mulMatrix(b, b, m);
		n /= 2;
	}
	return a[1][0];
}
int main() {
	int n, m;
	while (cin >> n >> m) {
		cout << fibon(n, m) << endl;
	}
}